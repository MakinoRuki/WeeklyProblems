#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define N 200005
#define M 25
#define eps 1e-6
using namespace std;
typedef long long ll;
int t, n, m;
ll h[N];
ll w, x, y, z;
int a[M], b[M], u[M], d[M];
int ru[N], rd[N], lu[N], ld[N];
bool check(double mid) {
	double upv = h[1] + mid, dwnv = h[1] - mid;
	for (int i = 1; i < n; ++i) {
		double tuv = h[i + 1] + mid;
		double tdv = h[i + 1] - mid;
		if (lu[i + 1] >= 0) {
			if (tuv- upv - ld[i + 1] > eps) tuv = upv + ld[i + 1];
			if (dwnv - lu[i + 1] - tdv > eps) tdv = dwnv - lu[i + 1];
		}
		if (tdv - tuv > eps) return false;
		if (ru[i] >= 0) {
			upv += ru[i];
			dwnv -= rd[i];
			if (upv - tuv > eps) upv = tuv;
			if (tdv - dwnv > eps) dwnv = tdv;
		} else {
			upv = tuv;
			dwnv = tdv;
		}
		if (dwnv - upv > eps) return false;
	}
	return true;
}
int main() {
	freopen("platform_parkour.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
	cin>>t;
	for (int cas = 1; cas <= t; ++cas) {
		cin>>n>>m;
		cin>>h[1]>>h[2]>>w>>x>>y>>z;
		for (int i = 0; i < m; ++i) {
			cin>>a[i]>>b[i]>>u[i]>>d[i];
		}
		for (int i = 3; i <= n; ++i) {
			h[i] = (w * h[i - 2] + x * h[i - 1] + y) % z;
		}
		memset(ru, -1, sizeof(ru));
		memset(rd, -1, sizeof(rd));
		memset(lu, -1, sizeof(lu));
		memset(ld, -1, sizeof(ld));
		for (int i = 0; i < m; ++i) {
			if (a[i] > b[i]) {
				for (int j = a[i]; j > b[i]; j--) {
					if (lu[j] < 0) {
						lu[j] = u[i];
						ld[j] = d[i];
					} else {
						lu[j] = min(lu[j], u[i]);
						ld[j] = min(ld[j], d[i]);
					}
				}
			} else {
				for (int j = a[i]; j < b[i]; ++j) {
					if (ru[j] < 0) {
						ru[j] = u[i];
						rd[j] = d[i];
					} else {
						ru[j] = min(ru[j], u[i]);
						rd[j] = min(rd[j], d[i]);
					}
				}
			}
		}
		double l = 0.0, r = (double)z;
		while(fabs(l - r) > eps) {
			double mid = (l + r) * 0.5;
			if (check(mid)) {
				r = mid;
			} else {
				l = mid;
			}
		}
		cout<<"Case #"<<cas<<": ";
		printf("%.6lf\n", r);
	}
	return 0;
}
