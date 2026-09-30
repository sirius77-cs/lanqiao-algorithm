/*
 * 洛谷 P3371 【模板】单源最短路径（弱化版）
 * 考点：图论 · Dijkstra 堆优化版（原在 07-date_structure，最短路属图论，
 *       已归入 08-graph）
 * 题意：n 点 m 边有向图（非负边权），求 s 到每个点的最短路，不可达输出 (1<<31)-1。
 * 思路：vector 邻接表存图；小根堆维护 (dist, 点)，
 *       每次取出堆顶（当前最近未确定点）松弛其出边；
 *       取出的 dist 已大于记录值则跳过（惰性删除过期堆项）。
 * 复杂度：时间 O((n+m) log n)，空间 O(n+m)
 */
#include<bits/stdc++.h>
using namespace std;

struct Edge
{
    int to;//终点
    int w;//边权
};
vector <Edge>g[10005];             // 邻接表：g[u] = u 的所有出边
int dist[10005];                   // dist[i]：起点到 i 的最短路估计
const int INF = 0x3f3f3f3f;        // "无穷大"标记
unsigned long long x = (1ULL << 31) - 1;  // 题目要求的不可达输出值 2147483647

void dijkstra(int n , int start){
    for(int i = 1; i <= n; i++)dist[i] = INF;   // 初始化为无穷
    dist[start] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;  // 小根堆 (dist, 点)
    pq.push({0,start});

    while(!pq.empty()){
        auto[d , u] = pq.top();pq.pop();
        if(d > dist[u])continue;   // 过期堆项：u 已被更短路更新过，跳过
        for(auto &e : g[u]){       // 松弛 u 的每条出边
            if(e.w + dist[u] < dist[e.to]){
                dist[e.to] = e.w + dist[u];
                pq.push({dist[e.to],e.to});
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,s;
    cin >> n >> m >> s;            // 点数、边数、起点

    for(int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});     // 有向边 u -> v
    }
    dijkstra(n,s);
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) cout << x << " ";   // 不可达按题目要求输出
        else cout << dist[i] << " ";
    }
    cout << "\n";
    return 0;
}
