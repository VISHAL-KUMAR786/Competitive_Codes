#include "bits/stdc++.h"
using namespace std;

#define int        long long int
#define now(x)     cout<<#x<<" : "<<x<<endl;

int MOD = 1e9 + 7;

void solve(){
    int n,m; cin>>n>>m;

    vector<vector<int>> dp(n, vector<int> (m)), prefix(n+1, vector<int> (m+1,0));
    for(auto &arr : dp) for(auto &i : arr) cin>>i;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            prefix[i][j] = dp[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }

    /*

    for(auto arr : dp){ for(auto i : arr) cout<<i<<" "; cout<<endl;}
    for(auto arr : prefix){ for(auto i : arr) cout<<i<<" "; cout<<endl;}

    dp
        1 0 4 0
        0 2 0 3
        0 2 0 3
        1 0 4 0
    prefix
        0 0 0 0 0 
        0 1 1 5 5 
        0 1 3 7 10 
        0 1 5 9 15 
        0 2 6 14 20
    want sum of this sub_matrix
        1 0 4 
        0 2 0 
        0 2 0 

    i = 1, j = 1;
    i_low = 0, j_low = 0;
    i_high = 3, j_high = 3;

    */


    int maxRooms = 0, mid = -1;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(dp[i][j] == 0) continue;

            int i_low = max(i - mid, 0ll);
            int i_high = min(i + mid + 1, n);
            int j_low = max(j - mid, 0ll);
            int j_high = min(j + mid + 1, m);

            int tmp = prefix[i_high][j_high] - prefix[i_low][j_high] - prefix[i_high][j_low] + prefix[i_low][j_low];

            maxRooms = max(maxRooms, tmp);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    cin >> t;  
    while (t--) solve();
    return 0;
} 