/////////////////////////////////////////////////////////////
// title : (Greedy Algorithm) 백준 1946 신입사원
// date : 2020.01.06
// writer : jeong
// result : ok
/////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	int testCase = 0;
	int N = 0;

	cin >> testCase;
	vector<int>result(testCase);

	for (int i = 0; i < testCase; i++) {
		cin >> N;
		vector<pair<int, int>>v(N);
		int count = 1;
		int min = 100001;

		for (int i = 0; i < N; i++) {
			cin >> v[i].first >> v[i].second;
		}
		sort(v.begin(), v.end());

		for (int i = 1; i < N ; i++) {
			if ((v[0].second > v[i].second)&&(min > v[i].second)) {
				min = v[i].second;
				count++;
			}
		}
		result[i] = count;
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
	return 0;
}
