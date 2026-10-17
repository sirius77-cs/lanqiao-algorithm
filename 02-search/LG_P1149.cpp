#include<bits/stdc++.h>
using namespace std;

map<int, int> cost = {
        {0, 6},
        {1, 2},
        {2, 5},
        {3, 5},
        {4, 4},
        {5, 5},
        {6, 6},
        {7, 3},
        {8, 7},
        {9, 6}
    };

int countStick(int x){
    if(x == 0) return cost[0];
    int sum = 0;
    while(x > 0){
        sum += cost[x % 10];
        x /= 10;
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    if(n <= 4){
        cout << 0 << "\n";
        return 0;
    }

    int real_num = n - 4;
    int ans = 0;

    for(int a = 0; a <= 1000; a++){
        for(int b = a; b <= 1000; b++){
            if(countStick(a) + countStick(b) +countStick(a + b) == real_num){
                if(a != b)ans+=2;
                else ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
