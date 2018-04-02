#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 100005
#define eps 1e-6
using namespace std;
int n;
double pr[N];
double dp[N];
int main() {
    cin>>n;
    double ans = 0.0;
    for (int i = 0; i < n; ++i) {
        cin>>pr[i];
        ans += pr[i];
    }
    dp[0] = 0.0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] * pr[i - 1];
        ans += dp[i] * 2.0;
        dp[i] += pr[i - 1];
    }
    printf("%.7lf\n", ans);
    return 0;
}
