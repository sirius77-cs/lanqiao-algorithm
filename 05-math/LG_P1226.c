/*
 * 洛谷 P1226 【模板】快速幂
 * 考点：数学 · 快速幂（原在 01-basic，已按考点归入 05-math）
 * 思路：把指数 b 按二进制拆分，b 的每一位对应不断自平方的底数 a，
 *       该位为 1 时把当前底数乘进答案，全程取模防止溢出。
 * 复杂度：时间 O(log b)，空间 O(1)
 */
#include<stdio.h>
long long Pow(long long a,long long b,long long p){
    long long res=1;            // 答案初值 1（乘法单位元）
    while(b>0){
        if(b%2==1){res=(res*a)%p;}  // b 当前末位为 1：把 a^(2^i) 乘入答案
        a=(a*a)%p;                  // 底数自平方：a^(2^i) -> a^(2^(i+1))
        b/=2;                       // 右移一位处理下一个二进制位
    }
    return res;
}
int main(){
    long long a,b,p;
    scanf("%lld %lld %lld",&a,&b,&p);
    long long res=Pow(a,b,p);
    printf("%lld^%lld mod %lld=%lld",a,b,p,res);  // 按题目要求的原样输出格式
    return 0;
}
