#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int n,m;
vector<long long>a(MAXN);

bool check(int mid){
    long long  sum = 0,cnt = 1;
    for(int i = 0 ; i < n; i++){
        if(sum + a[i] <= mid){sum+=a[i];}
        else{
            cnt++;
            sum = a[i];
        }
    }
    return cnt <= m;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    long long  l = 0, r = 0;
    int ans = 0;
    for(int i = 0 ; i < n; i++){
        cin >> a[i];
        l = max(l, a[i]);
        r += a[i]; 
    }
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(check(mid)){
            ans = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    cout << ans << " ";
    return 0;
}