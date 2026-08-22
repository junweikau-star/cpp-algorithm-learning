#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    const long long INF = 4'000'000'000'000'000'000LL;
    cin >> n >> m;
    vector<vector<pair<int,long long>>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        long long w;
        cin >> a >> b >> w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    int start,target;
    cin >> start >> target;

    priority_queue<
        pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long, int>>
        > pq;
    pq.push({0,start});
    vector<long long> dist(n+1,INF);
    dist[start] = 0;
    vector<int> parent(n+1,-1);


    while(!pq.empty()){
        pair<long long,int> state = pq.top();
        long long d = state.first;
        int u = state.second;
        pq.pop();
        if(d > dist[u]) continue;

        for(pair<int,long long> edge:adj[u]){
            int v = edge.first;
            long long w = edge.second;

            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v],v});
            }
        }
    }
    if(dist[target] == INF) cout << -1;
    else{
        cout << dist[target] << '\n';
        vector<int> ans;
        int x = target;
        while(x!=start){
            ans.push_back(x);
            x = parent[x];
        }
        ans.push_back(x);
        reverse(ans.begin(),ans.end());
        for(int i:ans) cout << i << ' ';
    }
}