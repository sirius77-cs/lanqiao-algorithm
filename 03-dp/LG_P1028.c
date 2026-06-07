//记忆化搜索，从指数级降到n方
#include<stdio.h>
int dp[1001];//减少时间复杂度
int solve (int n){
    if(dp[n] != -1) return dp[n];
    if(n==0)return dp[0] = 0;
    if(n==1)return dp[1] = 1;
    int sum=0;
    for(int i=1;i<=n/2;i++){
        sum+=solve(i);//递归调用
    }
    return dp[n]=sum+1;
}
int main(){
    int n,i;
    scanf ("%d",&n);
    for (i = 0; i <= n; i++) dp[i] = -1;
    int ans=solve(n);
    printf("%d",ans);
    return 0;
}
//更优方法：前缀和（AI提示）
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