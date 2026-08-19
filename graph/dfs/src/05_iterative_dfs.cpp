#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<int> visited(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int s;
    cin >> s;
    stack<int> stk;
    stk.push(s);
    visited[s] = 1;
    while(!stk.empty()){
        int u = stk.top();
        stk.pop();
        cout << u << ' ';
        for(int v : adj[u]){
            if(!visited[v]){
                visited[v] = 1;
                stk.push(v);
            }
        }
    }
}