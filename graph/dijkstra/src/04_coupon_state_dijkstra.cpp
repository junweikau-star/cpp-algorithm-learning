#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,long long>>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        long long w;
        cin >> a >> b >> w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    const long long INF = 4'000'000'000'000'000'000LL;
    int s,t;
    cin >> s >> t;
    priority_queue<
        pair<long long,pair<int,int>>,
        vector<pair<long long,pair<int,int>>>,
        greater<pair<long long,pair<int,int>>>
    > pq;
    vector<vector<long long>> dist(n+1,vector<long long>(2,INF));
    dist[s][0] = 0;
    pq.push({0,{s,0}});

    while(!pq.empty()){
        pair<long long,pair<int,int>> state = pq.top();
        long long d = state.first;
        int u = state.second.first;
        int used = state.second.second;
        pq.pop();
        if(d > dist[u][used]) continue;

        for(pair<int,long long> edge:adj[u]){
            int v = edge.first;
            long long w = edge.second;

            long long newDist = d + w;
            if(newDist < dist[v][used]){
                dist[v][used] = newDist;
                pq.push({newDist,{v,used}});
            }
            if(used == 0 and d < dist[v][1]){
                dist[v][1] = d;
                pq.push({d,{v,1}});
            }
        }
    }
    long long ans = min(dist[t][0],dist[t][1]);
    if(ans == INF) cout << -1;
    else cout << ans;
}