#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> visited;

void DFS(int u){
    visited[u] = 1;

    for(int v : adj[u]){
        if(!visited[v]){
            DFS(v);
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    adj.resize(n+1);
    visited.resize(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int cnt = 0;
    for(int i=1;i<n+1;i++){
        if(!visited[i]){
            cnt += 1;
            DFS(i);
        }
    }
    cout << cnt;
}