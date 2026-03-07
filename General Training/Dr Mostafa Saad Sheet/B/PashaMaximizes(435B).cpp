#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*  اللهم اجعل هذا في سبيلك  */

void solve() {
    string s; int k;
    cin>> s >> k ;
    multiset<int> cur ;
    if (k == 0) {
        cout << s ; return ;
    }
    int n = s.size();
    for (int i =0 ;i<n; i++) {
        int mx = -1, idx =i ;
        for (int j =i ; j<= min(i+k, n-1) ;j++) {
            if (s[j] - '0' > mx){
                mx = max(s[j]-'0', mx);
                idx =j;
            }
        }
        if (idx != i) {
            for (int j = idx ;j>i ;j--) {
                swap(s[j], s[j-1]) ;
                k-- ;
                if (!k) {
                    cout << s ; return ;
                }
            }
        }
    }
    cout << s ;
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
