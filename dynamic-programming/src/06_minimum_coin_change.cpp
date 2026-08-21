#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,target,inf = 1000000000;
    cin >> n >> target;
    vector<int> coin(n);
    for(int i=0;i<n;i++) cin >> coin[i];

    vector<int> dp(target+1,inf);
    dp[0] = 0;
    for(int i=1;i<=target;i++){
        for(int c : coin){
            if(i>=c && dp[i-c] != inf){
                dp[i] = min(dp[i],dp[i-c]+1);
            }
        }
    }
    if(dp[target] != inf) cout << dp[target];
    else cout << -1;
}