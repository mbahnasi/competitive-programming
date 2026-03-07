#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*  اللهم اجعل هذا في سبيلك  */


void solve() {
    ll n, a, b;
    cin >> n >> a >> b ;
    ll x[n] ;
    for (auto & i : x) cin >> i ;
    ll ans[n] ;
    for (int i=0 ;i<n ;i++) {
        ll z = ((a*x[i]) % b) /a ;
        ans[i] = z;
    }
    for (auto i :ans) cout << i <<' ' ;
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
