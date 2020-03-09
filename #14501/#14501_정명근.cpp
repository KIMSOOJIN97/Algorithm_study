/////////////////////////////////////////////////////////////
// title : 백준 14501 - 퇴사 (DP) DP지만... DFS로 풀었음. DFS로 조합하는거 너무 어렵다..
// date : 2020.02.24
// writer : jeong
// result : 6시간만에 성공 
// problem : https://www.acmicpc.net/problem/14501
// reference : 
/////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
using namespace std;
int N, max_sum;
int T[15], P[15];
vector<int>v;

void DFS(int now) {
	if (now >= N) {
		int sum = 0;
		if (now == N) {
			for (int i = 0; i < v.size(); i++) {
				sum += P[v[i]];
			}
		}
		else {
			for (int i = 0; i < v.size()-1; i++) {
				sum += P[v[i]];
			}
		}
		if (sum > max_sum)max_sum = sum;
	}
	
	for (int i = now; i < N; i++) {
		v.push_back(i);
		DFS(i + T[i]);
		v.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 데이터 받기
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
	}

	// DFS
	DFS(0);

	cout << max_sum;

	return 0;
}
