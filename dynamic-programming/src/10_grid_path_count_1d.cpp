#include <bits/stdc++.h>
using namespace std;

int main(){
    int H,W;
    cin >> H >> W;
    vector<vector<char>> maze(H,vector<char>(W));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++) cin >> maze[i][j];
    }

    vector<long long> dp(W);
    dp[0] = 1;

    for(int r=0;r<H;r++){
        for(int c=0;c<W;c++){
            if(maze[r][c] == '#'){
                dp[c] = 0;
                continue;
            }
            if(c > 0) dp[c] += dp[c-1];
        }
    }
    cout << dp[W-1];
}