#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> coin(n+1);
    for(int i=1;i<n+1;i++) cin >> coin[i];
    vector<long long> dp(n+1,0);
    dp[1] = coin[1];
    vector<int> from(n+1,0);
    from[1] = 0;

    for(int i=2;i<n+1;i++){
        if(dp[i-1] >= dp[i-2]){
            dp[i] = coin[i] + dp[i-1];
            from[i] = i-1;
        }else{
            dp[i] = coin[i] + dp[i-2];
            from[i] = i-2;
        }
    }
    cout << dp[n] << '\n';


    vector<int> path;

    int x=n;
    while(x!=0){
        path.push_back(x);
        x = from[x];
    }
    reverse(path.begin(), path.end());
    for(int i:path) cout << i << ' ';
}