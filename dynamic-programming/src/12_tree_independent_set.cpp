#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<long long> value;;
vector<vector<long long>> dp;

void DFS(int u,int parent){
    dp[u][0] = 0;
    dp[u][1] = value[u];

    for(int v:adj[u]){
        if(v == parent) continue;

        DFS(v,u);
        dp[u][0] += max(dp[v][1],dp[v][0]);
        dp[u][1] += dp[v][0];
    }
}

int main(){
    int n;
    cin >> n;
    value.resize(n+1);
    for(int i=1;i<=n;i++) cin >> value[i];
    adj.resize(n+1);
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dp.resize(
        n + 1,
        vector<long long>(2, 0)
    );
    DFS(1,-1);

    cout << max(dp[1][0],dp[1][1]);
}