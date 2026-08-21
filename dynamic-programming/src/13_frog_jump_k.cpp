#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,K;
    const long long INF = 1'000'000'000'000'000'000LL;
    cin >> n >> K;
    vector<long long> h(n + 1);
    for(int i=1;i<=n;i++) cin >> h[i];

    vector<long long> dp(n+1,INF);
    dp[1] = 0;

    for(int i=2;i<=n;i++){
        for(int j=1;j<=K;j++){
            if(i>j){
                dp[i] = min(dp[i],dp[i-j] + abs(h[i] - h[i-j]));
            }
        }
    }
    cout << dp[n];
}