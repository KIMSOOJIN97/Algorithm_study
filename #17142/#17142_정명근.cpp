/////////////////////////////////////////////////////////////
// title : 백준 17142 - 연구소 3
// date : 2020.03.04
// writer : jeong
// result : 
// problem : https://www.acmicpc.net/problem/17142
// reference : 
/////////////////////////////////////////////////////////////

#include  <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int x, y, nx, ny, level, flag = 0, min_flag = 0, min_level = 10000;
int map[50][50];
int copy_map[50][50];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
vector<pair<int, int>>v;
vector<int>virus;
vector<int>result;

void CHECKMAP() {
	int max_level = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (copy_map[i][j] == 10001)continue;
			if (copy_map[i][j] == 10000) {
				result.push_back(-1);
				return;
			}
			if (copy_map[i][j] > max_level) {
				// 비 활성 바이러스를 지나가려면 이렇게 해줘야함. 
				for (int k = 0; k < v.size(); k++) { 
					if (v[k].first == i && v[k].second == j) {
						flag = 1;
						break;
					}
				}
				if (flag == 1) {
					flag = 0;
					continue; // 이렇게 비 활성 바이러스를 만나면 max_level 저장 안하고 다시 탐색 keep going
				}
				max_level = copy_map[i][j];
			}
		}
	}
	result.push_back(max_level);
}

void COPYMAP() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1) copy_map[i][j] = 10001; // 벽
			else copy_map[i][j] = 10000; // 0이나 2였던 곳
		}
	}
	for (int i = 0; i < virus.size(); i++) {
		copy_map[v[virus[i]].first][v[virus[i]].second] = 0; // 활성바이러스
	}
}

void DFS(int st) {
	if (virus.size() == M) {// 바이러스 골라담은게 M개라면
		COPYMAP();// 맵 복사
		queue<pair<pair<int, int>, int>>q;
		for (int i = 0; i < virus.size(); i++) {
			q.push(make_pair(make_pair(v[virus[i]].first, v[virus[i]].second), 0)); //골라담은 바이러스의 x,y좌표(행,열)와 level 
		}
		while (!q.empty()) {
			x = q.front().first.first;
			y = q.front().first.second;
			level = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				nx = x + dx[i];
				ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N)continue; // 범위를 벗어나면 돌아가
				if (copy_map[nx][ny] == 10000) { // 퍼뜨릴 수 있는 곳이면
					copy_map[nx][ny] = level + 1;
					q.push(make_pair(make_pair(nx, ny), level + 1));
				}
			}
		}
		CHECKMAP();
		return;
	}
	// 여기서 조합으로 M개만큼의 바이러스를 고르기
	for (int i = st; i < v.size(); i++) {
		virus.push_back(i);
		DFS(i + 1);
		virus.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)v.push_back(make_pair(i, j));
		}
	}

	DFS(0);

	for (int i = 0; i < result.size(); i++) {
		if (result[i] != -1) {
			min_flag = 1;
			if (min_level > result[i])min_level = result[i];
		}
	}
	if (min_flag == 1)cout << min_level;
	else cout << -1;

	return 0;
}//
