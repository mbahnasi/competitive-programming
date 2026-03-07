#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*  اللهم اجعل هذا في سبيلك  */

void solve() {
    int n ;cin >> n;
    string a [n];
    for (auto &  i  :a ) {
        cin >> i ;
        if (i=="0") {
            cout << 0 ;
            return ;
        }
    }
    auto f =[&](string x) {
        string s = x ;
        int z =0 ;
        int i =0;
        for ( ;i<s.size() ;i++) {
            if (s[i] =='1') {i ++ ; break;}
        }
        for (;i<s.size();i++) if (s[i] =='0') z++ ;
        return z ;
    };
    auto ch = [&](string x) {
        string s = x ;
        string num;
        for (auto i : s) {
            if (i!= '0') num += i;
        }
        if (num != "1") return 0 ;
        return -1 ;
    };
    ll z =0 ;
    string single ="1" ;
    for (auto & i:a) {
        if (ch(i) != -1) single = i ;
        else {
            z += f(i);
        }
    }
    string ans = single;
    while (z--) ans += '0' ;
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
