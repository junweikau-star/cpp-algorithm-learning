#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<long long> ways(n+1);
    ways[0] = 1;
    ways[1] = 1;

    for(int i=2;i<=n;i++) ways[i] = ways[i-1] + ways[i-2];
    cout << ways[n];
}