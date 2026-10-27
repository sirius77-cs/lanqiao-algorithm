#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,d;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> d;
    vector<ll>position(n+1);
    for(int i = 1; i <= n; i++){
        cin >> position[i];
    }
    sort(position.begin()+1,position.begin()+n+1);
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        int cnt = upper_bound(position.begin()+i+1,position.begin()+n+1,position[i]+d) - (position.begin()+i+1);
        sum+=cnt;
    }
    cout << sum <<"\n";
    return 0;
    } 