#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*  اللهم اجعل هذا في سبيلك  */

void solve() {
    int n, m; cin>> n>> m ;
    bool a[n][m] ;
    bool b[n][m] ;
    for (int i =0 ;i<n ;i++) for (int j =0 ;j<m ;j++) cin >> a[i][j] ;

    for (int i =0 ;i<n ;i++) {
        for (int j =0 ;j<m ;j++) {
            if (a[i][j] == 0) b[i][j] =0 ;
            else {
                bool a1 =1 , a2 =1 ;
                for (int x = 0 ;x < n; x++) {
                    if (x == i) continue;
                    a1 &= a[x][j] ;
                }
                if (m == 1) a1 = a[i][j] ;
                for (int y = 0 ;y<m ;y++) {
                    if (y == j) continue;
                    a2 &= a[i][y] ;
                }
                if (n == 1) a2 = a[i][j];
                if (!a1 && !a2 ) {
                    cout << "NO";
                    return ;
                }
                if (a1 && a2) b[i][j] =1 ;
                else b[i][j] = 0 ;
            }
        }
    }
    for (int i =0 ;i<n ;i++) {
        for (int j =0 ;j <m ;j++) {
            bool a1 =0 ;
            for (int x = 0 ;x < n; x++) {
                a1 |= b[x][j] ;
            }
            bool a2 =0 ;
            for (int y = 0 ;y<m ;y++) {
                a2 |= b[i][y] ;
            }
            if ((a1 | a2) != a[i][j]) {
                cout << "NO" ;
                return ;
            }
        }
    }
    cout << "YES\n" ;
    for (int i =0 ;i<n ;i++) {
        for (int j =0 ;j<m ;j++) cout <<b[i][j] <<" ";
        cout << '\n' ;
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
    //cin >> tc ;
    tc = 1;
    while (tc--) solve();
}
