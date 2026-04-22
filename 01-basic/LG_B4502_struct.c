#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int len;
    int sum;
    int max;
    int min;
    int id;
    int a[];
}Gift_inf;
int Sum(int a[],int len){
    int i;
    int sum;
    for(i=0;i<len;i++){
        sum+=a[i];
    }
    return sum;
}
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}
int getMin(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}
int cmp(const void *x, const void *y) {
    // 把 void* 转回你的结构体指针
    Gift_inf *p1 = (Gift_inf *)x;
    Gift_inf *p2 = (Gift_inf *)y;
    if (p1->sum != p2->sum) {
        return p1->sum - p2->sum;
    }
    if (p1->max != p2->max) {
        return p1->max - p2->max;
    }
    if (p1->min != p2->min) {
        return p1->min - p2->min;
    }
    return p1->id - p2->id;
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);//n行k个
    Gift_inf *arr=(Gift_inf *)malloc((n+1)*(sizeof(Gift_inf)+k*sizeof(int)));
    if(arr==NULL)return 1;
    int i,j;
    for(i=1;i<=n;i++){
        arr[i].len=k;
        for(j=0;j<k;j++){
            scanf("%d",&arr[i].a[j]);
        }
        arr[i].sum=Sum(arr[i].a,k);
        arr[i].max=getMax(arr[i].a,k);
        arr[i].min=getMin(arr[i].a,k);
        arr[i].id=i;
        }
    qsort(arr + 1, n, sizeof(Gift_inf), cmp);
    for (int i = 1; i <= n; i++) {
        printf("%d ", arr[i].id);
    }    
    free(arr); 
    return 0;
}