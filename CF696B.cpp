#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 100005
#define eps 1e-7
using namespace std;
int n;
vector<int>edges[N];
double ans[N];
int son[N];
void dfs1(int root) {
    son[root] = 1;
    for (int i = 0; i < edges[root].size(); ++i) {
        int cur = edges[root][i];
        dfs1(cur);
        son[root] += son[cur];
    }
}
void dfs2(int root) {
    for (int i = 0; i < edges[root].size(); ++i) {
        int cur = edges[root][i];
        ans[cur] = ans[root] + 1.0 + 0.5*(double)(son[root] - 1 - son[cur]);
        dfs2(cur);
    }
}
int main() {
    cin>>n;
    for (int i = 2; i <= n; ++i) {
        int p;
        cin>>p;
        edges[p].push_back(i);
    }
    ans[1] = 1.0;
    dfs1(1);
    dfs2(1);
    for (int i = 1; i <= n; ++i) {
        printf("%.7lf", ans[i]);
        if (i == n) cout<<endl;
        else cout<<" ";
    }
    return 0;
}
