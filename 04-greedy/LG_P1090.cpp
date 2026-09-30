/*
 * 洛谷 P1090 [NOIP2004 提高组] 合并果子
 * 考点：贪心 + 优先队列（小根堆），即哈夫曼树的合并代价模型
 * 题意：n 堆果子，每次任选两堆合并，代价为两堆之和，求全部合并的最小总代价。
 * 思路：每次都合并当前最小的两堆（代价最小的合并尽早做，且被计入后续每次
 *       合并的次数最少）。用小根堆维护，每次取堆顶两个合并后放回。
 * 复杂度：时间 O(n log n)，空间 O(n)
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);    // 关闭同步加速 cin/cout
    cin.tie(nullptr);
    priority_queue<int, vector<int>, greater<int>> pq;  // 小根堆
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        pq.push(x);
    }
    long long sum = 0;              // 修改说明：n 与 a_i 上限下总代价可能超 int，
                                    // P1090 数据范围内 int 可过，long long 更稳妥
    while(pq.size() > 1){           // 堆中只剩一堆时结束
        int a = pq.top(); pq.pop();   // 最小的
        int b = pq.top(); pq.pop();   // 次小的
        int c = a + b;
        sum += c;                   // 本次合并代价
        pq.push(c);                 // 合并后放回堆
    }
    cout << sum << "\n";
    return 0;
}
