#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll n ,m;
vector<ll>a(1e6+5);
bool check(ll mid){
    ll sum = 0;
    for(int i = 1 ; i <= n; i++){
        if(a[i] - mid > 0){sum = sum + (a[i] - mid);}
    }
    return sum >= m;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    ll r = 0, l =0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        r = max(r,a[i]);
    }
    int ans = 0;
    while(l <= r){
        ll mid = l + (r - l) / 2;
        if(check(mid)){
            ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    cout << ans << " ";
    return 0;
}