#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> value(n+1);
    for(int i=1;i<=n;i++) cin >> value[i];

    vector<long long> dp(n+1,0);
    dp[1] = value[1];
    for(int i=2;i<=n;i++){
        dp[i] = max(dp[i-1],dp[i-2] + value[i]);
    }
    cout << dp[n];
}