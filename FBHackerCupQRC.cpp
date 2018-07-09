#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 2005
using namespace std;
int t, n;
string a, b;
int pre[N];
void getpre() {
	for (int i = 1; i < n; ++i) {
		int j = pre[i - 1];
		while(j != -1) {
			if (a[j + 1] == a[i]) {
				break;
			}
			j = pre[j];
		}
	//	cout<<"*"<<i<<" "<<j<<endl;
	//	cout<<a[j + 1]<<" "<<a[i]<<endl;
		if (a[j + 1] == a[i]) pre[i] = j + 1;
	//	cout<<i<<" "<<pre[i]<<endl;
	}
}
int main() {
	freopen("ethan_searches_for_a_string.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
	cin>>t;
	for (int cas = 1; cas <= t; ++cas) {
		cin>>a;
		n = a.size();
		memset(pre, -1, sizeof(pre));
		getpre();
		// for (int i = 0; i < n; ++i) {
		// 	cout<<i<<" "<<pre[i]<<endl;
		// }
		int i;
		string b = "";
		for (i = 0; i < n - 1; ++i) {
			int j = pre[i];
			while(j != -1) {
				if (a[j + 1] != a[i + 1]) {
					break;
				}
				j = pre[j];
			}
			//if (i == 2) cout<<i<<" "<<j<<endl;
			if (j != -1) {
				b = a.substr(0, i + 1) + a.substr(j + 1, n - j - 1);
				break;
			}
		}
		cout<<"Case #"<<cas<<": ";
		if (b.empty()) {
			cout<<"Impossible"<<endl;
		} else {
			cout<<b<<endl;
		}
	}
	return 0;
}
