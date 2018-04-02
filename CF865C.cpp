#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#define N 52
#define M 5200
#define eps 1e-9
using namespace std;
int n, r;
int f[N], s[N], p[N];
double dp[N][M];
bool check(double expt) {
    for (int i = r + 1; i < M; ++i) {
        dp[n][i] = expt;
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j <= r; ++j) {
            double t1 = (dp[i + 1][j + f[i]] + (double)f[i]) * ((double)p[i] / 100.0);
            double t2 = (dp[i + 1][j + s[i]] + (double)s[i]) * (1.0 - (double)p[i] / 100.0);
            dp[i][j] = min(t1 + t2, expt);
        }
        for (int j = r + 1; j < M; ++j) {
            dp[i][j] = expt;
        }
    }
    return dp[0][0] < expt;
}
int main() {
    cin>>n>>r;
    double tot = 0.0;
    for (int i = 0; i < n; ++i) {
        cin>>f[i]>>s[i]>>p[i];
        tot += (double)s[i];
    }
    double ll = 0, rr = 1e10;
//    while(fabs(ll - rr) > eps) {
    for (int t = 1; t <= 100; ++t) {
        double mid = (ll + rr) * 0.5;
        if (check(mid)) rr = mid;
        else ll = mid;
    }
    printf("%.9lf\n", rr);
    return 0;
}
