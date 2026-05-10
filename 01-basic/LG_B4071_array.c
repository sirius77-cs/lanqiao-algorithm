#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1005
#define MAXM 1005

long long min(long long a, long long b) {
    return a < b ? a : b;
}

// 升序比较函数
int cmp(const void* a, const void* b) {
    long long va = *(long long*)a;
    long long vb = *(long long*)b;
    if (va < vb) return -1;
    if (va > vb) return 1;
    return 0;
}

long long costs[MAXN][MAXM];   // 分组存储非武器1的花费
long long prefix[MAXN][MAXM];  // 前缀和

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int p[MAXM];
    long long c[MAXM];
    int count[MAXN] = {0};  // 每种武器的初始材料数量
    int len[MAXN] = {0};    // 每种武器的材料数量（非武器1）
    
    // 特判 n=1
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    
    // 读入数据
    for (int i = 1; i <= m; i++) {
        scanf("%d %lld", &p[i], &c[i]);
        count[p[i]]++;
        if (p[i] != 1) {
            costs[p[i]][len[p[i]]++] = c[i];
        }
    }
    
    // 对每种武器的花费升序排序并计算前缀和
    for (int i = 2; i <= n; i++) {
        qsort(costs[i], len[i], sizeof(long long), cmp);
        prefix[i][0] = 0;
        for (int j = 1; j <= len[i]; j++) {
            prefix[i][j] = prefix[i][j-1] + costs[i][j-1];
        }
    }
    
    // ===== 关键修正 =====
    // 存储全局未被选用的材料（用于最终补充武器1）
    long long all_costs[MAXM];
    int all_len = 0;
    for (int i = 1; i <= m; i++) {
        if (p[i] != 1) {
            all_costs[all_len++] = c[i];
        }
    }
    qsort(all_costs, all_len, sizeof(long long), cmp);
    long long all_prefix[MAXM] = {0};
    for (int i = 1; i <= all_len; i++) {
        all_prefix[i] = all_prefix[i-1] + all_costs[i-1];
    }
    
    long long ans = 1e18;
    int s = count[1];  // 武器1初始材料数
    
    // 枚举武器1的最终材料数量 k（从初始数量到总材料数）
    for (int k = s; k <= m; k++) {
        int need = 0;           // 需要从其他武器删除的材料总数
        long long sum_req = 0;  // 删除这些材料的总花费
        int valid = 1;
        
        // ===== 关键修正：先保存每个武器删除的数量 =====
        int req_count[MAXN] = {0};  // 记录每个武器需要删除的数量
        
        for (int i = 2; i <= n; i++) {
            // 每个武器 i 最终不能超过 k-1（严格小于武器1）
            int req = count[i] - (k - 1);
            if (req < 0) req = 0;
            if (req > len[i]) {
                valid = 0;
                break;
            }
            req_count[i] = req;     // 保存需要删除的数量
            need += req;
            sum_req += prefix[i][req];
        }
        
        if (!valid) continue;
        
        // 武器1需要增加的数量 = k - s
        // 如果 need > k-s，说明删除的材料比增加的多，需要额外处理
        if (need > k - s) continue;
        
        // ===== 关键修正：计算额外需要的材料（从剩余材料中选最便宜的）=====
        int extra = (k - s) - need;
        long long total = sum_req;
        
        if (extra > 0) {
            // 不能从已经删除的材料中选择，需要从未被删除的材料中选
            // 但这里是简化版本：从全局所有非1材料中选最便宜的（可能会重复计数）
            // 正确做法：收集实际剩余的材料
            
            // ===== 更精确的方法：收集剩余材料池 =====
            long long remaining[MAXM];
            int rem_cnt = 0;
            
            // 把每个武器删除 req_count[i] 个材料后，剩余的材料加入池子
            for (int i = 2; i <= n; i++) {
                for (int j = req_count[i]; j < len[i]; j++) {
                    remaining[rem_cnt++] = costs[i][j];
                }
            }
            
            // 如果剩余材料不够，则无效
            if (extra > rem_cnt) continue;
            
            // 对剩余材料排序
            qsort(remaining, rem_cnt, sizeof(long long), cmp);
            
            // 取最便宜的 extra 个
            for (int j = 0; j < extra; j++) {
                total += remaining[j];
            }
        }
        
        ans = min(ans, total);
    }
    
    printf("%lld", ans);
    return 0;
}