#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
ll position[100005];
bool check(ll x){
    ll in_cow = 1;
    ll pre;
    pre = 1;
    for(int i = 2; i <= n; i++){
        if(position[i] - position[pre] >= x){
            pre = i;
            in_cow++;
        }
    }
    return in_cow >= m;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> position[i];
    }
    sort(position+1,position+1+n);
    ll l = 0, r = position[n]  - position[1];
    ll mid; 
    while(l <= r){
        mid = l + (r - l)/2;
        if(check(mid)){l = mid + 1;}
        else{r = mid - 1;}
    }
    cout << l << "\n";
    return 0;
}