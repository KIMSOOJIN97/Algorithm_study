/////////////////////////////////////////////////////////////
// title : 백준 14503 - 로봇 청소기
// date : 2020.03.17
// writer : jeong
// result : 
// problem : https://www.acmicpc.net/problem/14503
// reference : 
/////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, r, c, d, cnt = 0, init_cnt=0;
int map[50][50];
bool check[50][50] = { false, };
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

void CheckMap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0 && check[i][j]==true)cnt++; // 청소한 영역을 세기
		}
	}
}

void Move(int dir, int x, int y, int count) {
	if (count == 4) { // 네 방향 탐색을 모두 끝냈으면, 
		int mx = x + dx[(dir + 2) % 4];
		int my = y + dy[(dir + 2) % 4];
		if (map[mx][my] == 1) return; // 뒤에 벽이다, 그러면 후진 못하니 종료
		else Move(dir, mx, my, 0); // 방향은 그대로 유지한 채, 뒤로 후진
	}
	else{
		int nx = x + dx[(dir + 1) % 4];
		int ny = y + dy[(dir + 1) % 4];
		if (check[nx][ny] == true||map[nx][ny]==1) { // 이미 방문했거나, 벽이면 방향만 바꾸고 count 증가시켜
			Move((dir + 1) % 4, x, y, count + 1);
			return;
		}
		else {
			check[nx][ny] = true;
			Move((dir + 1) % 4, nx, ny, 0);
			return;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++) { // 맵 다 받기
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	switch (d) { // 방향 바꿔주기 (시계->반시계)
	case 1:
		d = 3;
		break;
	case 3:
		d = 1;
		break;
	}
	check[r][c] = true; // 초기위치 방문처리
	Move(d, r, c, 0);
	CheckMap();

	cout << cnt;
	return 0;
}
