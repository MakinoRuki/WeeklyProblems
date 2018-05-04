#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int t, n, l;
vector<string> words;
bool valid[12][30];
int main() {
    cin>>t;
    for (int cas = 1; cas <= t; ++cas) {
        cin>>n>>l;
        set<string> pres;
        pres.clear();
        words.clear();
        memset(valid, false, sizeof(valid));
        for (int i = 0; i < n; ++i) {
            string s;
            cin>>s;
            words.push_back(s);
            for (int j = 1; j <= l; ++j) {
                pres.insert(s.substr(0, j));
                valid[j - 1][s[j - 1] - 'A'] = true;
            }
        }
        string ans = "-";
        for (int i = 0; i < n; ++i) {
            int j;
            string ts;
            for (j = 0; j < l; ++j) {
                ts = words[i].substr(0, j);
                ts += " ";
                int k;
                for (k = 0; k < 26; ++k) {
                    if (!valid[j][k]) continue;
                    ts[ts.size() - 1] = 'A' + k;
                    if (pres.find(ts) == pres.end()) {
                        break;
                    }
                }
                if (k < 26) break;
            }
            if (j < l) {
                ans = ts + words[i].substr(j + 1, l - j - 1);
                break;
            }
        }
        cout<<"Case #"<<cas<<": "<<ans<<endl;
    }
    return 0;
}
