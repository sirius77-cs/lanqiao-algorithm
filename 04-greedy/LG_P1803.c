/*
 * 洛谷 P1803 凌乱的yyy / 线段覆盖（活动选择问题）
 * 考点：贪心 · 区间调度
 * 题意：n 个比赛区间 [begin, end]，一个时间点只能参加一个（结束时刻可接下一场），
 *       求最多能参加几场。
 * 思路：按结束时间升序排序；每次选择结束最早且与已选区间不冲突的比赛，
 *       最早结束给后面留出最多空间，是经典交换论证可证的最优贪心。
 * 复杂度：时间 O(n log n)，空间 O(n)
 * 说明：cmp 里把 void* 转成 int(*)[2] 是 qsort 排二维数组（n 行 2 列）的写法。
 */
#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void *b){
    const int (*x)[2]=(const int (*)[2])a;   // 每个元素是 int[2]
    const int(*y)[2]=(const int (*)[2])b;
    return (*x)[1]-(*y)[1];                  // 按结束时间 (*x)[1] 升序
}
int main(){
    int n;
    scanf("%d",&n);
    int count=1;                     // 至少能参加第一场（结束最早的那场）
    int (* a )[2] = (int (*) [2])malloc(n * 2 * sizeof(int));  // n 行 2 列：a[i][0]=开始, a[i][1]=结束
    int i;
    for(i=0;i<n;i++){
        scanf("%d %d",&a[i][0],&a[i][1]);
    }
    qsort( a , n , sizeof(int [2]) , cmp );
    int pre=a[0][1];                 // 上一场选中比赛的结束时间
    for(i=1;i<n;i++){
        if(a[i][0]>=pre){            // 开始时间不早于上一场结束：不冲突（题目允许恰好接上）
            //可以选择
            count++;
            pre=a[i][1];
        }
    }
    printf("%d",count);
    free(a);
    return 0;
}
