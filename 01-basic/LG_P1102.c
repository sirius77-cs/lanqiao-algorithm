/*
 * 洛谷 P1102 A-B 数对
 * 考点：排序 + 双指针（原在 02-search，实际不涉及 DFS/BFS，已归入 01-basic）
 * 题意：统计数列中满足 A-B=C 的数对个数（不同位置算不同数对），C>=1，0<=a_i<2^30
 * 思路：先升序排序，再用双指针 ptr1(较小数 B)、ptr2(较大数 A) 同向扫描：
 *       diff < C 时 ptr2 右移增大差值；diff > C 时 ptr1 右移减小差值；
 *       diff == C 时两段重复数字分别计数，贡献 cnt1*cnt2。
 * 复杂度：时间 O(n log n)（排序主导），空间 O(n)
 * 注意：a_i < 2^30 且非负，故 int 存差值不会溢出；
 *       答案最多约 n^2/4 ≈ 10^10，必须用 long long（代码中已正确转换）。
 */
#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;    // 升序比较器
}
int main(){
    int N,C;
    scanf("%d %d",&N,&C);
    int * a=(int * )malloc( N * sizeof( int ));
    int i;
    long long count=0;               // 答案用 long long，防溢出
    int *ptr1=a,*ptr2=a+1;           // ptr1 指向 B，ptr2 指向 A
    for(i=0;i<N;i++){
    scanf("%d",&a[i]);
    }
    qsort( a,N,sizeof(int),cmp);    // 排序后差值随指针右移单调不减
    while(ptr2<a+N){
        int diff= *ptr2 - *ptr1;
        if(diff < C){
                ptr2++;              // 差值太小，右移 ptr2 放大
            }else if(diff > C){
                ptr1++;              // 差值太大，右移 ptr1 缩小
                if (ptr1 == ptr2) ptr2++;  // 两指针重合时保持 ptr2 在前
            }else{                   // diff == C：统计两段重复值
                int cnt1 = 1 , cnt2 = 1;
                while(ptr1 + 1< a+N && *ptr1==*(ptr1+1)){
                    cnt1++;          // 数出 B 这一侧相同值的个数
                    ptr1++;
                }
                while(ptr2 + 1< a+N &&*ptr2==*(ptr2+1)){
                    cnt2++;          // 数出 A 这一侧相同值的个数
                    ptr2++;
                }
                count+=(long long )cnt1*cnt2;  // 任意一对 (B,A) 都合法
                ptr1++;
                ptr2++;
            }
        }
    printf("%lld",count);
    free(a);
    return 0;
    }
