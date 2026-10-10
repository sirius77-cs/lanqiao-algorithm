#include<bits/stdc++.h>
using namespace std;

int checkRotate(vector<vector<char>>& a, vector<vector<char>>& b, int n){
    bool ok = true;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n && ok; j++){
                if(a[i][j] != b[j][n-i+1]){
                    ok = false;
                    break;
                }
            }
        }
    if(ok) return 1; // 90度旋转


    ok = true;
    for(int i = 1; i <= n; i++){    
            for(int j = 1; j <= n && ok; j++){
                if(a[i][j] != b[n-i+1][n-j+1]){
                    ok = false;
                    break;
                }
            }
        }
    if(ok) return 2; // 180度旋转

    ok = true;

    for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n && ok; j++){
                if(a[i][j] != b[n-j+1][i]){
                    ok = false;
                    break;
                }
            }
        }
    if(ok) return 3; // 270度旋转
    return 0;
}

int flipangle(vector<vector<char>>& a, vector<vector<char>>& b , int n){

        return checkRotate(a, b, n);
    }

int flipmirror(vector<vector<char>>& a, vector<vector<char>>& b , int n){

        //判断镜像关系，若满足则输出对应编号

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(a[i][j] != b[i][n-j+1]){
                    return 0;
                }
            }
        }
        return 4;
    }

int flipcombine(vector<vector<char>>& a, vector<vector<char>>& b , int n){

        //判断组合关系，若满足则输出对应编号

        vector<vector<char>> mirror_a(n + 1, vector<char>(n + 1, 0));
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++){
            mirror_a[i][j] = a[i][n-j+1];
            }

        if (checkRotate(mirror_a, b, n) != 0) return 5;
        return 0;
    }   

int flipnone(vector<vector<char>>& a, vector<vector<char>>& b , int n){

        //判断无变化关系，若满足则输出对应编号

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(a[i][j] != b[i][j]){
                    return 0;
                }
            }
        }
        return 6;
    }

bool found = false;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;//n是矩阵行数

    vector<vector<char>> a(n + 1, vector<char>(n + 1, 0));
    vector<vector<char>> b(n + 1, vector<char>(n + 1, 0));

    string s;


    for(int i = 1; i <= n; i++){
        cin >> s;
        for(int j = 1; j <= n; j++){
            a[i][j] = s[j-1];
        }
    }


    for(int i = 1; i <= n; i++){
        cin >> s;
        for(int j = 1; j <= n; j++){
            b[i][j] = s[j-1];
        }
    }
        
    int ans1 = flipangle(a,b,n);
    int ans2 = flipmirror(a,b,n);
    int ans3 = flipcombine(a,b,n);
    int ans4 = flipnone(a,b,n);
    if (ans1 != 0) {
        cout << ans1 << endl;
        return 0;   
    }
    else if (ans2 != 0) {
        cout << ans2 << endl;   
        return 0;
    }
    else if (ans3 != 0) {
        cout << ans3 << endl;   
        return 0;
    }
    else if (ans4 != 0) {
        cout << ans4 << endl;   
        return 0;
    }
    else{
    cout << 7 << endl;   
    return 0;
    }
}