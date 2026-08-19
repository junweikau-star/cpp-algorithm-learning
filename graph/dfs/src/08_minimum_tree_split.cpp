#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> subtree;
int ans;

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
    ans = n;
    adj.resize(n+1);
    subtree.resize(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    DFS(1,-1);
    for(int i=2;i<n+1;i++){
        int c = abs(n - 2*subtree[i]);
        ans = min(ans,c);
    }
    cout << ans;
}