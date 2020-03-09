/////////////////////////////////////////////////////////////
// title : 백준 2667 - 단지 번호 붙이기(미로찾기 upgrade 라고 생각함) DFS
// date : 2020.01.18
// writer : jeong
// result : DFS로 구현 - 모범답안 보고 감탄
// 문제   : https://www.acmicpc.net/problem/2667
/////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>


char map[26][26];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int N = 0;
int NumGroup = 0;      // 단지 수
int cnt[500] = { 0, }; // 배열 크기 주의!!!
int t_cnt=0;


using namespace std;

void DFS(int x, int y) {

	map[x][y] = '0'; // 1이었던거 0으로 만들어버려
	t_cnt++;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		// 맵을 벗어나지 않고, 맵이 1인경우
		if (nx >= 0 && ny >= 0 && nx < N&&ny < N&&map[nx][ny] == '1') {

			DFS(nx, ny);
		}

	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	// 맵을 전부 확인한다. 1이 나오면 그때부턴 DFS
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == '1') {

				DFS(i, j);
				cnt[NumGroup] = t_cnt;
				t_cnt = 0;
				NumGroup++;
			}
		}
	}
	// 정렬
	sort(cnt, cnt+NumGroup);


	cout << NumGroup << '\n';
	for (int i = 0; i < NumGroup; i++) {
		cout << cnt[i] << '\n';
	}
	return 0;
}


/////////////////////////////////////////////////////////////
// title : 백준 2667 - 단지 번호 붙이기(미로찾기 upgrade 라고 생각함) BFS
// date : 2020.01.17
// writer : jeong
// result : 2번 정렬 까먹고있다가 틀리고
//          1번 algorithm include 안해서 틀리고
//          4번째로 성공
// 문제   : https://www.acmicpc.net/problem/2667
/////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <queue>
#include <vector>
#include <algorithm>


char map[26][26];
bool check[26][26];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int N;
int NumGroup = 0;
int cnt[500]; // 배열 크기 주의!!!


using namespace std;

int BFS(int i, int j) { // 배열은 참조가 되지 않기때문에 주소값을 받아서 직접 접근

	int cnt=0;
	queue<pair<int, int>>q;
	q.push(make_pair(i, j));
	check[i][j] = true; // 방문처리


	while (!q.empty()) {
		int x = q.front().first; // 행
		int y = q.front().second; // 열
		q.pop();
		cnt++;  // 와... 실수주의
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 0 || ny < 0 || nx > N-1 || ny > N-1) {
				continue;
			}
			if (map[nx][ny] != '1') {
				continue;
			}
			if (check[nx][ny] == true) {
				continue;
			}
			q.push(make_pair(nx, ny));
			check[nx][ny] = true;
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int>cntvec;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	// 맵을 전부 확인한다. 1이 나오면 그때부턴 bfs
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == '1' && check[i][j] != true) { // 이미 bfs를 통해 방문처리 된곳은 다시 안들어가게 만들어줌.
				cntvec.push_back(BFS(i, j));
				NumGroup++;
			}
			check[i][j] = true;
		}
	}

	sort(cntvec.begin(), cntvec.end());

	cout << NumGroup << '\n';
	for (int i = 0; i < NumGroup; i++) {
		cout << cntvec[i] << '\n';
	}
	return 0;
}
