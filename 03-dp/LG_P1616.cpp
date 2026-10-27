#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t,m;
    cin >> t >>m;
    vector<long long> dp(t + 1, 0);
    for(int i = 1; i <= m;i++){
        long long w,v;
        cin >> w >>v;
        for(int j = w; j <= t; j++){
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }
    cout << dp[t] << "\n";
    return 0;
}