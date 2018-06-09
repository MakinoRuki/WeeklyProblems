#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int t, n;
vector<int> r, c;
int main() {
    cin>>t;
    for (int cas = 1; cas <= t; ++cas) {
        cin>>n;
        int minx, maxx, miny, maxy;
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin>>x>>y;
            if (i == 0) {
                minx = maxx = x;
                miny = maxy = y;
            } else {
                minx = min(minx, x);
                maxx = max(maxx, x);
                miny = min(miny, y);
                maxy = max(maxy, y);
            }
        }
        int ans = max((maxx - minx + 1) / 2, (maxy - miny + 1) / 2);
        cout<<"Case #"<<cas<<": "<<ans<<endl;
    }
    return 0;
}
