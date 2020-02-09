/////////////////////////////////////////////////////////////
// title : 백준 4256 - 트리(전위, 중위 제시해주고, 후위 구하시오)
// date : 2020.02.03
// writer : jeong
// result : 실패 ~~~~~~~~~~~~~~~~~~~~~~~
// reference : https://github.com/Yukariko/acm/blob/master/problem/4256/test.c
/////////////////////////////////////////////////////////////

#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;
int pre[1001];
int in[1001];
int n[100000000];
int result[1001];
int cnt = 0;

void DFS(int root, int start, int end) {
	for (int i = start; i < end; i++) {
		if (pre[root] == in[i]) { // 중위에서 인덱스 = i
			DFS(root + 1, start, i);
			DFS(root + (i - start) + 1, i + 1, end);
			result[cnt++] = pre[root];
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {

		// 데이터 받기
		cin >> n[i];
		for (int j = 0; j < n[i]; j++) {
			cin >> pre[j];
		}
		for (int j = 0; j < n[i]; j++) {
			cin >> in[j];
		}

		// DFS
		// 첫인자 : pre에서의 root의 인덱스
		// 나머지 : start ~ end
		DFS(0, 0, n[i]);
	}

	for (int i = 0; i < T; i++) {
		int start = n[i];
		int end = start + n[i + 1];
		for (int j = start; j < end; j++) {
			cout << result[j] << ' ';
		}
		if (i != T - 1) {
			cout << '\n';
		}
	}
	return 0;
}
