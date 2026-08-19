#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> depth;


void DFS(int u){
    for(int v : adj[u]){
        if(depth[v] == -1){
            depth[v] = depth[u] + 1;
            DFS(v);
        }
    }
}

int main(){
    int n;
    cin >> n;
    adj.resize(n+1);
    depth.resize(n+1,-1);
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int root;
    cin >> root;
    depth[root] = 0;
    DFS(root);
    for(int i=1;i<n+1;i++) cout << depth[i] << ' ';
}