#include<bits/stdc++.h>
using namespace std;

int n,m;
char arr[10005][10005];
bool vis[10005][10005];
bool pd = 1;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool check(int x,int y){
    return x > 0 && x <= n && y > 0 && y <= m;
}

void dfs(int x,int y){
    if(vis[x][y])return;
    vis[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(check(nx,ny) && arr[nx][ny] == '.' && !vis[nx][ny]){
            if(nx == n && ny == m){
                pd = 0;
                return;
            }
            dfs(nx,ny);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
        }
    }
    dfs(1,1);
    if(pd == 0){
        cout << "Yes";
        return 0;
    }
    cout << "No";
    return 0;
}