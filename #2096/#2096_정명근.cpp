/////////////////////////////////////////////////////////////
// title : 백준 2096 - 내려가기 (DP)
// date : 2020.03.04
// writer : jeong
// result : 와... 맞았...다....
// problem : https://www.acmicpc.net/problem/2096
// reference : https://wootool.tistory.com/175
/////////////////////////////////////////////////////////////

#include  <stdio.h>
#define Max(a,b) ((a) > (b) ? (a) : (b))
#define Min(a,b) ((a) < (b) ? (a) : (b))
using namespace std;
int DP[100001][3];
int map[100001][3];
int N;

int main() {
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d %d %d", &map[i][0], &map[i][1], &map[i][2]);
	}
	// max를 위한 준비
	for (int i = 0; i < 3; i++) {
		DP[N - 1][i] = map[N - 1][i];
	}
	for (int i = N - 2; i >= 0; i--) {
		DP[i][0] = Max(DP[i + 1][0], DP[i + 1][1]) + map[i][0];
		DP[i][1] = Max(Max(DP[i + 1][0], DP[i + 1][1]), DP[i + 1][2]) + map[i][1];
		DP[i][2] = Max(DP[i + 1][1], DP[i + 1][2]) + map[i][2];
	}
	printf("%d ", Max(Max(DP[0][0], DP[0][1]), DP[0][2]));

	// DP 배열 초기화
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			DP[i][j] = 0;
		}
	}

	// min을 위한 준비
	for (int i = 0; i < 3; i++) {
		DP[N - 1][i] = map[N - 1][i];
	}
	for (int i = N - 2; i >= 0; i--) {
		DP[i][0] = Min(DP[i + 1][0], DP[i + 1][1]) + map[i][0];
		DP[i][1] = Min(Min(DP[i + 1][0], DP[i + 1][1]), DP[i + 1][2]) + map[i][1];
		DP[i][2] = Min(DP[i + 1][1], DP[i + 1][2]) + map[i][2];
	}
	printf("%d", Min(Min(DP[0][0], DP[0][1]), DP[0][2]));
	return 0;
}


/////////////////////////////////////////////////////////////
// title : 백준 2096 - 내려가기 (DP)
// date : 2020.03.04
// writer : jeong
// result : 배열 크기 3x3으로 줄임 - 그랬는데도 메모리 오바. 이유는 재귀호출 할수록 계속해서 메모리에 쌓이는 것 때문인듯
// problem : https://www.acmicpc.net/problem/2096
// 재귀호출 메모리 잡아먹는것 : https://hh4131.tistory.com/26
/////////////////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
int N;
int map[100001][3];
int DP[3][3];

int max_dp(int x, int y) {
	if (DP[x%3][y] > -1)return DP[x%3][y]; // 이거 >-1이 아니라, >0으로 하고, main에서 memset으로 -1로 초기화 해주지 않았더라면, 0일때는 계속 다시 계산해야한다.
	if (x > N) return DP[x%3][y] = 0; // x가 N보다 크면 max_dp를 들어가지 않는다.
	if (y == 0) return DP[x%3][y] = max(max_dp(x + 1, y), max_dp(x + 1, y + 1)) + map[x][y];
	if (y == 2) return DP[x%3][y] = max(max_dp(x + 1, y - 1), max_dp(x + 1, y)) + map[x][y];
	return DP[x%3][y] = max(max(max_dp(x + 1, y - 1), max_dp(x + 1, y)), max_dp(x + 1, y + 1)) + map[x][y];
}

