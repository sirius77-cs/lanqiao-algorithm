#include<bits/stdc++.h>
using namespace std;

int binary_ans(int left, int right, int n, const vector<int>& a, int k){
    int ans;
    while(left <= right){
    int mid = (left + right) / 2;
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i] / mid;
    }
    if(sum >= k){
        ans = mid;       // 记录可行解
        left = mid + 1;  // 尝试更大的长度
    } else {
        right = mid - 1; // 长度太大，减小
    }
}
return ans;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;
    vector<int>wood(n);
    for(int i = 0; i < n; i++){
        cin >> wood[i];
    }
    int left = 1, right = *max_element(wood.begin(), wood.end());
    cout << binary_ans(left, right, n, wood, k) << endl;
}