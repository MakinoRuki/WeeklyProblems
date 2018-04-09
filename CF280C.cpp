#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 100005
using namespace std;
int n;
vector<int> edges[N];
double ans;
void dfs(int u, int p, int d) {
    ans += 1.0 / (double)d;
    for (int i = 0; i < edges[u].size(); ++i) {
        if (edges[u][i] == p) continue;
        dfs(edges[u][i], u, d + 1);
    }
}
int main() {
    cin>>n;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    ans = 0;
    dfs(1, 0, 1);
    printf("%.7lf\n", ans);
    return 0;
}
