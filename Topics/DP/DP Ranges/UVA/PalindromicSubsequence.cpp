#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*  اللهم اجعل هذا في سبيلك  */
const int N = 1e3 +3 ;
int dp[N][N];
string s ;

int rec(int i, int j) {
    if (i > j) return 0 ;
    if (i== j) return 1 ;
    int &ret = dp[i][j] ;
    if (~ret) return ret ;
    ret = 0 ;
    if (s[i] == s[j]) {
        ret = 2 + rec(i+1, j-1) ;
    }
    else {
        ret = max( rec(i+1, j) ,rec(i, j-1)) ;
    }
    return ret ;
}
string mem[N][N];
bool vis[N][N] ;

string build(int i, int j) {
    if (i>j) return"";
    if (i==j) {
        return mem[i][j] = s.substr(i, 1) ;
    }
    int ans = dp[i][j] ;
    if (vis[i][j]) return mem[i][j] ;
    vis[i][j] = 1 ;
    string x = "~";
    if (s[i] == s[j] && ans == 2 + rec(i+1,j-1)) {
        x =min(x ,  s.substr(i, 1) +build(i+1, j-1) + s.substr(j, 1)) ;
    }
    else {
        if (rec(i, j-1) == ans) {
            x = min(x, build(i, j-1)) ;
        }
        if (rec(i+1, j) == ans) {
            x = min(x, build(i+1, j)) ;
        }
    }
    return mem[i][j] = x ;
}
void solve() {
    memset(dp, -1, sizeof dp) ;
    memset(vis, 0, sizeof(vis)) ;
    int n = (int)s.size() ;
    rec(0, n-1)  ;
    cout <<  build(0, n-1)<<'\n' ;

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
    while (cin >>s ) {
        solve();
    }
}