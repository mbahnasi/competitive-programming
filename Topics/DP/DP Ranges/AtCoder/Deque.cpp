#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*  اللهم اجعل هذا في سبيلك  */
const int N = 3e3 +3 ;
ll dp[N][N][2] ; // who =0 -- > first is playing
ll n, arr[N], neg[N] ;
bool vis[N][N][2] ;

ll rec(int i, int j, bool who) {
    if (i > j)return 0 ;
    ll &ret = dp[i][j][who] ;
    if (vis[i][j][who]) return ret ;
    vis[i][j][who] =1 ;
    ret = -1e18 ;
    if (who == 0) {
        return ret = max(arr[i] + rec(i+1, j, 1), arr[j]+rec(i, j-1,1 )) ;
    }
    return ret = min(neg[i]+rec(i+1, j, 0), neg[j]+rec(i, j-1, 0));
}
void solve() {
    cin >> n ;
    for (int i=0  ;i<n ;i++) {
        cin>> arr[i] ;
        neg[i] = -arr[i] ;
    }
    cout << rec(0, n-1, 0) ;
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
    //cin >> tc ;
    tc = 1;
    while (tc--) solve();
}