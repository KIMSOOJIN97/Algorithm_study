/////////////////////////////////////////////////////////////
// title : (Greedy Algorithm) 백준 2875
// date : 2020.01.04
// writer : jeong
// result : 
/////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// 동적 할당. int형 포인터 N,M,K가 동적 할당된 영역을 가리킴
	int *n = new int;
	int *m = new int;
	int *k = new int;

	// 동적할당을 했을 때는 이렇게 값을 참조해서 이용하는 수밖에 없을까?
	int &N = *n;
	int &M = *m;
	int &K = *k;

	cin >> N;
	cin >> M;
	cin >> K;

	while (K > 0 && M>0 && N>0) {
		if (2 * M < N) {
			N--;
			K--;
			continue;
		}
		else if (2 * M >= N) {
			M--;
			K--;
			continue;
		}
	}

	if (M == 0 | N == 0) {
		cout << 0;
	}
	else if (2 * M < N) {
		cout << M;
	}
	else if (2 * M >= N) {
		cout<< N / 2;
	}

	delete n;
	delete m;
	delete k;

	return 0;
}
