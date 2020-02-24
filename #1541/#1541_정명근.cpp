/////////////////////////////////////////////////////////////
// title : (Greedy Algorithm) 백준 1541
// date : 2020.01.05
// writer : jeong
// result : queue 이용해서 구현해봤는데... 
//          cin으로 안받고, scanf로 받았으면 하나씩 잘라서 받을 수 있었다. 
//          하나씩 잘라서 받으면 바로바로 더하면 됐을텐데..
//          쉬운문젠데,, 어렵게 갔다. 
/////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int changetoNum(int start, int end, string sentence) {
	// start 는 숫자 시작 인덱스,
	// end 는 연산자 나오는 인덱스

	int result = 0;
	for (start ; start < end ; start++) {
		result = result*10 + sentence[start] - 48;
	}
	return result;
}


int main() {

	string sentence;
	cin >> sentence;
	int start = 0;


	queue<int>num;
	queue<char>oper;


	for (int i = 0; i < sentence.size(); i++) {
		if ((sentence[i] == '+') | (sentence[i] == '-')) {

			int number = changetoNum(start, i, sentence);
			num.push(number);
			oper.push(sentence[i]);

			start = i + 1;
		}
		else if(i == sentence.size()-1){
			// 마지막 숫자 저장
			num.push(changetoNum(start, i + 1, sentence));
		}
	}

	int result = num.front();
	num.pop();

	int negative = 0;

	int mode = 0;

	while (!(num.empty())) {
		switch (mode) {

		case 0: // 맨처음 양수 더하는 구간
			if (oper.front() == '-') {
				mode = 1;
				break;
			}
			// 맨 앞의 부호가 + 이다.
			oper.pop();
			result += num.front();
			num.pop();
			break;


		case 1: // - 하나라도 만난 구간
			// 맨 앞의 부호가 - 이다.
			oper.pop();
			negative += num.front();
			num.pop();
			break;
		}
	}
	cout << result - negative;

	return 0;
}
