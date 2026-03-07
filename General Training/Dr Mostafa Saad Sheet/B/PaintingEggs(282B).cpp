#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*  اللهم اجعل هذا في سبيلك  */

void solve() {
    int n ;cin >> n ;
    int a[n], b[n] ;
    string ans ;
    int s1 =0 , s2 =0 ;
    int idx[n];
    for (int i =0 ;i<n ;i++)cin >> a[i] >> b[i] ;
    iota(idx, idx+n, 0) ;
    sort(idx, idx+n, [&](int i, int j) {
        return abs(a[i] - b[i]) < abs(a[j] - b[j]) ;
    });
    int c =0 ;
    for (int i =0 ;i<n ;i++) {
            if (abs(s1 + a[idx[i]] -s2) <= 500) {
                c++ , ans +='A', s1 += a[idx[i]] ;
            }
            else if (abs(s2 + b[idx[i]] - s1) <= 500 ) {
                c++, ans +='G', s2 += b[idx[i]];
            }
            else break;
    }
    if (c == n) {
        cout << ans ; return ;
    }
    c =0 ;ans ="", s1 =0 , s2 =0;
    for (int i =0 ;i<n ;i++) {
        if (abs(s2 + b[idx[i]] - s1) <= 500 ) {
            c++, ans +='G', s2 += b[idx[i]];
        }
        else if (abs(s1 + a[idx[i]] -s2) <= 500) {
            c++ , ans +='A', s1 += a[idx[i]] ;
        }
        else break;
    }
    if (c == n) {
        cout << ans ; return ;
    }
    cout << -1 ;
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
