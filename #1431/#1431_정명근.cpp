/////////////////////////////////////////////////////////////
// title : 백준 1431 
// date : 2019.12.22
// writer : jeong
// result : 이중 pair 를 사용하였음. 
//          새롭게 추가된 개념은 그저.. 문자열에서 숫자 뽑아서 더하는것. 
/////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int SumOfNums(string a) { // 숫자합

	int sum = 0;

	for (int i = 0; i < a.size(); i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			sum += a[i] - '0';
		}
	}
	return sum;
}

bool compare(pair<string, pair<int, int>> a,
	pair<string, pair<int, int>> b) {
	if (a.second.first == b.second.first) { // 문자의 갯수가 같다면
		if (a.second.second == b.second.second) { // 3. 숫자합도 같다면
			return a < b;  // 작은거 먼저 출력
		}
		return SumOfNums(a.first) < SumOfNums(b.first); // 2. 숫자합 작은것 먼저 정렬
	}
	else {
		return (a.second.first < b.second.first);  // 1. 문자의 갯수가 적은쪽 먼저 정렬
	}

}

int main()
{

	int number;

	cin >> number;
	vector<pair<string, pair<int, int>>> v(number); // 글자, 몇글자, 숫자합

	for (int i = 0; i < number; i++) {
		cin >> v[i].first;
		v[i].second.first = v[i].first.size(); // 몇글자
		v[i].second.second = SumOfNums(v[i].first); // 숫자합
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < number; i++) {
		cout << v[i].first << "\n";
	}

	return 0;
}
