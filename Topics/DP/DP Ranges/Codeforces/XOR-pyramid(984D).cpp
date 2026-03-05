#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*  اللهم اجعل هذا في سبيلك  */
const int N = 5005 ;
int n, a[N], dp[N][N], mem[N][N] ;

int pre(int l , int r) {
    if (l == r) return a[l] ;
    if (l+1== r) return a[l] ^ a[r] ;
    if (l+2 == r) {
        return mem[l][r] = a[l] ^ a[r] ;
    }
    int &ret = mem[l][r] ;
    if (~ret) return ret ;
    ret = pre(l, r-1) ^ pre(l+1, r) ;
    return ret ;
}
int get(int l,int  r) {
    if (l == r) return a[l] ;
    int&ret = dp[l][r] ;
    if (~ret) return ret ;
    ret = max({pre(l, r), get(l, r-1), get(l+1, r)}) ;
    return  ret ;
}
void solve() {
    cin>>  n ;
    for (int i =0 ;i<n ;i++) cin>> a[i] ;
    memset(dp, -1,sizeof dp) ;
    memset(mem, -1 , sizeof mem) ;
    for (int i =0 ;i<n ;i++)
        for (int j =i ;j<n ;j++) pre(i, j) ;
    // cout <<pre(2, 5) << '\n' ;
    int q;cin>> q;
    while (q--) {
        int l, r ;cin >> l>> r ;
         l-- , r-- ;
        cout << get(l, r) <<'\n' ;
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