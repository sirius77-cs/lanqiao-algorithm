/*
 * 洛谷 B3767 [语言月赛 202305] 你的牌太多了 2
 * 考点：模拟（原在 01-basic，实际是纯模拟题，已归入 09-simulate）
 * 题意：扶苏和小 F 各 n 张牌（花色 f、点数 p）。每轮由先手打出手中点数最小的牌
 *       （同点数取花色最小），随后双方轮流跟牌：必须打出与上一张同花色且点数
 *       更大的牌中点数最小的一张；无牌可跟则本轮结束，下一轮由本轮最后出牌者先出。
 *       求谁先出完手牌（输出 FS wins! / FR wins!）。
 * 思路：直接按规则逐张模拟：findmin 找先手最小牌，canPlay 找合法跟牌，
 *       出牌后置 (f,p)=(0,0) 标记已打出，每步之后检查是否有一方出完。
 * 复杂度：每张牌至多打出一次，时间 O(n^2) 级别（n<=100，足够）
 */
#include<stdio.h>
#define FUSU  1
#define XIAOF  2
typedef struct{
    int f;//花色
    int p;//点数
} Card;
int CheckEmpty(Card cards[],int len){    // 判断一方手牌是否已全部打出
    int i;
    int flag=1;
    for(i=0;i<len;i++){
     if(cards[i].f!=0||cards[i].p!=0){flag=0;break;}
    }
    return flag;
}
int findmin(Card cards[],int len){       // 找点数最小的牌；同点数取花色更小者
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
    // 找一张能跟的牌：与上一张同花色且点数更大，取其中点数最小
    // （同花色同点数的牌完全等价，取哪张不影响结果）
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
    int T;scanf("%d",&T);               // 多组测试数据
    int k=0;
    for(k=0;k<T;k++){
    int n;scanf("%d",&n);
    int m,r;scanf("%d %d",&m,&r);
    int s;scanf("%d",&s);               // s=1 扶苏先出，s=2 小F 先出
    Card fs[n];Card fr[n];              // 双方手牌（VLA，n<=100）
    int i,j;
    for(i=0;i<n;i++){scanf("%d",&fs[i].f);}
    for(i=0;i<n;i++){scanf("%d",&fs[i].p);}
    for(i=0;i<n;i++){scanf("%d",&fr[i].f);}
    for(i=0;i<n;i++){scanf("%d",&fr[i].p);}//输入花色点数
    int last_f,last_p;                  // 上一张打出牌的花色、点数
    int now_player,last_player;
    last_player = s;                    // 本轮先出牌者（初始为 s）
    while(1){
        int min_idx;
// 谁是上一轮最后出牌的，谁这一轮先出
if (last_player == FUSU) {
    min_idx = findmin(fs, n);       // 扶苏找最小
    last_f = fs[min_idx].f;
    last_p = fs[min_idx].p;
    fs[min_idx].f = 0;              // 置零表示已打出
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
    if (last_player == FUSU) now_player = XIAOF;   // 轮到对方跟牌
    else now_player = FUSU;
        while(1){                     // 本轮双方轮流跟牌
        if(now_player==XIAOF){
            int idx=canPlay(fr,n,last_f,last_p);
            if(idx==-1){              // 跟不出：本轮结束
                break;
            }
            last_f=fr[idx].f;last_p=fr[idx].p;
            fr[idx].f=0;fr[idx].p=0;
            last_player = now_player; // 最后出牌者更新（决定下轮先手）
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
        if (now_player == XIAOF) {    // 交换出牌权
        now_player = FUSU;
        } else {
        now_player = XIAOF;
        }
        if( CheckEmpty(fr,n)){        // 每次出牌后再查胜负
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
