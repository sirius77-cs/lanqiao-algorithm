#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;//n是食材种类数

    vector<vector<int>> inf(n, vector<int> (2, 0));
    for(int i = 0; i < n; i++){
        cin >> inf[i][0] >> inf[i][1];//读入酸度和苦度
    }
    int differ = INT_MAX;

    for(int mask = 1; mask < (1 << n); mask++){
        int curracid = 1, currbitter = 0;
        for(int i = 0; i < n; i++){
            if(mask & (1 << i)){
                curracid *= inf[i][0];
                currbitter += inf[i][1];
            }
        }
        if(abs(curracid - currbitter) < differ){
            differ = abs(curracid - currbitter);
        }
    }
    cout << differ << endl;
    return 0;
}

