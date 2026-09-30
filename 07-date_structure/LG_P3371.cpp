#include<bits/stdc++.h>
using namespace std;

struct Edge
{
    int to;//终点
    int w;//边权
};
vector <Edge>g[10005];
int dist[10005];
const int INF = 0x3f3f3f3f;
unsigned long long x = (1ULL << 31) - 1;

void dijkstra(int n , int start){
    for(int i = 1; i <= n; i++)dist[i] = INF;
    dist[start] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,start});

    while(!pq.empty()){
        auto[d , u] = pq.top();pq.pop();
        if(d > dist[u])continue;
        for(auto &e : g[u]){
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
    cin >> n >> m >> s;

    for(int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
    }
    dijkstra(n,s);
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) cout << x << " ";
        else cout << dist[i] << " ";
    }
    cout << "\n";
    return 0;
}