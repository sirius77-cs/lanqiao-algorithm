/*
 * 洛谷 P1031 均分纸牌
 * 考点：贪心
 * 题意：n 堆纸牌（题目保证总和能被 n 整除），每次可在相邻两堆间移动任意张牌，
 *       求使所有堆牌数相等的最少移动次数。
 * 思路：设 avg 为目标值。从左到右扫，前缀差 prefix = Σ(a[i]-avg)：
 *       只要当前前缀差不为 0，就必须向右（或向左）移动一次把它清零，
 *       因此统计前缀差不为 0 的位置个数即为答案。
 * 复杂度：时间 O(n)，空间 O(n)
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {  // 读入失败或非法直接退出
        return 0;
    }

    int *a = (int *)malloc(n * sizeof(int));
    if (a == NULL) {
        return 0;
    }

    long long sum = 0;              // 总和用 long long 防溢出
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    int avg = (int)(sum / n);       // 目标牌数（题目保证整除）
    int prefix = 0;                 // 前缀差：前 i 堆相对目标的净盈亏
    int count = 0;                  // 最少移动次数

    for (int i = 0; i < n; i++) {
        if (prefix != 0) {          // 前缀差不为 0：必须移动一次把它传下去
            count++;
        }
        prefix += a[i] - avg;       // 累加当前堆的差值
    }

    printf("%d", count);
    free(a);
    return 0;
}
//下面为初版，上部分为copilot优化后的（初版思路相同，多开了 d/s 两个数组）
// #include<stdio.h>
// #include<stdlib.h>
// int Average(int *a , int len){
//     int i,sum=0;
//     for(i=0;i<len;i++){
//         sum+=a[i];
//     }
//     return sum/len;
// }
// int main(){
//     int n;
//     int count=0;
//     scanf("%d",&n);
//     int * a=(int*)malloc( n * sizeof(int));
//     for(int i=0;i<n;i++){
//         scanf("%d",&a[i]);
//     }
//     int avg=Average(a,n);
//     int * d=(int*)malloc( n * sizeof(int));
//     int * s=(int*)malloc( n * sizeof(int));
//     for(int i=0;i<n;i++){
//         d[i] = a[i] - avg;
//         for(int j=0;j<i;j++){
//             s[i]+=d[j];
//         }
//         if(s[i]!=0)s[i]=1;
//         else s[i]=0;
//     }
//     for(int i=0;i<n;i++){
//         count+=s[i];
//     }
//     printf("%d",count);
//     free(a);
//     free(d);
//     free(s);
//     return 0;
// }
