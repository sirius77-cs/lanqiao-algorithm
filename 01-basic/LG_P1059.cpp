#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end()); 
    a.erase(unique(a.begin(), a.end()), a.end());
    cout << a.size() << endl;
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    return 0;
}