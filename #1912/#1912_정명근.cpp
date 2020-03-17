/////////////////////////////////////////////////////////////
// title : 백준 1912 - 연속합(DP)
// date : 2020.03.15
// writer : jeong
// result : 성공.. 참고함
// problem : https://www.acmicpc.net/problem/1912
// reference : https://www.youtube.com/watch?v=zTgSCqc9vHc
/////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int number[100000];
int DP[100001] = { 0, };
int n, temp, max_sum=-1001;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> number[i];
		temp = DP[i] + number[i];
		DP[i + 1] = max(number[i], temp);
		if (DP[i + 1] > max_sum)max_sum = DP[i + 1];
	}
	cout << max_sum;
	return 0;
}
