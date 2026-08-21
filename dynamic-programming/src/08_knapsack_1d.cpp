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

    vector<long long> dp(W+1,0);

    for(int i=1;i<=n;i++){
        for(int w=W;w>=weight[i];w--){
            dp[w] = max(dp[w],dp[w-weight[i]] + value[i]);
        }
    }
    cout << dp[W];
}