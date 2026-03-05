#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*  اللهم اجعل هذا في سبيلك  */
const int N = 202, K = 1002, mod = 1e9+7 ;
int n, k ;
int dp[N][N][K], a[N] ; // dp (i, groups, imb) in how many ways you can reach i using k groups with imbalance imb


ll count(int i, int groups, ll imb) {
    if (imb > k) return 0 ;
    if (i == n) return groups == 0 ;
    int &ret = dp[i][groups][imb] ;
    if (~ret) return ret ;
    ret =0 ;
    if (groups == 0) imb = 0 ;
    if (i) imb += (a[i] - a[i-1])*groups ;
    // case 1 : open a new interval
    ret += count(i+1,groups +1, imb);
    // case 2 : take one element
    ret += count(i+1, groups, imb) ;
    // case 3: continue taking without new group:
    if (groups) ret += count(i+1,groups, imb)* groups;
    // case 4 : close a group
    if (groups) ret += count(i+1, groups-1, imb) ;
    // case 5 : close an existing then open a new one: this is a WRONG case as no student will be in 2 groups
    //if (groups) ret += count(i+1,groups, imb)*groups;
    ret %= mod;
    return ret ;
}

void solve() {
    cin >> n>> k ;
    for (int i =0 ;i<n ;i++) cin>> a[i] ;
    sort(a, a+n) ;
    // memset(dp, -1, sizeof dp) ;
    // cout << count(0, 0, 0) ;

    // iterative approach is preferred here
    dp[0][0][0] = 1 ;
    for (int i = 0 ;i<n ;i++)
        for (int groups = 0 ;groups <= n ;groups ++)
            for (int imb =0 ;imb <= k ;imb ++) {
                int newImb = imb ;
                if (i)newImb =imb +(a[i] - a[i-1]) * groups;
                ll me = dp[i][groups][imb];
                if (newImb > k) break;
                // case 1 : open
                    dp[i+1][groups+1][newImb] += me;
                    dp[i+1][groups+1][newImb] %=mod ;
                // case 2 : close an interval (it can be any open interval)
                if (groups) {
                    dp[i+1][groups-1][newImb] += me * groups % mod ;
                    dp[i+1][groups-1][newImb] %= mod ;
                }
                // case 3 : take current element in a single group
                dp[i+1][groups][newImb] += me ;
                dp[i+1][groups][newImb] %= mod ;

                // case 4 : take current without opening or closing
                dp[i+1][groups][newImb] += me * groups % mod  ; // it can be taken with any open group
                dp[i+1][groups][newImb] %=mod ;
            }

            int res = 0;
            for (int i =0 ;i<=k ;i++) {
                res+= dp[n][0][i]; res %= mod ;
            }
            cout <<res;
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
