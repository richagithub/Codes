// Author : anta0

#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

template<typename T>                                     /*Use of Template */
vector<pair<T, int> > runLength(const T a[], int n) {
	vector<pair<T, int> > r;
	if (n <= 0) return r;
	int cnt = 0;
	for (int i = 0; i <= n; i ++) {
		if (i == n || (i != 0 && a[i] != a[i - 1])) {
			r.push_back(make_pair(a[i - 1], cnt));
			cnt = 0;
		}
		cnt ++;
	}
	return r;
}

int main() {
	char S[100001];
	while (~scanf("%s", S)) {
		auto runs = runLength(S, strlen(S)); /*recieving  vector<pair> in auto runs;*/
		vector<int> U;
		for (auto run : runs) {
			rep(k, run.second)
				U.push_back((k + 1) * (run.first - 'a' + 1));
		}
		sort(U.begin(), U.end());
		int Q;
		scanf("%d", &Q);
		rep(ii, Q) {
			int x;
			scanf("%d", &x);
			bool ans = binary_search(U.begin(), U.end(), x);  /* Used binary Search STL */
			puts(ans ? "Yes" : "No");
		}
	}
	return 0;
