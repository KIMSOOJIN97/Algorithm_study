/////////////////////////////////////////////////////////////
// title : 백준 14890 - 경사로 (시뮬레이션)
// date : 2020.03.03
// writer : jeong
// result : 복잡... 시뮬
// problem : https://www.acmicpc.net/problem/14890
// reference : 
/////////////////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, L, cnt = 0, x, y, dir = 0;
int map[100][100];
int max_height = 0;
int dx[4] = { 0,1 };
int dy[4] = { 1,0 };
int flag = 0;


void CHECK_ROW(int i, int j) {
	bool check[100][100];
	int x = i;
	int y = j;
	dir = 0;
	while (1) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (ny > N - 1) {
			cnt++;
			break;
		}
		if (map[x][y] == map[nx][ny]) { // 이동해도 높이가 같으면
			x = nx;
			y = ny;
			continue;
		}
		// 내리막
		if (map[x][y] - map[nx][ny] == 1) { // 내리막길
			// 문제 없는지 탐색
			if (y + (L - 1) * dy[dir]<0 || y + (L - 1) * dy[dir] >N - 1) { // 길이 일단 재기
				break;
			}
			for (int z = 0; z < L; z++) {
				if (map[nx][ny] != map[nx][ny + z * dy[dir]] || check[nx][ny + z * dy[dir]] == true) { // L개동안 같지 않다면, 겹친다면
					break;
				}
				check[nx][ny + z * dy[dir]] = true;
			}
			// L개동안 같았다면 (L이 1이면 바로 여기로 온다)
			if (flag == 0) {
				x = nx;
				y = ny;
				continue;
			}
		}
		// 오르막
		if (map[x][y] - map[nx][ny] == -1) { // 오르막길
			if (y - (L - 1) * dy[dir]<0 || y - (L - 1) * dy[dir] >N - 1) { // 길이 일단 재기
				break;
			}
			for (int z = 0; z < L; z++) {
				if (map[x][y] != map[nx][ny - z * dy[dir]] || check[nx][ny - z * dy[dir]] == true) { // L개동안 같지 않다면,
					break;
				}
				check[nx][ny - z * dy[dir]] = true;
			}
			// L개동안 같았다면 (L이 1이면 바로 여기로 온다)
			if (flag == 0) {
				x = nx;
				y = ny;
				continue;
			}
		}
	}
}
void CHECK_COL(int i, int j) {
	bool check[100][100];
	int x = i;
	int y = j;
	dir = 1;
	while (1) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx > N - 1) {
			cnt++;
			break;
		}
		if (map[x][y] == map[nx][ny]) { // 이동해도 높이가 같으면
			x = nx;
			y = ny;
			continue;
		}
		// 내리막
		if (map[x][y] - map[nx][ny] == 1) { // 내리막길
			// 문제 없는지 탐색
			if (x + (L - 1) * dx[dir]<0 || x + (L - 1) * dx[dir] >N - 1) { // 길이 일단 재기
				break;
			}
			for (int z = 0; z < L; z++) {
				if (map[nx][ny] != map[nx + z * dx[dir]][ny] || check[nx + z * dx[dir]][ny] == true) { // L개동안 같지 않다면, 겹친다면
					return;
				}
				check[nx + z * dx[dir]][ny] = true;
			}
			// L개동안 같았다면 (L이 1이면 바로 여기로 온다)
			if (flag == 0) {
				x = nx;
				y = ny;
				continue;
			}
		}
		// 오르막
		if (map[x][y] - map[nx][ny] == -1) { // 오르막길
			if (x - (L - 1) * dx[dir]<0 || x - (L - 1) * dx[dir] >N - 1) { // 길이 일단 재기
				break;
			}
			for (int z = 0; z < L; z++) {
				if (map[nx][ny] != map[nx - z * dx[dir]][ny] || check[nx - z * dx[dir]][ny] == true) { // L개동안 같지 않다면,
					return;
				}
				check[nx - z * dx[dir]][ny] = true;
			}
			// L개동안 같았다면 (L이 1이면 바로 여기로 온다)
			if (flag == 0) {
				x = nx;
				y = ny;
				continue;
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> L;
	// 맵 저장
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}


	for (int i = 0; i < N; i++) {
		CHECK_ROW(i, 0);
		CHECK_COL(0, i);
	}
	cout << cnt;
	return 0;
}
