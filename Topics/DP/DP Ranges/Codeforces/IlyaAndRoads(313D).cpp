#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*  اللهم اجعل هذا في سبيلك  */
const int N = 303 , M = 1e5+5 ;
ll cost[N][N] ;
int n, k, m ;
ll dp[N][N] ;
// dp (i, j) gives us the minimum needed cost to achieve j fixed holes at index i

ll get(int i, int cur) {
    if (cur >= k) return 0;
    if (i==n) {
        return 1e18 ;
    }
    ll &ret = dp[i][cur] ;
    if (~ret) return ret ;
    ret = 1e18 ;
    // leave :
    ret = min(ret,  get(i+1,cur)) ;
    // try every possible take from i to md :  
    for (int md = i ;md < n ;md ++) {
        ret = min(ret, cost[i][md] + get(md+1,cur +(md-i+1)));
    }
    return ret ;
}
void solve() {
    cin >> n>> m>> k ;
    for (int i =0 ;i<n;i++)
        for (int j =0 ;j<n ;j++) cost[i][j] = 1e18 ;

    for (int i=0 ;i<m ;i++) {
        int l, r, c ;cin>> l>> r>> c ;
        l--, r-- ;
        cost[l][r] = min(cost[l][r] ,c*1LL) ;
    }

    
    for (int j =0 ; j<n ;j++) {
        for (int i =1 ;i<=j ;i++) {
            // let cost from i to j be X ,and (i-1) to j be Y
            // if Y is smaller than X ,it would be better to fix from (i-1) to (j) even if I am fixing from i to j 
            cost[i][j] = min(cost[i-1][j], cost[i][j] );
        }
    }
    memset(dp, -1, sizeof dp) ;
    ll ans = get(0,0);
    if (ans >= 1e18) ans =-1 ;
    cout << ans ;

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
