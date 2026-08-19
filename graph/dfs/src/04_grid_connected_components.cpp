#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> maze;
vector<vector<int>> visited;
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
int n,m;

void DFS(int r,int c){
    visited[r][c] = 1;
    for(int i=0;i<4;i++){
        int nr = r+dr[i];
        int nc = c+dc[i];

        if(0<=nr && nr <n && 0<=nc && nc<m){
            if(!visited[nr][nc] && maze[nr][nc] == '.'){
                DFS(nr,nc);
            }
        }
    }
}

int main(){
    
    cin >> n >> m;
    maze.resize(n,vector<char>(m));
    visited.resize(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin >> maze[i][j];
    }
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            if(!visited[i][j] && maze[i][j] == '.'){
                cnt += 1;
                DFS(i,j);
        }
    }
    cout << cnt;
}