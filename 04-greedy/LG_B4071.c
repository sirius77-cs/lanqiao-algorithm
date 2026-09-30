/*
 * 洛谷 B4071 [GESP202412 五级] 武器强化
 * 考点：枚举 + 贪心 + 排序/前缀和（原在 01-basic 且文件名带误导性后缀 _array，
 *       实际是贪心题，已归入 04-greedy 并更名为 LG_B4071.c）
 * 题意：n 种武器、m 种强化材料，材料 i 适配武器 p_i，花 c_i 金币可把它改成适配
 *       任意武器。要求适配武器 1 的材料数严格大于其他每种武器，求最小总花费。
 * 思路：枚举武器 1 的最终材料数 k（从初始数 s 到 m）：
 *   - 其他每种武器 i 最终最多 k-1 个，超出的 req_i 个必须改走，
 *     显然每种都删最便宜的（排序 + 前缀和 O(1) 求和）；
 *   - 武器 1 还差 (k-s)-need 个材料时，从各武器删除后剩下的材料池里
 *     挑最便宜的补上（每次收集剩余池再排序）；
 *   - 若 need > k-s（要改走的比要补进的多），该 k 被更大的 k 支配，直接跳过
 *     （把多余材料直接给武器 1 即对应更大的 k，花费不会更多）。
 * 复杂度：O(m^2 log m) 级别（m<=1000，可通过）
 *
 * 【本次修订】原文件中 all_costs / all_prefix 一段（约 14 行）计算后从未被使用，
 * 属于调试遗留的死代码，已注释保留，逻辑未受影响。
 */
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

long long costs[MAXN][MAXM];   // costs[i][]：适配武器 i（非 1）的各材料花费
long long prefix[MAXN][MAXM];  // prefix[i][j]：排序后前 j 个便宜材料的和

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int p[MAXM];
    long long c[MAXM];
    int count[MAXN] = {0};  // 每种武器的初始材料数量
    int len[MAXN] = {0};    // 每种武器的材料数量（非武器1）

    // 特判 n=1：没有其他武器可比，无需花费
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

    // 对每种武器的花费升序排序并计算前缀和（删便宜的最优）
    for (int i = 2; i <= n; i++) {
        qsort(costs[i], len[i], sizeof(long long), cmp);
        prefix[i][0] = 0;
        for (int j = 1; j <= len[i]; j++) {
            prefix[i][j] = prefix[i][j-1] + costs[i][j-1];
        }
    }

    // ===== 以下一段为死代码（计算结果从未被使用），已注释保留 =====
    // // 存储全局未被选用的材料（用于最终补充武器1）
    // long long all_costs[MAXM];
    // int all_len = 0;
    // for (int i = 1; i <= m; i++) {
    //     if (p[i] != 1) {
    //         all_costs[all_len++] = c[i];
    //     }
    // }
    // qsort(all_costs, all_len, sizeof(long long), cmp);
    // long long all_prefix[MAXM] = {0};
    // for (int i = 1; i <= all_len; i++) {
    //     all_prefix[i] = all_prefix[i-1] + all_costs[i-1];
    // }

    long long ans = 1e18;
    int s = count[1];  // 武器1初始材料数

    // 枚举武器1的最终材料数量 k（从初始数量到总材料数）
    for (int k = s; k <= m; k++) {
        int need = 0;           // 需要从其他武器删除的材料总数
        long long sum_req = 0;  // 删除这些材料的总花费
        int valid = 1;

        int req_count[MAXN] = {0};  // 记录每个武器需要删除的数量

        for (int i = 2; i <= n; i++) {
            // 每个武器 i 最终不能超过 k-1（严格小于武器1）
            int req = count[i] - (k - 1);
            if (req < 0) req = 0;
            if (req > len[i]) {     // 该武器没有足够材料可删，k 不可行
                valid = 0;
                break;
            }
            req_count[i] = req;     // 保存需要删除的数量
            need += req;
            sum_req += prefix[i][req];  // 前缀和 O(1) 取最便宜 req 个的和
        }

        if (!valid) continue;

        // 要改走的比要补进的多：该 k 被更大的 k 支配，跳过（见文件头思路说明）
        if (need > k - s) continue;

        // 武器 1 还缺的材料数 = (k-s) - need，从剩余材料池补最便宜的
        int extra = (k - s) - need;
        long long total = sum_req;

        if (extra > 0) {
            // 收集实际剩余的材料池（每个武器删掉 req_count[i] 个之后剩下的）
            long long remaining[MAXM];
            int rem_cnt = 0;

            for (int i = 2; i <= n; i++) {
                for (int j = req_count[i]; j < len[i]; j++) {
                    remaining[rem_cnt++] = costs[i][j];
                }
            }

            // 剩余材料不够补，k 不可行
            if (extra > rem_cnt) continue;

            // 对剩余材料排序，取最便宜的 extra 个
            qsort(remaining, rem_cnt, sizeof(long long), cmp);
            for (int j = 0; j < extra; j++) {
                total += remaining[j];
            }
        }

        ans = min(ans, total);
    }

    printf("%lld", ans);
    return 0;
}
