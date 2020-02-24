/////////////////////////////////////////////////////////////
// title : 백준 2468 - 안전 영역 (DFS,BFS)
// date : 2020.02.07
// writer : jeong
// result : 아니... 다 1인 경우 왜 1이지? 아직도 이해는 안가지만 맞음... -> 비가 안오는 경우도 
// 실수   : 물에 안잠긴곳을 세야지, 물에 잠긴곳을 세고 있었다... 하...
// problem : https://www.acmicpc.net/problem/2468
// reference : 
/////////////////////////////////////////////////////////////

#include <iostream>
#include <queue>

using namespace std;

int N;
int map[101][101];
int map_copy[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int max_height = 0;
int safe_area = 0;
int max_safe_area = 0;

void CopyMap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map_copy[i][j] = map[i][j];
		}
	}
}

void BFS(int k, int i, int j) { // k보다 높은 애들은 다 0으로 만들어버려
	queue<pair<int, int>>q;
	q.push(make_pair(i, j));
	map_copy[i][j] = 0; // 0으로 만들어버려

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int a = 0; a < 4; a++) {
			int nx = x + dx[a];
			int ny = y + dy[a];
			if (nx<0 || ny<0 || nx>N - 1 || ny>N - 1) continue; // 범위 밖을 나가면 continue
			if (map_copy[nx][ny] > k) {
				q.push(make_pair(nx, ny));
				map_copy[nx][ny] = 0; // 0으로 만들어버려
			}
		}
	}
}

void FIND_ANSWER() {
	for (int k = 1; k < max_height; k++) {
		CopyMap();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map_copy[i][j] > k) {
					BFS(k, i, j);
					safe_area++;
				}
			}
		}
		if (safe_area > max_safe_area) max_safe_area = safe_area; // 최댓값 갱신
		safe_area = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] > max_height) max_height = map[i][j]; // 최대 높이 저장
		}
	}

	FIND_ANSWER();
	if (max_safe_area == 0) {
		cout << 1;
	}
	else {
		cout << max_safe_area;
	}

	return 0;
}
