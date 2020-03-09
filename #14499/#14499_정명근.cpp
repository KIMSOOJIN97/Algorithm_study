/////////////////////////////////////////////////////////////
// title : 백준 14499 - 주사위 굴리기
// date : 2020.02.09
// writer : jeong
// result : 
// problem : https://www.acmicpc.net/problem/14499
// reference : 
/////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;
int N, M, x, y, K, order, temp;
int map[20][20];
int pos[6] = { 0, };
int dx[5] = { 0,0,0,-1,1 }; // 1,2,3,4 -> 동서북남
int dy[5] = { 0,1,-1,0,0 };

void CheckBottom() {
	if (map[x][y] == 0) {
		map[x][y] = pos[6];
	}
	else if (map[x][y] != 0) {
		pos[6] = map[x][y];
		map[x][y] = 0;
	}
}

bool CheckRange(int order) {
	int nx = x + dx[order];
	int ny = y + dy[order];

	if (nx<0 || ny<0 || nx>N - 1 || ny>M - 1) { // 범위 밖을 벗어나면
		return false;
	}
	x = nx;
	y = ny;
	return true;
}

void Move(int order) {
	if (CheckRange(order)) { // 현재 바닥면이 맵 안에 있는지
		switch (order) {
		case 1:
			temp = pos[3];
			pos[3] = pos[1];
			pos[1] = pos[4];
			pos[4] = pos[6];
			pos[6] = temp;
			break;
		case 2:
			temp = pos[4];
			pos[4] = pos[1];
			pos[1] = pos[3];
			pos[3] = pos[6];
			pos[6] = temp;
			break;
		case 3:
			temp = pos[2];
			pos[2] = pos[1];
			pos[1] = pos[5];
			pos[5] = pos[6];
			pos[6] = temp;
			break;
		case 4:
			temp = pos[6];
			pos[6] = pos[5];
			pos[5] = pos[1];
			pos[1] = pos[2];
			pos[2] = temp;
			break;
		}
		CheckBottom();
		cout << pos[1] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> x >> y >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i=0; i < K; i++) {
		cin >> order;
		Move(order);
	}

	return 0;
}
