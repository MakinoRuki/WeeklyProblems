#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 150005
using namespace std;
int T, s;
vector<int> d, a, b;
int dp1[N][2], dp2[N][2];
int main() {
    cin>>T;
    for (int cas = 1; cas <= T; ++cas) {
        d.clear();
        a.clear();
        b.clear();
        memset(dp1, 0, sizeof(dp1));
        memset(dp2, 0, sizeof(dp2));
        cin>>s;
        for (int i = 0; i < s; ++i) {
            int dx, ax, bx;
            cin>>dx>>ax>>bx;
            d.push_back(dx);
            a.push_back(ax);
            b.push_back(bx);
        }
        for (int i = s - 1; i >= 0; --i) {
            dp1[i][0] = i;
            if (i < s - 1 && d[i] + a[i] == d[i + 1] + a[i + 1]) {
                dp1[i][0] = max(dp1[i][0], dp1[i + 1][0]);
            }
            dp1[i][1] = i;
            if (i < s - 1 && d[i] - b[i] == d[i + 1] - b[i + 1]) {
                dp1[i][1] = max(dp1[i][1], dp1[i + 1][1]);
            }
        }
        for (int i = s - 1; i >= 0; --i) {
            int a1 = dp1[i][0];
            dp2[i][0] = max(dp2[i][0], dp1[i][0]);
            if (a1 < s - 1) {
                int b1 = dp1[a1 + 1][1];
                dp2[i][0] = max(dp2[i][0], b1);
                if (b1 < s - 1) {
                    if (d[b1 + 1] + a[b1 + 1] == d[i] + a[i]) {
                        int a2 = dp1[b1 + 1][0];
                        dp2[i][0] = max(dp2[i][0], a2);
                        if (a2 < s - 1) {
                            if (d[a2 + 1] - b[a2 + 1] == d[a1 + 1] - b[a1 + 1]) {
                                dp2[i][0] = max(dp2[i][0], dp2[b1 + 1][0]);
                            }
                        }
                    }
                }
            }
            int b1 = dp1[i][1];
            dp2[i][1] = max(dp2[i][1], dp1[i][1]);
            if (b1 < s - 1) {
                int a1 = dp1[b1 + 1][0];
                dp2[i][1] = max(dp2[i][1], a1);
                if (a1 < s - 1) {
                    if (d[a1 + 1] - b[a1 + 1] == d[i] - b[i]) {
                        int b2 = dp1[a1 + 1][1];
                        dp2[i][1] = max(dp2[i][1], b2);
                        if (b2 < s - 1) {
                            if (d[b2 + 1] + a[b2 + 1] == d[b1 + 1] + a[b1 + 1]) {
                                dp2[i][1] = max(dp2[i][1], dp2[a1 + 1][1]);
                            }
                        }
                    }
                }
            }
        }
        int ans = 0, cnt = 0;
        for (int i = 0; i < s; ++i) {
            ans = max(ans, max(dp2[i][0], dp2[i][1]) - i + 1);
        }
        for (int i = 0; i < s; ++i) {
            if (dp2[i][0] - i + 1 == ans || dp2[i][1] - i + 1 == ans) {
                cnt++;
            }
        }
        cout<<"Case #"<<cas<<": "<<ans<<" "<<cnt<<endl;
    }
    return 0;
}
