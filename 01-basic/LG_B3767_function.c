#include<stdio.h>
#define FUSU  1 
#define XIAOF  2
typedef struct{
    int f;//花色
    int p;//点数
} Card;
int CheckEmpty(Card cards[],int len){
    int i;
    int flag=1;
    for(i=0;i<len;i++){
     if(cards[i].f!=0||cards[i].p!=0){flag=0;break;}
    }
    return flag;
}
int findmin(Card cards[],int len){
    int i;
    int idx = -1;
    for(i=0;i<len;i++){
          if(cards[i].f != 0){  // 只看没出掉的
            idx = i;
            break;
        }
    }
    for(i=0;i<len;i++){
    if (cards[i].f == 0) continue;
    if(cards[i].p<cards[idx].p||(cards[i].p==cards[idx].p&&cards[i].f<cards[idx].f)){idx=i;}
    }
    return idx;
}
int canPlay(Card cards[],int len,int last_f,int last_p){
    int i;
    int idx=-1;
    for(i=0;i<len;i++){
        if (cards[i].f == 0) continue;
        if(cards[i].f==last_f&&(cards[i].p>last_p)){
            if(idx==-1)idx=i;
            else if(cards[i].p<cards[idx].p)idx=i;
        }
    }
    return idx;
}
int main(){
    int T;scanf("%d",&T);
    int k=0;
    for(k=0;k<T;k++){
    int n;scanf("%d",&n);
    int m,r;scanf("%d %d",&m,&r);
    int s;scanf("%d",&s);
    Card fs[n];Card fr[n];
    int i,j;
    for(i=0;i<n;i++){scanf("%d",&fs[i].f);}
    for(i=0;i<n;i++){scanf("%d",&fs[i].p);}
    for(i=0;i<n;i++){scanf("%d",&fr[i].f);}
    for(i=0;i<n;i++){scanf("%d",&fr[i].p);}//输入花色点数
    int last_f,last_p;
    int now_player,last_player;
    last_player = s;
    while(1){
        int min_idx;
// 谁是上一轮最后出牌的，谁这一轮先出
if (last_player == FUSU) {
    min_idx = findmin(fs, n);       // 扶苏找最小
    last_f = fs[min_idx].f;
    last_p = fs[min_idx].p;
    fs[min_idx].f = 0;
    fs[min_idx].p = 0;
} else {
    min_idx = findmin(fr, n);       // 小F找最小
    last_f = fr[min_idx].f;
    last_p = fr[min_idx].p;
    fr[min_idx].f = 0;
    fr[min_idx].p = 0;
}
// 出完立刻判断胜负
if (CheckEmpty(fs, n)) {
    printf("FS wins!\n");
    break;
}
if (CheckEmpty(fr, n)) {
    printf("FR wins!\n");
    break;}
    if (last_player == FUSU) now_player = XIAOF;
    else now_player = FUSU;
        while(1){
        if(now_player==XIAOF){
            int idx=canPlay(fr,n,last_f,last_p);
            if(idx==-1){
                break;
            }
            last_f=fr[idx].f;last_p=fr[idx].p;
            fr[idx].f=0;fr[idx].p=0;
            last_player = now_player; 
        }
        else{
        int idx=canPlay(fs,n,last_f,last_p);
            if(idx==-1){
                break;
            }
            last_f=fs[idx].f;last_p=fs[idx].p;
            fs[idx].f=0;fs[idx].p=0;
            last_player = now_player; 
        }
        if (now_player == XIAOF) {
        now_player = FUSU; 
        } else {
        now_player = XIAOF;
        }
        if( CheckEmpty(fr,n)){
            printf("FR wins!\n");
            break;
        }
        if( CheckEmpty(fs,n)){
            printf("FS wins!\n");
            break;
        }
        }
        }
    }
    return 0;
}

