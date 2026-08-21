#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> h(n+1);
    for(int i=1;i<n+1;i++) cin >> h[i];
    if(n==1){
        cout << 0;
        return 0;
    }

    vector<long long> dp(n+1,0);
    dp[1] = 0;
    dp[2] = abs(h[2] - h[1]);
    for(int i=3;i<n+1;i++){
        dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]),dp[i-2] + abs(h[i] - h[i-2]));
    }
    cout << dp[n];
}