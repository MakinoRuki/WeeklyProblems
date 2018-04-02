#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#define eps 1e-6
using namespace std;
string s;
int n;
int maxv[26];
int main() {
    cin>>s;
    n = s.size();
    memset(maxv, 0, sizeof(maxv));
    for (int i = 0; i < n; ++i) {
        int cnt[900];
        memset(cnt, 0, sizeof(cnt));
        for (int j = 0; j < n; ++j) {
            int c1 = s[j] - 'a';
            int c2 = s[(j + i) % n] - 'a';
            cnt[c1 * 26 + c2]++;
        }
        vector<int> sum(26, 0);
        for (int j = 0; j < n; ++j) {
            int c1 = s[j] - 'a';
            int c2 = s[(j + i) % n] - 'a';
            if (cnt[c1 * 26 + c2] == 1) {
                sum[s[j] - 'a']++;
            }
        }
        for (int i = 0; i < 26; ++i) {
            maxv[i] = max(maxv[i], sum[i]);
        }
    }
    int sum = 0;
    for (int i = 0; i < 26; ++i) {
        sum += maxv[i];
    }
    double ans = (double)sum / (double)n;
    printf("%7lf\n", ans);
    return 0;
}
