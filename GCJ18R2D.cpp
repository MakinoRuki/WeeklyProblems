#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#define N 22
using namespace std;
int t, r, c;
bool vis[N][N];
bool mark[N][N];
vector<string> grid;
int ans, cnt;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void dfs(int i, int j) {
    if (vis[i][j]) return;
    cnt++;
    vis[i][j] = true;
    for (int d = 0; d < 4; ++d) {
        int ni = i + dx[d];
        int nj = j + dy[d];
        if (ni >= 0 && ni < r && nj >= 0 && nj < c && mark[ni][nj]) {
            dfs(ni, nj);
        }
    }
}
int solve() {
    memset(vis, false, sizeof(vis));
    int res = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (mark[i][j] && !vis[i][j]) {
                cnt = 0;
                dfs(i, j);
                res = max(res, cnt);
            }
        }
    }
    return res;
}
int main() {
    cin>>t;
    for (int cas = 1; cas <= t; ++cas) {
        cin>>r>>c;
        ans = 0;
        grid.clear();
        for (int i = 0; i < r; ++i) {
            string s;
            cin>>s;
            grid.push_back(s);
        }
        set<string> s1, s2, s3;
        s1.clear();
        s2.clear();
        s3.clear();
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                string ss;
                if (i + 1 < r && j + 1 < c) {
                    ss += grid[i].substr(j, 1) + grid[i].substr(j + 1, 1) + grid[i + 1].substr(j, 1) + grid[i + 1].substr(j + 1, 1);
                    s1.insert(ss);
                }
                ss.clear();
                if (i + 1 < r) {
                    ss += grid[i].substr(j, 1) + grid[i + 1].substr(j, 1);
                    s2.insert(ss);
                }
                ss.clear();
                if (j + 1 < c) {
                    ss += grid[i].substr(j, 1) + grid[i].substr(j + 1, 1);
                    s3.insert(ss);
                }
            }
        }
        ans = 0;
        memset(mark, false, sizeof(mark));
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == 'B') mark[i][j] = true;
            }
        }
        ans = max(ans, solve());
        memset(mark, false, sizeof(mark));
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == 'W') mark[i][j] = true;
            }
        }
        ans = max(ans, solve());
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (i + 1 < r && j + 1 < c) {
                    for (int cc = 0; cc < (1<<4); ++cc) {
                        string ss;
                        ss += ((cc & 1) ? 'B' : 'W');
                        ss += (((1<<1) & cc) ? 'B' : 'W');
                        ss += (((1<<2) & cc) ? 'B' : 'W');
                        ss += (((1<<3) & cc) ? 'B' : 'W');
                        if (s1.find(ss) != s1.end()) {
                            memset(mark, false, sizeof(mark));
                            for (int i1 = 0; i1 < r; ++i1) {
                                for (int j1 = 0; j1 < c; ++j1) {
                                    if (i1 <= i && j1 <= j && grid[i1][j1] == ss[0]) mark[i1][j1] = true;
                                    if (i1 <= i && j1 > j && grid[i1][j1] == ss[1]) mark[i1][j1] = true;
                                    if (i1 > i && j1 <= j && grid[i1][j1] == ss[2]) mark[i1][j1] = true;
                                    if (i1 > i && j1 > j && grid[i1][j1] == ss[3]) mark[i1][j1] = true;
                                }
                            }
                            ans = max(ans, solve());
                        }
                    }
                }
                if (i + 1 < r) {
                    for (int cc = 0; cc < (1<<2); ++cc) {
                        string ss;
                        ss += ((cc & 1) ? 'B' : 'W');
                        ss += (((1<<1) & cc) ? 'B' : 'W');
                        if (s2.find(ss) != s2.end()) {
                            memset(mark, false, sizeof(mark));
                            for (int i1 = 0; i1 < r; ++i1) {
                                for (int j1 = 0; j1 < c; ++j1) {
                                    if (i1 <= i && grid[i1][j1] == ss[0]) mark[i1][j1] = true;
                                    if (i1 > i && grid[i1][j1] == ss[1]) mark[i1][j1] = true;
                                }
                            }
                            ans = max(ans, solve());
                        }
                    }
                }
                if (j + 1 < c) {
                    for (int cc = 0; cc < (1<<2); ++cc) {
                        string ss;
                        ss += ((cc & 1) ? 'B' : 'W');
                        ss += (((1<<1) & cc) ? 'B' : 'W');
                        if (s3.find(ss) != s3.end()) {
                            memset(mark, false, sizeof(mark));
                            for (int i1 = 0; i1 < r; ++i1) {
                                for (int j1 = 0; j1 < c; ++j1) {
                                    if (j1 <= j && grid[i1][j1] == ss[0]) mark[i1][j1] = true;
                                    if (j1 > j && grid[i1][j1] == ss[1]) mark[i1][j1] = true;
                                }
                            }
                            ans = max(ans, solve());
                        }
                    }
                }
            }
        }
        cout<<"Case #"<<cas<<": "<<ans<<endl;
    }
    return 0;
}
