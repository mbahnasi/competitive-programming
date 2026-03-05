#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*  اللهم اجعل هذا في سبيلك  */
const int N = 2002, M = 2002, mod = 1e9 + 7 ;
ll dp[N][M] ; // for dp(i, open) it means in how many ways you can achieve the needed until i
// using (open) intervals
int n, h , a[N];

ll count(int i, int open) {
    if (i == n) return open==0 ;
    if (a[i] + open > h || a[i] + open +1 < h) return 0 ;
    ll & ret = dp[i][open] ;
    if (~ret) return ret ;
    ret =0 ;
    // case 1 : start an interval from i, if it possible to achieve the h with this open
    if (a[i] + open + 1 == h)ret +=  count(i+1, open+1);
    // case 2 : close an interval at i
    if (open && a[i] + open == h) ret += count(i+1, open-1)*open ;
    // case 3 : continue in current interval (open or closed)
    if (a[i] + open == h) ret += count(i+1, open) ;
    // case 4 : open a new interval then close it (take one element)
    if (a[i] + open + 1 == h) ret += count(i+1, open);
    // case 5 : close an old interval at i the open a new interval starting from i
    if (open && a[i] + open +1 == h) ret +=  count (i+1, open) * open ;
    ret %= mod ;
    return ret  ;
}

void solve() {
    cin>> n>> h;
    for (int i =0 ;i<n;i++)cin>> a[i] ;
    memset(dp, -1, sizeof dp) ;
    cout << count(0, 0);

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
