#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> subtree;

void DFS(int u,int parent){
    subtree[u] = 1;

    for(int v : adj[u]){
        if(v == parent) continue;

        DFS(v,u);
        subtree[u] += subtree[v];
    }
}

int main(){
    int n;
    cin >> n;
    adj.resize(n+1);
    subtree.resize(n+1);
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int root;
    cin >> root;
    DFS(root,-1);
    for(int i=1;i<n+1;i++) cout << subtree[i] << ' ';
}