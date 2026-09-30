/*
 * 洛谷 P1028 数的计算
 * 考点：动态规划 · 记忆化搜索
 * 题意：只含 n 的合法序列定义：一个数本身算一种；其左边不能有比它大的数，
 *       且每个数可以放一个不超过自身一半的数。求合法序列总数（f(n)）。
 * 递推：f(n) = 1 + f(1) + f(2) + ... + f(n/2)（自身 + 以各 i 为左邻的方案）
 * 思路：自顶向下递归 + dp 数组缓存已算过的 f 值，把指数级搜索降到 O(n^2)。
 * 复杂度：时间 O(n^2)，空间 O(n)
 *
 * 【注】文件末尾附有一段前缀和 O(n) 优化的草稿（原代码自带，已注释）：
 *       思路方向正确（f 前缀和加速求和），但该草稿只填到 n/2 且未处理 f[n]，
 *       不完整，仅作参考，不能直接使用。
 */
//记忆化搜索，从指数级降到n方
#include<stdio.h>
int dp[1001];//减少时间复杂度
int solve (int n){
    if(dp[n] != -1) return dp[n];   // 已算过直接返回（记忆化）
    if(n==0)return dp[0] = 0;       // 边界：f(0)=0
    if(n==1)return dp[1] = 1;       // 边界：f(1)=1
    int sum=0;
    for(int i=1;i<=n/2;i++){
        sum+=solve(i);//递归调用   // f(n) = 1 + Σ f(i), i=1..n/2
    }
    return dp[n]=sum+1;
}
int main(){
    int n,i;
    scanf ("%d",&n);
    for (i = 0; i <= n; i++) dp[i] = -1;  // -1 表示未计算
    int ans=solve(n);
    printf("%d",ans);
    return 0;
}
//更优方法：前缀和（AI提示）—— 草稿不完整，见文件头说明，仅作参考
// int prefix[1001];
// int f[1001];
// int solve (int n){//需要直接放在主函数里，否则stack会出现问题
//     f[0] = 0;
//     f[1] = 1;
//     prefix[1] = f[1];
//     int sum = 0;
//     for(int i = 2; i <= n/2;i++){
//         sum = prefix[i/2];
//         f[i] = sum+1;
//         prefix[i] = prefix[i-1] + f[i];
//     }
//     return f[n];
// }
