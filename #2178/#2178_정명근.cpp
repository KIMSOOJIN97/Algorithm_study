/////////////////////////////////////////////////////////////
// title : (BFS) 미로찾기 - 백준 2178  복습. 포인터 사용
// date : 2020.01.11
// writer : jeong
// result : 포인터를 사용하여 문제의 환경과 100% 일치시켰다. 
//         https://www.acmicpc.net/problem/2178
//
// 문제 고려대상
// 1. 데이터 입력받을 때 숫자로 받을지, 문자로 받을지
// 2. 동서남북 어떻게 구현할지
// 3. 행렬 방향, x,y 방향 어떻게 설정할지
// 4. bfs 구현할 때 vector 선언? ㄴㄴ
// 5. queue 쓸때 얘가 담고 있어야 할 데이터 -> x,y,count
//
// bfs 고려대상
// 1. 이미 간 곳은 언제 처리를 해줘야하는가?
// 2. 
/////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define max_int 102
int N, M;

char map[max_int][max_int];
bool check[max_int][max_int];


char* map_ptr[max_int];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int bfs() {
	queue<pair<pair<int, int>, int>>q;
	q.push(make_pair(make_pair(1, 1), 1));
	check[1][1] = true; // 이것도 결국 맨처음 -1로 다 초기화 해준다음에 값을 바꿔줬다면 몇번 이동했는지 여기에도 저장할 수 있었다.

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int count = q.front().second;
		q.pop();
		if (x == N && y == M) {
			return count;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			// 범위에 벗어나거나, 갈 수 없는 길이거나, 이미 갔거나
			if (nx<1 || ny<1 || nx>N || ny>M) {
				continue;
			}
			if (map[nx][ny] != '1') {
				continue;
			}
			if (check[nx][ny] == true) {
				continue;
			}
			q.push(make_pair(make_pair(nx, ny), count + 1));
			check[nx][ny] = true;
		}
	}
}

int main(void) {
	scanf_s("%d %d", &N, &M);

	for (int i = 1; i < max_int; i++) {
		map_ptr[i] = map[i] + 1;
	}
	for (int i = 1; i <= N; i++) {
		cin >> map_ptr[i];
	}

	cout << bfs();

	return 0;
}



/////////////////////////////////////////////////////////////
// title : (BFS) 미로찾기 - 백준 2178
// date : 2020.01.10
// writer : jeong
// result : 행렬 기반의 bfs를 구현해야함. 
// 문제   : https://www.acmicpc.net/problem/2178
// 풀이 참고: https://jun-itworld.tistory.com/20
// 
/////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define max_int 101

int N, M;
bool check[max_int][max_int];
char map[max_int][max_int];

// ☆☆☆☆☆
// 완전히 x, y도 행,렬로 맞추자.
int dx[4] = { 1,-1,0,0 }; // 남, 북, 동, 서 순이다.
int dy[4] = { 0,0,1,-1 };


int bfs() {
	queue<pair<pair<int, int>,int>>q;  // 좌표 저장용 queue - bfs에서는 필수!
	q.push(make_pair(make_pair(0, 0),1)); // 처음 위치를 넣는다.
	check[0][0] = true; // 시작점 방문처리

	while (!q.empty()) {
		int x = q.front().first.first;   // 현재 x,y좌표를 얻어온다.
		int y = q.front().first.second;
		int count = q.front().second;
		q.pop();

		if (x == N - 1 && y == M - 1) { // 목적지에 다다랐을 경우 count출력
			return count;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; // 한칸씩 나아간 새로운 x,y좌표
			int ny = y + dy[i];

			// 나아갈 수 없는 조건 3가지 거르기
			// 1. 경계를 벗어날 경우
			if (nx<0 || ny<0 || nx>N-1 || ny>M-1) {
				continue;
			}
			// 2. 방문처리가 이미 되어있는 경우
			if (check[nx][ny] == 1) {
				continue;
			}
			// 3. map 데이터가 1이 아닌 경우 (갈수 없는 곳인 경우)
			if (map[nx][ny] != '1') {
				continue;
			}
			q.push(make_pair(make_pair(nx, ny),count+1));
			check[nx][ny] = true; // 방문처리
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> map[i]; // 와.. 똑똑하다...
	}
	cout << bfs();

	return 0;
}
