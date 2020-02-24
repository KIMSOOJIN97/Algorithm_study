/////////////////////////////////////////////////////////////
// title : 백준 14502 - samsung 
// date : 2020.01.18
// writer : jeong
// result : DFS로 구현
// 문제   : https://www.acmicpc.net/problem/14502
//
// README
//
// 1. (x,y)는 x,y좌표가 아닌, (행,열) 그대로 따라가자.
// 
/////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int N, M;
int map[8][8];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int _dx[8] = { 1,1,1,-1,-1,-1,0,0 };
int _dy[8] = { 1,0,-1,1,0,-1,1,-1 };
int cnt = 0;          // 안전영역('0')의 갯수를 카운팅하는 변수
int MaxSafeArea = -1; // 최종적으로 안전영역 최대값 저장
bool check[8][8] = { false, }; // BFS에서 방문처리용 배열


using namespace std;

void virusBFS() { // 2와 인접한 0을 줄줄이 탐색하는 BFS
	queue<pair<int, int>>q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 2) { // 2를 만나면 BFS 시작
				q.push(make_pair(i, j));
				check[i][j] = true; // 초기위치 방문처리

				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) { // 현재 노드의 동서남북을 한번씩 보면서 0인지 체크
						int nx = x + dx[k];
						int ny = y + dy[k];
						// 맵 안에 있고, 퍼질 수 있는 장소이며, 방문하지 않았다면, 방문한다.
						if (nx >= 0 && ny >= 0 && nx < N && ny < M && map[nx][ny] == 0 && check[nx][ny] != true) {
							q.push(make_pair(nx, ny));
							check[nx][ny] = true;
							cnt--; // 0을 2로 바꾸지는 않았지만, 바이러스가 퍼졌다고 생각하고, 안전영역을 하나 지우는것.
						}
					}
				}
			}
		}
	}
}


void wallDFS(int index) { // 벽 3개 세우는 DFS

	if (index == 3) { // 벽 3개 다 세웠으면

		// 1. map에서 0의 갯수 파악 -> cnt
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0) {
					cnt++;
				}
			}
		}

		// 2. 바이러스 퍼지는 공간마다 cnt 빼주기
		virusBFS();

		// 3. cnt와 Max 비교해서 최댓값 갱신
		if (cnt > MaxSafeArea) {
			MaxSafeArea = cnt;
		}
		// 4. 방문처리 배열 초기화
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				check[i][j] = false;
			}
		}
		// 5. 카운팅 초기화
		cnt = 0;
	}


	if (index < 3) { // 사용할 수 있는 벽의 갯수가 남아있으면
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0) { // 0을 만나면
					int flag = 0;
					for (int k = 0; k < 8; k++) {
						int nx = i + _dx[k];
						int ny = j + _dy[k];
						// 속도를 올리기 위해
						// 일단은 map 안에 있어야 하고,
						// 동, 서, 남, 북, 북동, 북서, 남동, 남서 중에 하나라도 벽이나 바이러스가 있어야 flag=1로 만들어 벽을 세운다.
						if (map[nx][ny] != 0 && nx >= 0 && ny >= 0 && nx < N&&ny < M) {
							flag = 1;
							break;
						}
					}
					if (flag == 1) {
						map[i][j] = 1; // 벽 세우기
						wallDFS(index + 1);
						map[i][j] = 0; // DFS탈출 후 벽 허물기
					}
				}
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			check[i][j] = false; // 방문처리용 배열 초기화
		}
	}

	wallDFS(0);
	cout << MaxSafeArea;

	return 0;
}
