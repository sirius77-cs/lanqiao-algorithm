#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}
int main(){
    int N,C;
    scanf("%d %d",&N,&C);
    int * a=(int * )malloc( N * sizeof( int ));
    int i;
    long long count=0;
    int *ptr1=a,*ptr2=a+1;
    for(i=0;i<N;i++){
    scanf("%d",&a[i]);
    }
    qsort( a,N,sizeof(int),cmp);
    while(ptr2<a+N){
        int diff= *ptr2 - *ptr1;
        if(diff < C){
                ptr2++;
            }else if(diff > C){
                ptr1++;
                if (ptr1 == ptr2) ptr2++;
            }else{
                int cnt1 = 1 , cnt2 = 1;
                while(ptr1 + 1< a+N && *ptr1==*(ptr1+1)){
                    cnt1++;
                    ptr1++;
                }
                while(ptr2 + 1< a+N &&*ptr2==*(ptr2+1)){
                    cnt2++;
                    ptr2++;
                }
                count+=(long long )cnt1*cnt2;
                ptr1++;
                ptr2++;
            }
        }
    printf("%lld",count);
    free(a);
    return 0;
    }