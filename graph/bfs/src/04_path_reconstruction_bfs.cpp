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

    vector<int> path(n+1);
    queue<int> q;
    vector<int> d(n+1);
    for(int i=1;i<n+1;i++) d[i] = -1;
    int s,t;
    cin >> s >> t;
    d[t] = 0;
    q.push(t);
    while(!q.empty()){
       int v = q.front();
        q.pop();
        for(int i=0;i<adj[v].size();i++){
            if(d[adj[v][i]] == -1){
                d[adj[v][i]] = d[v] + 1;
                path[adj[v][i]] = v;
                q.push(adj[v][i]);
            }
        }
    }
    int x = s;
    if(d[s] == -1) cout << -1;
    else{
        cout << d[s] << endl;
        while(x!=t){
            cout << x << ' ';
            x = path[x];
        }
        cout << x;
    }
    
}