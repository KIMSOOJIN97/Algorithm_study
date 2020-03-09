/////////////////////////////////////////////////////////////
// title : 백준 2512 - 예산(이분탐색 문제)
// date : 2020.02.17
// writer : jeong
// result : 
// problem : https://www.acmicpc.net/problem/2512
// reference : https://www.youtube.com/watch?v=dvI9jeMu6BU&t=306s
/////////////////////////////////////////////////////////////

#include <iostream>
#include <algorithm>

int N, M;
int request[10000];
int l=0, r=0, m;
using namespace std;

bool ok(int mid) {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		ret += min(mid, request[i]);
	}
	return (ret <= M);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> request[i];
		r = max(r, request[i]);
	}
	cin >> M;

	while (l != r) {
		m = (l + r + 1) / 2;
		if (ok(m)) { // ok라는 함수에는 middle값이 들어가야한다.
			l = m;
		}
		else {
			r = m - 1;
		}
	}
	cout << l;

	return 0;
}
