#include <bits/stdc++.h>
using namespace std;

int main(){
    int H,W;
    cin >> H >> W;
    vector<vector<long long>> cost(H,vector<long long>(W));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++) cin >> cost[i][j];
    }

    int dr[4] = {0,0,1,-1};
    int dc[4] = {1,-1,0,0};

    int sr,sc,tr,tc;
    cin >> sr >> sc >> tr >> tc;
    const long long INF = 4'000'000'000'000'000'000LL;

    priority_queue<
        pair<long long,pair<int,int>>,
        vector<pair<long long,pair<int,int>>>,
        greater<pair<long long,pair<int,int>>>
        > pq;

    vector<vector<long long>> dist(H,vector<long long>(W,INF));
    dist[sr][sc] = 0;
    pq.push({0,{sr,sc}});
    vector<vector<pair<int, int>>> parent(
    H,
    vector<pair<int, int>>(W, {-1, -1})
    );

    while(!pq.empty()){
        pair<long long,pair<int,int>> state = pq.top();
        long long d = state.first;
        int r = state.second.first;
        int c = state.second.second;
        pq.pop();

        if(d>dist[r][c]) continue;

        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];

            if(nr >= H or  nr <0 or nc >= W or nc <0) continue;
            if(cost[nr][nc] == -1) continue;

            long long n = d + cost[nr][nc];
            if(n<dist[nr][nc]){
                dist[nr][nc] = n;
                parent[nr][nc] = {r,c};
                pq.push({n,{nr,nc}});
            }
        }
    }

    int r=tr,c=tc;
    vector<pair<int,int>> path;

    if(dist[tr][tc] == INF) cout << -1;
    else{
        cout << dist[tr][tc] << '\n';
        while(r!=sr or c!=sc){
            path.push_back({r,c});
            pair<int,int> previous = parent[r][c];
            r = previous.first;
            c = previous.second;
        }
        path.push_back({r,c});
        reverse(path.begin(),path.end());
        for(pair<int,int> i:path) cout << '(' << i.first << ',' << i.second << ") ";
    }
}