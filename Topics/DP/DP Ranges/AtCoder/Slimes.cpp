#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*  اللهم اجعل هذا في سبيلك  */
const int N = 403 ;
ll dp[N][N] ;
ll a[N] ,n ;
ll mn(int l, int r) {
    if (l >= r) return 0;
    ll &ret = dp[l][r] ;
    if (~ret) return ret ;
    ret = 1e18 ;
    for (int i = l ; i<r ;i++) {
        ret = min(ret, a[r] - (l==0 ? 0 : a[l-1]) + mn(l, i)+ mn(i+1, r))  ;
    }
    return ret ;
}

void solve() {
    cin >> n ;
    for (int i =0 ;i<n ;i++)cin>> a[i] ;
    for (int i = 1 ;i<n ;i++) a[i] += a[i-1] ;
    memset(dp , -1, sizeof dp) ;
    cout << mn(0, n-1) ;
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