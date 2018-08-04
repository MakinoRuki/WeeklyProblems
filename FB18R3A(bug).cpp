#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 60
using namespace std;
int t, n, k;
int cnt;
int u[N], v[N], w[N];
int main() {
	freopen("ethan_finds_the_shortest_path.txt","r", stdin);
	freopen("aout.txt", "w", stdout);
	cin>>t;
	for (int cas = 1; cas <= t; ++cas) {
		cin>>n>>k;
		cnt = 0;
		cout<<"Case #"<<cas<<": ";
		int num = min(n - 1, k - 1);
		int tot1 = 0;
		int tot2 = 0;
		if (k == 1 || n == 2 || num <= 1) {
			u[cnt] = 1;
			v[cnt] = 2;
			w[cnt] = k;
			cnt++;
			tot1 = 0;
			tot2 = 0;
		} else {
			u[cnt] = 1;
			v[cnt] = n;
			w[cnt] = k;
			cnt++;
			tot2 = k;
			for (int i = 1; i <= num; ++i) {
				if (i < num) {
					u[cnt] = 1 + i - 1;
					v[cnt] = 1 + i;
					w[cnt] = k - i;
				} else {
					u[cnt] = 1 + i - 1;
					v[cnt] = n;
					w[cnt] = k - i;
				}
				tot1 += k - i;
				cnt++;
			}
		}
		cout<<tot1 - tot2<<endl;
		cout<<cnt<<endl;
		for (int i = 0; i < cnt; ++i) {
			cout<<u[i]<<" "<<v[i]<<" "<<w[i]<<endl;
		}
	}
	return 0;
}
