#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,W;
    cin >> n >> W;
    vector<int> weight(n+1);
    vector<int> value(n+1);
    for(int i=1;i<=n;i++){
        int a,b;
        cin >> a >> b;
        weight[i] = a;
        value[i] = b;
    }

    vector<vector<long long>> dp(
        n + 1,
        vector<long long>(W + 1, 0)
    );

    for(int i=1;i<=n;i++){
        for(int w=0;w<=W;w++){
            dp[i][w] = dp[i-1][w];
            if(weight[i]<=w){
                dp[i][w] = max(dp[i][w],dp[i-1][w-weight[i]] + value[i]);
            }
        }
    }
    cout << dp[n][W];
}