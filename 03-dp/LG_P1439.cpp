#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>a1,vector<int>a2,int n){
    vector<int> pos(n + 1);
    for(int i = 0; i < n; i++) {
        pos[a1[i]] = i; 
    }
    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        b[i] = pos[a2[i]];
    }
    vector<int>tails;
    for(int x : b){
        auto it = lower_bound(tails.begin(),tails.end(),x);
        if(it == tails.end()){
            tails.push_back(x);
        }
        else{*it = x;}
    }
    return tails.size();
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int>a1(n);
    vector<int>a2(n);
    for(int i = 0; i < n; i++){
        cin >> a1[i];
    }
    for(int i = 0; i < n; i++){
        cin >> a2[i];
    }

    int ans = solve(a1,a2,n);
    cout << ans <<"\n";
    return 0;
}