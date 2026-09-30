/*
 * 洛谷 B4502 [GESP202603 四级] 礼盒排序
 * 考点：结构体封装 + qsort 多关键字排序
 * 题意：n 个礼盒各含 k 件商品，按（总价, 最贵商品价, 最便宜商品价, 编号）
 *       四重关键字升序排序，输出排序后的礼盒编号。
 * 思路：读入每个礼盒时顺手统计 sum/max/min/id 封装进结构体，
 *       cmp 里按优先级逐级比较，最后 qsort 一遍。
 * 数据范围：1<=n<=10^3, 1<=k<=10, 价格<=10^4（sum 最大 10^5，int 足够）
 * 复杂度：时间 O(nk + n log n)，空间 O(n)
 *
 * 【本次修订】修正两处问题：
 *   1. Sum() 中 sum 未初始化（未定义行为，靠栈上垃圾值碰运气）；
 *   2. 柔性数组布局隐患：malloc 按 sizeof(Gift_inf)+k*sizeof(int) 分配每个元素，
 *      但 arr[i] 指针运算按 sizeof(Gift_inf) 步长寻址，arr[i].a[] 实际写进了
 *      相邻元素的区域；qsort 也以 sizeof(Gift_inf) 为元素大小交换内存块。
 *      原代码仅因统计值在读入后立刻算好、柔性数组数据不再被读取才“碰巧”跑对，
 *      属于脆弱写法。现改为用临时数组 tmp 读入，结构体不再依赖柔性数组。
 */
#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int len;
    int sum;
    int max;
    int min;
    int id;
    // int a[];   // 【原代码·已注释】柔性数组，配合旧的 malloc 布局使用，见文件头说明
}Gift_inf;
int Sum(int a[],int len){
    int i;
    // int sum;   // 【错误·已注释】未初始化，累加的是栈上的随机值
    int sum = 0;  // 【修正】累加器必须初始化为 0
    for(i=0;i<len;i++){
        sum+=a[i];
    }
    return sum;
}
int getMax(int arr[], int n) {
    int max = arr[0];              // 打擂台求最大值
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}
int getMin(int arr[], int n) {
    int min = arr[0];              // 打擂台求最小值
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}
int cmp(const void *x, const void *y) {
    // 把 void* 转回结构体指针
    Gift_inf *p1 = (Gift_inf *)x;
    Gift_inf *p2 = (Gift_inf *)y;
    if (p1->sum != p2->sum) {      // 第一关键字：总价升序
        return p1->sum - p2->sum;
    }
    if (p1->max != p2->max) {      // 第二关键字：最贵商品升序
        return p1->max - p2->max;
    }
    if (p1->min != p2->min) {      // 第三关键字：最便宜商品升序
        return p1->min - p2->min;
    }
    return p1->id - p2->id;        // 第四关键字：编号升序
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);//n 个礼盒，每盒 k 件商品
    // Gift_inf *arr=(Gift_inf *)malloc((n+1)*(sizeof(Gift_inf)+k*sizeof(int))); // 【原代码·已注释】按“结构体+柔性数组”的步长分配
    Gift_inf *arr=(Gift_inf *)malloc((n+1)*sizeof(Gift_inf)); // 【修正】去掉柔性数组后按统一元素大小分配
    if(arr==NULL)return 1;
    int i,j;
    int tmp[15];                   // 【修正】k<=10，用临时数组暂存当前礼盒的商品价格
    for(i=1;i<=n;i++){
        arr[i].len=k;
        // for(j=0;j<k;j++){ scanf("%d",&arr[i].a[j]); }  // 【原代码·已注释】向柔性数组写入（布局隐患见文件头）
        for(j=0;j<k;j++){
            scanf("%d",&tmp[j]);
        }
        arr[i].sum=Sum(tmp,k);     // 统计值算好即存入结构体
        arr[i].max=getMax(tmp,k);
        arr[i].min=getMin(tmp,k);
        arr[i].id=i;
        }
    qsort(arr + 1, n, sizeof(Gift_inf), cmp);  // 从 1 号礼盒开始排；元素大小与分配步长一致
    for (int i = 1; i <= n; i++) {
        printf("%d ", arr[i].id);
    }
    free(arr);
    return 0;
}
