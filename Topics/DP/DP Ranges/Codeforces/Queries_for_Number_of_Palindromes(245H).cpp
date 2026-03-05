#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*  اللهم اجعل هذا في سبيلك  */
const int N = 5005;
bool vis[N][N] ;
ll dp[N][N] ;
string s ;

bool rec(int l, int r) {
    // base
    if (l == r) return dp [l][r] = 1 ;
    if (l >r) return dp[l][r] =0 ;
    if (vis[l][r]) return dp[l][r] ;
    vis[l][r] = 1 ;
    ll &ret = dp[l][r] ;
    if (s[l] == s[r]) {
        if (l == r-1) ret = 1 ; // me and my next make a palindrome
        else ret = rec(l+1, r-1) ; // I am a palindrome if inner is a palindrome
    }
    rec(l, r-1) ; // check all possible substrings
    rec(l+1, r) ;
    return ret ;
}

void solve() {
    cin>> s ;
    s = '~' +s ;
    memset(dp, 0, sizeof dp) ;
    int n = (int)s.size();
    rec(1, n-1);


    for (int i = 1 ;i<n;i++) { // 2d prefix sum
        for (int j = 1 ;j<n ;j++) {
            dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] ;
        }
    }

    int q; cin>> q;
    while (q--) {
        int l, r ;cin >> l>>r ;
        cout << dp[r][r] - dp[l-1][r] - dp[r][l-1] + dp[l-1][l-1] << '\n';
    }
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
    // cin >> tc ;
    while (tc--) solve();
}