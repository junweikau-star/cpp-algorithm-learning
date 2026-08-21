#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    long long current,prev1=1,prev2=1;

    for(int i=2;i<=n;i++){
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    cout << prev1;
}