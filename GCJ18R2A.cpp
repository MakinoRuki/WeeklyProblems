#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 200
using namespace std;
int t, c;
int b[N];
int main() {
    cin>>t;
    for (int cas = 1; cas <= t; ++cas) {
        cin>>c;
        for (int i = 0; i < c; ++i) {
            cin>>b[i];
        }
        vector<string> ans;
        ans.clear();
        bool ok = true;
        for (int i = 0; i < c; ++i) {
            int j;
            for (j = 0; j < c; ++j) {
                if (b[j] > 0) break;
            }
            if (i == 0 && j != 0) {
                ok = false;
                break;
            }
            if (i == c - 1 && j != c - 1) {
                ok = false;
                break;
            }
            if (j < i) {
                int row = 0;
                for (int k = i; k > j; --k) {
                    if (row >= ans.size()) {
                        string ss(c, '.');
                        ans.push_back(ss);
                    }
                    ans[row][k] = '/';
                    row++;
                }
            } else if (j > i) {
                int row = 0;
                for (int k = i; k < j; ++k) {
                    if (row >= ans.size()) {
                        string ss(c, '.');
                        ans.push_back(ss);
                    }
                    ans[row][k] = '\\';
                    row++;
                }
            }
            b[j]--;
        }
        if (!ok) {
            cout<<"Case #"<<cas<<": IMPOSSIBLE"<<endl;
        } else {
            string ss(c, '.');
            ans.push_back(ss);
            cout<<"Case #"<<cas<<": "<<ans.size()<<endl;
            for (int i = 0; i < ans.size(); ++i) {
                for (int j = 0; j < c; ++j) {
                    cout<<ans[i][j];
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
