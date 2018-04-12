#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 100005
using namespace std;
typedef long long ll;
int T, n, l;
vector<int> c;
int rdn[N];
int main() {
    cin>>T;
    for (int cas = 1; cas <= T; ++cas) {
        cin>>n>>l;
        int del = 0;
        for (int i = n; i >= 0; --i) {
            int x = i * 1000 / n;
            if (i > 0 && ((i * 100 % n) == 0 || x % 10 >= 5)) {
                rdn[i] = i;
            } else {
                rdn[i] = rdn[i + 1];
            }
        }
        vector<pair<int, int> > rks;
        rks.clear();
        c.clear();
        for (int i = 0; i < l; ++i) {
            int cc;
            cin>>cc;
            c.push_back(cc);
            if (rdn[cc] > cc) {
                rks.push_back(make_pair(rdn[cc] - cc, i));
            }
            del += cc;
        }
        del = n - del;
        sort(rks.begin(), rks.end());
        for (int i = 0; i < rks.size(); ++i) {
            int d = rks[i].first;
            int idx = rks[i].second;
            if (del < d) break;
            if (d < rdn[0]) {
                c[idx] += d;
                del -= d;
            } else {
                break;
            }
        }
        int ans = 0;
        while(true) {
            if (del >= rdn[0]) {
                ans += rdn[0] * 100 / n;
                if ((rdn[0] * 1000 / n) % 10 >= 5) ans++;
                del -= rdn[0];
            } else {
                ans += del * 100 / n;
                if ((del * 1000 / n) % 10 >= 5) ans++;
                break;
            }
        }
        for (int i = 0; i < l; ++i) {
            ans += c[i] * 100 / n;
            if ((c[i] * 1000 / n) % 10 >= 5) ans++;
        }
        cout<<"Case #"<<cas<<": "<<ans<<endl;
    }
    return 0;
}


