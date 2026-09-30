#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        pq.push(x);
    }
    int sum = 0;
    while(pq.size() > 1){
        int a = pq.top(); pq.pop();   // 最小的
        int b = pq.top(); pq.pop();   // 次小的
        int c = a + b;
        sum += c;
        pq.push(c);                   // 合并后放回堆
    }
    cout << sum << "\n";
    return 0;
}