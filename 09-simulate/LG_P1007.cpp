#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L, N;
    cin >> L >> N;//L是桥长度，N是人的数量
    
    vector<vector<int>> pos(N, vector<int>(3));
    for(int i = 0; i < N; i++){
        cin >> pos[i][0];//读入位置
        pos[i][1] = min(pos[i][0], L - pos[i][0]+1);//计算最短时间
        pos[i][2] = max(pos[i][0], L - pos[i][0]+1);//计算最长时间
    }
    int minTime = 0;
    int maxTime = 0;
    for(int i = 0; i < N; i++){
        minTime = max(minTime, pos[i][1]);
        maxTime = max(maxTime, pos[i][2]);
    }
    cout << minTime << " " << maxTime << endl;
    return 0;
}