#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;//n是车厢总数

    vector<int> cars(n);
    for(int i = 0; i < n; i++){
        cin >> cars[i];
    }
    int count = 0;
    while(is_sorted(cars.begin(), cars.end()) == false){
        for(int i = n-1; i > 0; i--){
            if(cars[i] < cars[i - 1]){
                swap(cars[i], cars[i - 1]);
                count++;
            }
        }
    }
    cout << count << endl;
} 