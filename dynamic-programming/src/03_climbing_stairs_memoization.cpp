#include <bits/stdc++.h>
using namespace std;

vector<long long> memo;

long long solve(int x){
    if(x == 0 || x == 1) return 1;
    if(memo[x] != -1) return memo[x];
    memo[x] = solve(x-1) + solve(x-2);
    return memo[x];
}

int main(){
    int n;
    cin >> n;
    memo.resize(n+1,-1);
    cout << solve(n);
}