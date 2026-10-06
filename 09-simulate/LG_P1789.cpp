/*
 * 洛谷 P1789 【Mc生存】插火把
 * 考点：模拟（二维矩阵染色）
 * 题意：n×n 方阵放 m 个火把、k 个萤石。火把照亮以其为中心 5×5 范围内
 *       曼哈顿距离 <=2 的 13 格（菱形）；萤石照亮以其为中心的整个 5×5
 *       方格（切比雪夫距离 <=2）。统计既无光又没放东西（仍为 0）的格子数。
 * 思路：开 (n+1)×(n+1) 的矩阵（1 开始编号），火把按 |dx|+|dy|<=2 染色、
 *       萤石按 5×5 染色，注意用 max/min 把边界夹在 [1,n] 内防止越界，
 *       最后数 0 的个数。
 * 复杂度：时间 O(n^2 + 25(m+k))，空间 O(n^2)
 */
#include<bits/stdc++.h>
using namespace std;

void torch_effect(vector<vector<int>>& a, int m, vector<array<int, 2>>& torchpositions, int n){

        //火把的效果是将其所在行和列且边长为5以及边长为1的周围的所有元素都变为1
        //（即 5×5 范围内曼哈顿距离 <=2 的格子）

        for(int i = 0; i < m; i++){
            int x = torchpositions[i][0];
            int y = torchpositions[i][1];
            for(int row = max(1, x - 2); row <= min(n, x + 2); row++){
                for(int col = max(1, y - 2); col <= min(n, y + 2); col++){
                    if(abs(row - x) + abs(col - y) <= 2){    // 曼哈顿距离 <=2 才被照亮
                        a[row][col] = 1;
                    }
                }
            }
        }
    }

void stone_effect(vector<vector<int>>& a, int k, vector<array<int, 2>>& storepositions, int n){

        //萤石的效果是将其所在边长为5的所有元素都变为1

        for(int i = 0; i < k; i++){
            int x = storepositions[i][0];
            int y = storepositions[i][1];
            for(int j = max(1, x - 2); j <= min(n , x + 2); j++){
                for(int l = max(1, y - 2); l <= min(n, y + 2); l++){
                    a[j][l] = 1;                            // 5×5 全亮（切比雪夫距离 <=2）
                }
            }
        }
    }

void count_zero(vector<vector<int>>& a, int n){

    //统计矩阵中0的个数，输出结果
        int count = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(a[i][j] == 0){
                    count++;
                }
            }
        }
        cout << count << endl;
    }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,k;
    cin >> n >> m >> k;//n是矩阵行数，m是火把数，k是萤石数

    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));   // 已在构造时初始化为 0

    vector<array<int, 2>> torchpositions(m);
    vector<array<int, 2>> storepositions(k);

    for(int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        torchpositions[i][0] = x;
        torchpositions[i][1] = y;
    }

    for(int i = 0; i < k; i++){
        int x,y;
        cin >> x >> y;
        storepositions[i][0] = x;
        storepositions[i][1] = y;
    }

    //初始化矩阵为0（注：上方 vector 构造时已置 0，此循环为冗余保险，可留可删）
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            a[i][j] = 0;
        }
    }

    //应用火把和萤石的效果
    torch_effect(a, m, torchpositions, n);

    if(k > 0)stone_effect(a, k, storepositions, n);    // k=0 时循环体本就不会执行，判断仅是额外保险

    //统计并输出0的个数
    count_zero(a, n);

    return 0;
}
