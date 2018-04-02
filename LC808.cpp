double dp[5005][5005];
class Solution {
public:
    double soupServings(int N) {
        if ((N + 24) / 25 > 200) return 1.0;
        dp[0][0] = 0.5;
        for (int i = 1; i <= N; ++i) {
            dp[0][i] = 1.0;
            dp[i][0] = 0.0;
        }
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                dp[i][j] = dp[max(i - 100, 0)][j] * 0.25;
                dp[i][j] += dp[max(i - 75, 0)][max(j - 25, 0)] * 0.25;
                dp[i][j] += dp[max(i - 25, 0)][max(j - 75, 0)] * 0.25;
                dp[i][j] += dp[max(i - 50, 0)][max(j - 50, 0)] * 0.25;
            }
        }
        return dp[N][N];
    }
};
