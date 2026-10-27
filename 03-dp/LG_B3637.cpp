#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>a(100005);
int lenOfLIS(){
    vector<int>tails;
    for(int i = 0; i < n; i++){
        int x =a[i];
        auto it = lower_bound(tails.begin(),tails.end(),x);
        if(it == tails.end()){
            tails.push_back(x);
        }else{
            *it = x;
        }
    }
    return tails.size();
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n ; i++){
        cin >> a[i];
    }
    int ans = lenOfLIS();
    cout << ans << " ";
    return 0;
}