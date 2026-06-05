#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void *b){
    const int (*x)[2]=(const int (*)[2])a;
    const int(*y)[2]=(const int (*)[2])b;
    return (*x)[1]-(*y)[1];
}
int main(){
    int n;
    scanf("%d",&n);
    int count=1;
    int (* a )[2] = (int (*) [2])malloc(n * 2 * sizeof(int));
    int i;
    for(i=0;i<n;i++){
        scanf("%d %d",&a[i][0],&a[i][1]);
    }
    qsort( a , n , sizeof(int [2]) , cmp );
    int pre=a[0][1];
    for(i=1;i<n;i++){
        if(a[i][0]>=pre){
            //可以选择
            count++;
            pre=a[i][1];
        }
    }
    printf("%d",count);
    free(a);
    return 0;
}