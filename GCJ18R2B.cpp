#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 35
#define M 505
using namespace std;
int t, r, b;
int dp[N][M][M];
int main() {
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i * (i + 1) / 2 <= 500; ++i) {
        dp[0][0][i * (i + 1) / 2] = i;
    }
    for (int i = 1; i * (i + 1) / 2 <= 500; ++i) {
        for (int ri = 0; ri <= 500; ++ri) {
            for (int bi = 0; bi <= 500; ++bi) {
                for (int j = 0; j * (j + 1) / 2 <= 500; ++j) {
                    int nbj = bi - i * (j + 1);
                    int nrj = ri - j * (j + 1) / 2;
                    if (nbj >= 0 && nrj >= 0 && dp[i - 1][nbj][nrj] >= 0) {
                        dp[i][bi][ri] = max(dp[i][bi][ri], dp[i - 1][nbj][nrj] + j + 1);
                    }
                }
            }
        }
    }
    cin>>t;
    for (int cas = 1; cas <= t; ++cas) {
        cin>>r>>b;
        int ans = 0;
        for (int i = 0; i * (i + 1) / 2 <= max(r, b); ++i) {
            for (int ri = r; ri >= 0; --ri) {
                for (int bi = b; bi >= 0; --bi) {
                    if (dp[i][bi][ri] >= 0) {
                        ans = max(ans, dp[i][bi][ri]);
                    }
                    if (dp[i][ri][bi] >= 0) {
                        ans = max(ans, dp[i][ri][bi]);
                    }
                }
            }
        }
        cout<<"Case #"<<cas<<": "<<ans<<endl;
    }
    return 0;
}
