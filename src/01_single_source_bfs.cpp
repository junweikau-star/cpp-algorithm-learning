#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int s;
    cin >> s;
    vector<int> d(n+1);
    for(int i=1;i<n+1;i++) d[i] = -1;
    d[s] = 0;
    vector<int> visited(n+1);
    visited[s] = 1;
    queue<int> q;
    q.push(s);


    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int i=0;i<adj[v].size();i++){
            if(visited[adj[v][i]] == 0){
                visited[adj[v][i]] = 1;
                d[adj[v][i]] = d[v]+1;
                q.push(adj[v][i]);
            }
        }
    }
    for(int i=1;i<n+1;i++) cout << d[i] << " ";
}