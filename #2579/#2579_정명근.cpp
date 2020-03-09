/////////////////////////////////////////////////////////////
// title : 백준 2579 - 계단오르기 DP로 풀기
// date : 2020.03.02
// writer : jeong
// result : 참고함~ 성공~
// problem : https://www.acmicpc.net/problem/2579
// reference : https://mygumi.tistory.com/100
/////////////////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
using namespace std;
int N;
int score[301];
int DP[301]; // DP[N]은 N번째 칸까지 올라올때까지의 나올 수 있는 점수

int dp(int level) {
	if (level == 0)return 0;
	if (level == 1)return score[1];
	if (level == 2)return score[1]+score[2];
	if (DP[level] > 0)return DP[level];
	return DP[level] = max(dp(level - 3) + score[level - 1] + score[level], dp(level - 2) + score[level]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> score[i];
	}

	cout << dp(N);
	return 0;
}
