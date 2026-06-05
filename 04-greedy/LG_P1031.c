#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }

    int *a = (int *)malloc(n * sizeof(int));
    if (a == NULL) {
        return 0;
    }

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    int avg = (int)(sum / n);
    int prefix = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (prefix != 0) {
            count++;
        }
        prefix += a[i] - avg;
    }

    printf("%d", count);
    free(a);
    return 0;
}
//下面为初版，上部分为copilot优化后的
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
//     int * a=(int *)malloc( n * sizeof(int));
//     for(int i=0;i<n;i++){
//         scanf("%d",&a[i]);
//     }
//     int avg=Average(a,n);
//     int * d=(int *)malloc( n * sizeof(int));
//     int * s=(int *)malloc( n * sizeof(int));
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