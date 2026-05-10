#include<stdio.h>
long long Pow(long long a,long long b,long long p){
    long long res=1;
    while(b>0){
        if(b%2==1){res=(res*a)%p;}
        a=(a*a)%p;
        b/=2;
    }
    return res;
}
int main(){
    long long a,b,p;
    scanf("%lld %lld %lld",&a,&b,&p);
    long long res=Pow(a,b,p);
    printf("%lld^%lld mod %lld=%lld",a,b,p,res);
    return 0;
}