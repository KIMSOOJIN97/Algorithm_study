/////////////////////////////////////////////////////////////
// title : 백준 15683 - 감시 (samsung) DFS로 조합하기
// date : 2020.02.24
// writer : jeong
// result : 참고함.. DFS 진짜 너무 어렵다... DFS로 조합하는거..
// problem : https://www.acmicpc.net/problem/14501
// reference : https://jaimemin.tistory.com/1070
/////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
using namespace std;

int N, M;
int map[8][8];
int copy_map[8][8];
vector<pair<int, pair<int, int>>>cctv;
vector<int>dir;
int dx[4] = { 0,1,0,-1 }; // 동, 남, 서, 북 순서
int dy[4] = { 1,0,-1,0 };
int min_safe_area=65;

void COPY_MAP() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			copy_map[i][j] = map[i][j];
		}
	}
}

void COUNT() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (copy_map[i][j] == 0) cnt++;
		}
	}
	if (cnt < min_safe_area)min_safe_area = cnt;
}

void COVER(int x, int y, int DIR) {
	int cnt = 1;
	while (1) {
		if (copy_map[x + cnt * dx[DIR]][y + cnt * dy[DIR]] == 6 || x + cnt * dx[DIR] < 0 || y + cnt * dy[DIR] < 0 || x + cnt * dx[DIR] >= N || y + cnt * dy[DIR] >= M) {
			break;
		}
		if (copy_map[x + cnt * dx[DIR]][y + cnt * dy[DIR]] != 0) {
			cnt++;
			continue;
		}
		copy_map[x + cnt * dx[DIR]][y + cnt * dy[DIR]] = 7;
		cnt++;
	}
}

void DFS(int index) {
	if (index == cctv.size()) { // 방향 정보 다 채웠으면
		COPY_MAP(); // 맵 초기화

		for (int i = 0; i < cctv.size(); i++) {
			switch (cctv[i].first) {
			case 1:
				COVER(cctv[i].second.first, cctv[i].second.second, dir[i]);
				break;
			case 2:
				COVER(cctv[i].second.first, cctv[i].second.second, dir[i]);
				COVER(cctv[i].second.first, cctv[i].second.second, (dir[i] + 2) % 4);
				break;
			case 3:
				COVER(cctv[i].second.first, cctv[i].second.second, dir[i]);
				COVER(cctv[i].second.first, cctv[i].second.second, (dir[i] + 1) % 4);
				break;
			case 4:
				COVER(cctv[i].second.first, cctv[i].second.second, dir[i]);
				COVER(cctv[i].second.first, cctv[i].second.second, (dir[i] + 1) % 4);
				COVER(cctv[i].second.first, cctv[i].second.second, (dir[i] + 3) % 4);
				break;
			case 5:
				COVER(cctv[i].second.first, cctv[i].second.second, dir[i]);
				COVER(cctv[i].second.first, cctv[i].second.second, (dir[i] + 1) % 4);
				COVER(cctv[i].second.first, cctv[i].second.second, (dir[i] + 2) % 4);
				COVER(cctv[i].second.first, cctv[i].second.second, (dir[i] + 3) % 4);
				break;
			}
		}
		COUNT();
		return;
	}

	for (int i = 0; i < 4; i++) { // DFS는 최대한 간단하게 ㅠㅠ
		dir.push_back(i);
		DFS(index + 1);
		dir.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) { // N 세로
		for (int j = 0; j < M; j++) { // M 가로
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 5)cctv.push_back(make_pair(map[i][j], make_pair(i, j)));
		}
	}

	DFS(0);
	cout << min_safe_area;
	return 0;
}
//
