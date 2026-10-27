#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n , c;
vector<ll>a(200005);
ll sum;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> c;
    for(int i = 0; i < n ; i++){
        cin >> a[i];
    }
    sort(a.begin(),a.begin() + n);
    for(int i = 0; i < n; i++){
        ll target = a[i] + c;
        auto it1 = lower_bound(a.begin() + i + 1,a.begin() + n,target);
        auto it2 = upper_bound(a.begin() + i + 1,a.begin() + n,target);
            if(it1 != a.begin() + n && *it1 == target){
                sum += it2 - it1;
        }
    }
    cout << sum << " ";
    return 0;
}