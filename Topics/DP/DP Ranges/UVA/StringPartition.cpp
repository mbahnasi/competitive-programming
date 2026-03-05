#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*  اللهم اجعل هذا في سبيلك  */
ll dp[202] ;const int bound = INT_MAX ;
int n ;
string s;
ll get(int i) {
    if (i == n) return 0;
    ll & ret = dp[i] ;
    if (~ret) return ret ;
    int d = s[i] -'0' ;
    if (d == 0) {
        return ret = get(i+1) ;
    }
    ll cur =0  ;
    for (int j = i ;j<n &&cur <= bound ;j++) {
        d = s[j] -'0' ;
        cur = cur * 10 + d ;
        if (cur <= bound) ret = max(ret , get(j+1) + cur) ;
    }
    return ret ;

}


void solve() {

    cin >> s ;
    n = (int)s.size();
    memset(dp, -1, sizeof dp ) ;
    cout << get(0)<<'\n';

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
    cin >> tc ;
    while (tc--) solve();
}
