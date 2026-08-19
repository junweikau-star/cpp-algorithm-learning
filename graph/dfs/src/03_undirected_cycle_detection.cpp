#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> visited;

bool DFS(int u,int parent){
    visited[u] = 1;

    for(int v : adj[u]){
        if(!visited[v]){
            if(DFS(v,u)) return true;
        }else{
            if(v != parent) return true;
        }
    }
    return false;
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
    string ans = "NO";
    for(int i=1;i<n+1;i++){
        if(!visited[i]){
            if(DFS(i,-1)){
                ans = "YES";
                break;
            } 
        }
    }
    cout << ans;
}