/////////////////////////////////////////////////////////////
// title : 백준 14889 - 스타트와 링크 (Silver 3)
// date : 2020.01.26
// writer : jeong
// result : 
/////////////////////////////////////////////////////////////

#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int map[20][20];
int N;
int min_int = 1000000000;
int check[20];
vector<int>start;

int first, second;
int start_sum = 0;
int link_sum = 0;

void DFS(int N, int index, int st) {
	if (index == 0) {
		start_sum = 0;
		link_sum = 0;
		vector<int>link; // 함수 안에 선언해주면 매번 자동 초기화됨

		for (int i = 0; i < N; i++) {
			if (check[i] == 1) link.push_back(i); // 배열 v값이 1이면 start로 선택되지 않은 친구들
		}
		for (int i = 0; i < N / 2; i++) {
			for (int j = i + 1; j < N / 2; j++) {
				// start팀
				first = start[i];
				second = start[j];
				start_sum += map[first][second] + map[second][first];
				// link팀
				first = link[i];
				second = link[j];
				link_sum += map[first][second] + map[second][first];
			}
		}
		if (min_int > abs(link_sum - start_sum))min_int = abs(link_sum - start_sum);
		return;
	}
	// N/2 만큼 start팀 고르기
	for (int i = st; i < N; i++) {
		if (check[i] == 1) {
			check[i]--; // 결국, start팀으로 골라진 녀석들은 v 배열값이 0이된다.
			start.push_back(i);
			DFS(N, index - 1, i); // i라는 다음 st를 들고다니는게 핵심! 이래야지 쓸데없는 반복 없앰.
			start.pop_back();
			check[i]++;
		}
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
		}
	}
	for (int i = 0; i < N; i++) {
		check[i] = 1;
	}

	DFS(N, N / 2, 0);
	cout << min_int;

	return 0;
}
