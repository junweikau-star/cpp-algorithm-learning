#include <bits/stdc++.h>
using namespace std;

int main(){
    int H,W;
    cin >> H >> W;
    vector<vector<char>> maze(H,vector<char>(W));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++) cin >> maze[i][j];
    }

    vector<vector<long long>> dp(H,vector<long long>(W,0));
    dp[0][0] = 1;

    for(int r=0;r<H;r++){
        for(int c=0;c<W;c++){
            if(maze[r][c] == '#'){
                dp[r][c] = 0;
                continue;
            }
            if(r > 0) dp[r][c] += dp[r-1][c];
            if(c > 0) dp[r][c] += dp[r][c-1];
        }
    }
    cout << dp[H-1][W-1];
}