int min_dp(int x, int y) {
	if (DP[x % 3][y] > -1)return DP[x % 3][y]; // 이거 >-1이 아니라, >0으로 하고, main에서 memset으로 -1로 초기화 해주지 않았더라면, 0일때는 계속 다시 계산해야한다.
	if (x > N) return DP[x % 3][y] = -2; // x가 N보다 크면 min_dp를 들어가지 않는다.
	if (y == 0) {
		if (min(min_dp(x + 1, y), min_dp(x + 1, y + 1)) == -2) return DP[x % 3][y] = map[x][y];
		return DP[x % 3][y] = min(min_dp(x + 1, y), min_dp(x + 1, y + 1)) + map[x][y];
	}
	if (y == 2) {
		if (min(min_dp(x + 1, y - 1), min_dp(x + 1, y)) == -2) return DP[x % 3][y] = map[x][y];
		return DP[x % 3][y] = min(min_dp(x + 1, y - 1), min_dp(x + 1, y)) + map[x][y];
	}
	if (min(min(min_dp(x + 1, y - 1), min_dp(x + 1, y)), min_dp(x + 1, y + 1))==-2) return DP[x % 3][y] = map[x][y];
	return DP[x % 3][y] = min(min(min_dp(x + 1, y - 1), min_dp(x + 1, y)), min_dp(x + 1, y + 1)) + map[x][y];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> map[i][0] >> map[i][1] >> map[i][2];
	}
	memset(DP, -1, sizeof(DP)); // -1로 초기화. 즉, -1이면 아직 방문하지 않은 상태라는 것을 의미하게된다.
	max_dp(0, 1);

	cout << max(max(DP[1][0], DP[1][1]), DP[1][2]) << ' ';
	memset(DP, -1, sizeof(DP)); // -1로 초기화. 즉, -1이면 아직 방문하지 않은 상태라는 것을 의미하게된다.
	min_dp(0, 1);
	cout << min(min(DP[1][0], DP[1][1]), DP[1][2]);

	return 0;
}


/////////////////////////////////////////////////////////////
// title : 백준 2096 - 내려가기 (DP)
// date : 2020.03.04
// writer : jeong
// result : 메모리 초과 - 결국 문제는, 재귀호출을 할때마다 stack에 쌓이기 때문에 메모리가 소모된다. 
// problem : https://www.acmicpc.net/problem/2096
// reference : 
/////////////////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
int N;
int map[100001][3];
int DP[100001][3];

int max_dp(int x, int y) {
	if (DP[x][y] > -1)return DP[x][y]; // 이거 -1보다 크다 조건 없고, 0보다 크다로 했으면, 0일때 계속 다시 계산해야함. 즉, 0일때도 저장해주는것
	if (x >= N) return DP[x][y] = 0; // x가 N부터는 max_dp를 들어가지 않는다.
	if (y == 0) return DP[x][y] = max(max_dp(x + 1, y), max_dp(x + 1, y + 1)) + map[x][y];
	if (y == 2) return DP[x][y] = max(max_dp(x + 1, y - 1), max_dp(x + 1, y)) + map[x][y];
	return DP[x][y] = max(max(max_dp(x + 1, y - 1), max_dp(x + 1, y)), max_dp(x + 1, y + 1)) + map[x][y];
}

int min_dp(int x, int y) {
	if (DP[x][y] > -1)return DP[x][y]; // 이거 -1보다 크다 조건 없고, 0보다 크다로 했으면, 0일때 계속 다시 계산해야함. 즉, 0일때도 저장해주는것
	if (x >= N) return DP[x][y] = 0; // x가 N부터는 max_dp를 들어가지 않는다.
	if (y == 0) return DP[x][y] = min(min_dp(x + 1, y), min_dp(x + 1, y + 1)) + map[x][y];
	if (y == 2) return DP[x][y] = min(min_dp(x + 1, y - 1), min_dp(x + 1, y)) + map[x][y];
	return DP[x][y] = min(min(min_dp(x + 1, y - 1), min_dp(x + 1, y)), min_dp(x + 1, y + 1)) + map[x][y];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> map[i][0] >> map[i][1] >> map[i][2];
	}
	memset(DP, -1, sizeof(DP)); // -1로 초기화
	cout << max(max(max_dp(0, 0), max_dp(0, 1)), max_dp(0, 2)) << ' ';
	memset(DP, -1, sizeof(DP)); // -1로 초기화
	cout << min(min(min_dp(0, 0), min_dp(0, 1)), min_dp(0, 2));
	return 0;
}
