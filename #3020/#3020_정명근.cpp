/////////////////////////////////////////////////////////////
// title : 백준 3020 개똥벌레 문제 retry 
// date : 2019.12.24
// writer : jeong
// result : upper_bound, lower_bound 이진탐색 방법 사용
//     (ref) https://jaimemin.tistory.com/1109
/////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void)

{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, H;
	int sum = 0;
	int min = 200001, count = 0;
	cin >> N >> H;

	vector<int> top(N / 2), bottom(N / 2);

	// 데이터 입력
	for (int i = 0; i < N/2; i++) {
		cin >> bottom[i] >> top[i];
	}

	// 정렬
	sort(bottom.begin(), bottom.end());
	sort(top.begin(), top.end());


	for (int i = 0; i < H; i++) {

		// 석순 세기
		sum = bottom.size() - (lower_bound(bottom.begin(), bottom.end(), i + 1) - bottom.begin());

		// 종유석 세기
		sum += top.size() - (upper_bound(top.begin(), top.end(), H - i - 1) - top.begin());

		if (min > sum) {
			count = 1;
			min = sum;
		}
		else if (min == sum) {
			count++;
		}
	}

	cout << min << " " << count << "\n";

	return 0;

}

/////////////////////////////////////////////////////////////
// title : 백준 3020 개똥벌레 문제
// date : 2019.12.24
// writer : jeong
// result : 시간제한 1초인데 오바됨....
//          but 동적 할당에 대해서 자세히 알게됨
/////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

void stack(int i, int number, int* (&ref), int H) {
	if (i % 2 == 0) { // 짝수일때
		for (int i = 0; i < number; i++) {
			ref[i]++;
		}
	}
	else { // 홀수일때
		for (int i = 0; i < number; i++) {
			ref[H - 1 - i]++;
		}
	}
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);       // cin 속도 향상 위해

	int N, H, number;
	int min=200001, count;
	cin >> N >> H;

	//vector<int>sum(N);


	// 배열 동적 메모리 할당 ( N이라는놈이 runtime 중
	// 입력되므로 runtime중 heap영역에서 새로이 배열을 할당해주기 위해)
	int *sum    = new int[H];

	// 배열 초기화
	memset(sum, 0, H * sizeof(int));

	// 숫자 읽기
	for (int i=0; i < N; i++) {

		cin >> number;

		// 방법 1.
		stack(i, number, sum, H); // 이렇게 할수도 있다~ ref배웠다~

		// 방법 2.
		//if (i % 2 == 0) { // 짝수일때
		//	for (int i = 0; i < number; i++) {
		//		sum[i]++;
		//	}
		//}
		//else { // 홀수일때
		//	for (int i = 0; i < number; i++) {
		//		sum[H - 1 - i]++;
		//	}
		//}
	}

	// 최소값 카운팅
	for (int i = 0; i < H; i++) {
		if (sum[i] < min) {
			min = sum[i];
			count = 1;
		}
		else if (sum[i] == min) {
			count++;
		}
	}
	cout << min << " " << count;

	delete sum;

	return 0;

	//// (잠깐!) 동적할당 학습
	//int * ip = new int; // 새로운 int 형 변수 동적할당함.
	//// new int 하면 동적할당 메모리의 첫주소값을 반환한다.
	//// 그러므로 저장할 포인터값이 필요하다.
	//int &R = *ip; // ip 안에 들어있는 값을 R이 참조한것.
	//// int &R = ip 하면 안되는게, 이러면 그냥 int 값이 포인터값을 참조하게 되는 꼴이 되므로.
	//R = 100;

	//cout << ip << "\n"; // 그래서 ip 출력하면 새로 동적할당된 메모리의 첫 주소를 가리키는 것이고
	//cout << *ip << "\n"; // ip가 갖고있는 값은 R이 참조를 통해 100으로 초기화 해줫으므로 100
	//cout << &ip << "\n"; // ip 라는 포인터의 주소값은 ip가 가리키는 동적할당된 메모리의 첫 주소와는 다르지~~
	//cout << R << "\n";
	////cout << *R << "\n";
	//cout << &R << "\n"; // R의 주소값. ip 와 완전히 동일하므로, ip의 주소값과 같다.
	//delete ip;


}
