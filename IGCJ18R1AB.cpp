#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#define N 102
#define M 252
#define eps 1e-6
using namespace std;
int T, n;
int W[N], H[N];
double dp[2][N*M*2];
double p;
int maxv;
int main() {
    cin>>T;
    for (int cas = 1; cas <= T; ++cas) {
        cin>>n>>p;
        int tot = 0;
        double res = 0.0;
        for (int i = 0; i < n; ++i) {
            cin>>W[i]>>H[i];
            tot += 2 * max(W[i], H[i]);
            res += 2.0 * (double)(W[i] + H[i]);
        }
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            int now = (i & 1);
            for (int j = 0; j <= tot; ++j) {
                dp[now][j] = dp[now ^ 1][j];
                int delta = 2 * min(W[i - 1], H[i - 1]);
                double add = 2.0 * (double)sqrt(W[i - 1] * W[i - 1] + H[i - 1] * H[i - 1]);
                if (j >= delta) {
                    dp[now][j] = max(dp[now][j], dp[now ^ 1][j - delta] + add);
                }
            }
        }
        double ans = res;
        for (int j = 0; j <= tot; ++j) {
            if (res + dp[n & 1][j] <= p) {
                ans = res + (double)dp[n & 1][j];
            } else if (res + (double)j <= p) {
                ans = p;
                break;
            } else {
                ans = p;
                break;
            }
        }
        printf("Case #%d: %.7lf\n", cas, ans);
    }
    return 0;
}
