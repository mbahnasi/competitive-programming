#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*  اللهم اجعل هذا في سبيلك  */
const int N = 2e3 +3 ;
int dp[N][N];
int n, v[N];


int rec(int i, int j, int day) {
    if (i > j) return 0 ;
    int &ret = dp[i][j];
    if (~ret) return ret ;
    int c1 = v[i] * day +rec(i+1, j, day+1) ;
    int c2 = v[j]*day + rec(i, j-1, day+1) ;
    return ret =max(c1, c2) ;
}
void solve() {
    cin >> n ;
    for (int i=0  ;i<n ;i++) cin>> v[i] ;
    memset(dp, -1, sizeof dp) ;
    cout << rec(0, n-1, 1) ;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w",stdout);
#endif
    int tc;
   
    tc = 1;
    while (tc--) solve();
}
