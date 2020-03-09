/////////////////////////////////////////////////////////////
// title : 백준 14888 - DFS. 꼴 2
// date : 2020.01.13
// writer : jeong
// result : https://suriisurii.tistory.com/11  -> 똘똘하다. psmd 받아서 plus, sub, multi, divi를 증가시킨다. 
// 문제   : https://www.acmicpc.net/problem/14888
/////////////////////////////////////////////////////////////

#include<iostream>
#include<algorithm>
using namespace std;
int maxN = -100000000, minN = 1000000000;
int n, a[12], p, s, m, d;
void DFS(int index, int plus, int sub, int multi, int divi, int total) {
	// DFS가 index, plus, sub, multi, divi, total 다 들고다닌다.
	if (index == n) {
		maxN = max(maxN, total);
		minN = min(minN, total);
		return;
	}
	if (plus > 0)
		DFS(index + 1, plus - 1, sub, multi, divi, total + a[index]);
	if (sub > 0)
		DFS(index + 1, plus, sub - 1, multi, divi, total - a[index]);
	if (multi > 0)
		DFS(index + 1, plus, sub, multi - 1, divi, total * a[index]);
	if (divi > 0)
		DFS(index + 1, plus, sub, multi, divi - 1, total / a[index]);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> p >> s >> m >> d;
	DFS(1, p, s, m, d, a[0]);
	cout << maxN << endl << minN << endl;
	return 0;
}


/////////////////////////////////////////////////////////////
// title : 백준 14888 - DFS. 꼴 2
// date : 2020.01.13
// writer : jeong
// result : https://suriisurii.tistory.com/11  -> 똘똘하다. psmd 받아서 plus, sub, multi, divi를 증가시킨다. 
// 문제   : https://www.acmicpc.net/problem/14888
/////////////////////////////////////////////////////////////

#include<iostream>
#include<algorithm>
using namespace std;
int maxN = -100000000, minN = 1000000000;
int n, a[12], p, s, m, d;
void DFS(int index, int plus, int sub, int multi, int divi, int total) {
	// DFS가 index, plus, sub, multi, divi, total 다 들고다닌다.
	if (index == n) {
		maxN = max(maxN, total);
		minN = min(minN, total);
		return;
	}
	if (plus < p)
		DFS(index + 1, plus + 1, sub, multi, divi, total + a[index]);
	if (sub < s)
		DFS(index + 1, plus, sub + 1, multi, divi, total - a[index]);
	if (multi < m)
		DFS(index + 1, plus, sub, multi + 1, divi, total * a[index]);
	if (divi < d)
		DFS(index + 1, plus, sub, multi, divi + 1, total / a[index]);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> p >> s >> m >> d;
	DFS(1, 0, 0, 0, 0, a[0]);
	cout << maxN << endl << minN << endl;
	return 0;
}


/////////////////////////////////////////////////////////////
// title : 백준 14888 - DFS. 꼴 1
// date : 2020.01.13
// writer : jeong
// result : https://dongyeollee.github.io/2018/04/13/Al/14888/   
//           부호 데이터를 DFS 들어갈때는 하나 차감했다가, 탈출했을때는 다시 하나 원상복구 해주는 소스
// 문제   : https://www.acmicpc.net/problem/14888
/////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int max_int = -1000000001;
int min_int = 1000000001;
int N; // N 최대는 11이다.
vector<int>op(4); // 0 : + / 1 : - / 2 : x / 3  : %
vector<int>num(11);

void DFS(int index, int result) {
	if (index == N) {
		max_int = max(max_int, result);
		min_int = min(min_int, result);
	}

	if (op[0] > 0) { // 덧셈
		op[0]--;
		DFS(index + 1, result + num[index]);
		op[0]++; // DFS에서 빠져나오면 다시 원상복구 시켜놔야한다.
	}
	if (op[1] > 0) { // 뺄셈
		op[1]--;
		DFS(index + 1, result - num[index]);
		op[1]++;
	}
	if (op[2] > 0) { // 곱셈
		op[2]--;
		DFS(index + 1, result * num[index]);
		op[2]++;
	}
	if (op[3] > 0) { // 나눗셈
		op[3]--;
		DFS(index + 1, result / num[index]);
		op[3]++;
	}
}


int main() {
	// cin 속도 향상
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	DFS(1, num[0]);

	cout << max_int << '\n' << min_int;

	return 0;
}//
