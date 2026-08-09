#include <bits/stdc++.h>
using namespace std;

int main(){
    int H,W;
    cin >> H >> W;
    vector<vector<char>> gird(H,vector<char>(W));
    vector<vector<int>> dist(H,vector<int>(W));
    queue<pair<int,int>> q;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> gird[i][j];
            if(gird[i][j] == 'G'){
                q.push({i,j});
                dist[i][j] = 0;
            }else dist[i][j] = -1;
        }
    }
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    while(!q.empty()){
        pair<int,int> v = q.front();
        int r = v.first;
        int c = v.second;
        q.pop();
        for(int k=0;k<4;k++){
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(0<=nr and nr<H and 0<=nc and nc<W){
                if(gird[nr][nc] != '#' and dist[nr][nc] == -1){
                    dist[nr][nc] = dist[r][c] +1;
                    q.push({nr,nc});
                }
            }
        }
    }
    int ans = 0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(gird[i][j] != '#'){
                if(dist[i][j] == -1){
                    ans = -1;
                    break;
                }else if(dist[i][j] > ans) ans = dist[i][j];            
            }
        }
        if(ans == -1) break;
    }
    cout << ans;
}