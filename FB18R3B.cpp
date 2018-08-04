#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 200005
#define M 1000005
#define pii pair<int, int>
#define mp make_pair
using namespace std;
typedef long long ll;
int c[M];
vector<int> edges[N];
int t, n, m, a, b;
struct node {
	int v;
	int l, r;
	int midx;
} tree[4 * M];
int s[N], e[N];
int cnt;
int lev[N];
int val[N];
void build(int root, int begin, int end) {
	tree[root].l = begin;
	tree[root].r = end;
	if (begin == end) {
		tree[root].v = val[begin];
		tree[root].midx = begin;
		return;
	}
	int mid = (begin + end) / 2;
	build(root * 2, begin, mid);
	build(root * 2 + 1, mid + 1, end);
	if (tree[root * 2].v > tree[root * 2 + 1].v) {
		tree[root].v = tree[root * 2].v;
		tree[root].midx = tree[root * 2].midx;
	} else {
		tree[root].v = tree[root * 2 + 1].v;
		tree[root].midx = tree[root * 2 + 1].midx;
	}
}
int getval (int root, int begin, int end) {
	int l = tree[root].l;
	int r = tree[root].r;
	if (l == r) return tree[root].midx;
	if (begin == l && end == r) {
		return tree[root].midx;
	}
	int mid = (l + r) / 2;
	if (end <= mid) return getval(root * 2, begin, end);
	else if (begin > mid) return getval(root * 2 + 1, begin, end);
	else {
		int lidx = getval(root * 2, begin, mid);
		int ridx = getval(root * 2 + 1, mid + 1, end);
		if (val[lidx] > val[ridx]) {
			return lidx;
		} else {
			return ridx;
		}
	}
	return 0;
}
void modify(int root, int idx, int v) {
	int l = tree[root].l;
	int r = tree[root].r;
	if (l == r) {
		val[idx] = 0;
		tree[root].v = 0;
		return;
	}
	int mid = (l + r) / 2;
	if (idx <= mid) {
		modify(root * 2, idx, v);
	} else {
		modify(root * 2 + 1, idx, v);
	}
	if (tree[root * 2].v < tree[root * 2 + 1].v) {
		tree[root].v = tree[root * 2 + 1].v;
		tree[root].midx = tree[root * 2 + 1].midx;
	} else {
		tree[root].v = tree[root * 2].v;
		tree[root].midx = tree[root * 2].midx;
	}
}
void dfs(int cur, int l) {
	lev[cur] = l;
	s[cur] = cnt;
	cnt++;
	for (int i = 0; i < edges[cur].size(); ++i) {
		dfs(edges[cur][i], l + 1);
	}
	e[cur] = cnt;
}
int main() {
	freopen("jacks_candy_shop.txt","r", stdin);
	freopen("bout.txt", "w", stdout);
	cin>>t;
	for (int cas = 1; cas <= t; ++cas) {
		cin>>n>>m>>a>>b;
		for (int i = 0; i < n; ++i) {
			edges[i].clear();
		}
		for (int i = 1; i < n; ++i) {
			int p;
			cin>>p;
			edges[p].push_back(i);
		}
		for (int i = 0; i < m; ++i) {
			c[i] = ((ll)a * (ll)i + (ll)b) % n;
		}
		cnt = 0;
		dfs(0, 0);
		// for (int i = 0; i < n; ++i) {
		// 	cout<<i<<" "<<s[i]<<" "<<e[i]<<endl;
		// }
		for (int i = 0; i < n; ++i) {
			val[s[i]] = i;
		}
		build(1, 0, cnt - 1);
		vector<pii> tmp;
		tmp.clear();
		for (int i = 0; i < m; ++i) {
			tmp.push_back(mp(lev[c[i]], i));
		}
		sort(tmp.begin(), tmp.end());
		ll sum = 0;
		for (int i = tmp.size() - 1; i >= 0; --i) {
			int idx = tmp[i].second;
			int l = s[c[idx]], r = e[c[idx]];
			//cout<<idx<<" "<<l<<" "<<r<<endl;
			int midx = getval(1, l, r - 1);
			sum += val[midx];
			modify(1, midx, 0);
		}
		cout<<"Case #"<<cas<<": "<<sum<<endl;
	}
	return 0;
}
