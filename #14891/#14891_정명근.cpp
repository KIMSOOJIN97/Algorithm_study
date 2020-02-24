/////////////////////////////////////////////////////////////
// title : 백준 14891 - 톱니바퀴(samsung coding test)
// date : 2020.01.19
// writer : jeong
// result : 
/////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
char Gear[4][8];
int K;
char* ptr1 = Gear[0];
char* ptr2 = Gear[1];
char* ptr3 = Gear[2];
char* ptr4 = Gear[3];
bool check[3];

using namespace std;


void Rotate(char* &ptr, int dir) {
	// 시계방향 회전
	if (dir == 1) {
		if (ptr == &Gear[0][7] || ptr == &Gear[1][7] || ptr == &Gear[2][7] || ptr == &Gear[3][7]) {
			ptr -= 7;
			return;
		}
		ptr += 1;
	}
	// 시계반대방향 회전
	else if (dir == -1) {
		if (ptr == &Gear[0][0] || ptr == &Gear[1][0] || ptr == &Gear[2][0] || ptr == &Gear[3][0]) {
			ptr += 7;
			return;
		}
		ptr -= 1;
	}
}
void dirChange(int &dir) {
	if (dir == 1) {
		dir = -1;
	}
	else if (dir == -1) {
		dir = 1;
	}
}

void Check() {
	for (int i = 0; i < 3; i++) {
		// 체크 배열 초기화
		check[i] = false;
	}
	if (*(ptr1 + 2) != *(ptr2 + 6))check[0] = true;
	if (*(ptr2 + 2) != *(ptr3 + 6))check[1] = true;
	if (*(ptr3 + 2) != *(ptr4 + 6))check[2] = true;
}


void Case(int mode, int dir) {
	// 한번 쓱 체크
	Check();
	int cnt = 0;

	switch (mode) {
	case 1:
		for (int i = 0; i < 3; i++) {
			if (check[i] == true) {
				cnt++;
			}
			else if (check[i] == false) {
				break;
			}
		}
		if (cnt == 0) {
			Rotate(ptr1, dir);
		}
		if (cnt == 1) {
			Rotate(ptr1, dir);
			dirChange(dir);
			Rotate(ptr2, dir);
		}
		else if (cnt == 2) {
			Rotate(ptr1, dir);
			Rotate(ptr3, dir);
			dirChange(dir);
			Rotate(ptr2, dir);
		}
		else if (cnt == 3) {
			Rotate(ptr1, dir);
			Rotate(ptr3, dir);
			dirChange(dir);
			Rotate(ptr2, dir);
			Rotate(ptr4, dir);
		}
		break;

	case 2:
		for (int i = 1; i < 3; i++) {
			if (check[i] == true) {
				cnt++;
			}
			else if (check[i] == false) {
				break;
			}
		}

		if (check[0] == true) {
			if (cnt == 0) {
				Rotate(ptr2, dir);
				dirChange(dir);
				Rotate(ptr1, dir);
			}
			if (cnt == 1) {
				Rotate(ptr2, dir);
				dirChange(dir);
				Rotate(ptr1, dir);
				Rotate(ptr3, dir);
			}
			if (cnt == 2) {
				Rotate(ptr2, dir);
				Rotate(ptr4, dir);
				dirChange(dir);
				Rotate(ptr1, dir);
				Rotate(ptr3, dir);
			}
		}
		else if (check[0] == false) {
			if (cnt == 0) {
				Rotate(ptr2, dir);
			}
			if (cnt == 1) {
				Rotate(ptr2, dir);
				dirChange(dir);
				Rotate(ptr3, dir);
			}
			if (cnt == 2) {
				Rotate(ptr2, dir);
				Rotate(ptr4, dir);
				dirChange(dir);
				Rotate(ptr3, dir);
			}
		}
		break;

	case 3:
		for (int i = 1; i >= 0; i--) {
			if (check[i] == true) {
				cnt++;
			}
			else if (check[i] == false) {
				break;
			}
		}

		if (check[2] == true) {
			if (cnt == 0) {
				Rotate(ptr3, dir);
				dirChange(dir);
				Rotate(ptr4, dir);
			}
			if (cnt == 1) {
				Rotate(ptr3, dir);
				dirChange(dir);
				Rotate(ptr2, dir);
				Rotate(ptr4, dir);
			}
			if (cnt == 2) {
				Rotate(ptr3, dir);
				Rotate(ptr1, dir);
				dirChange(dir);
				Rotate(ptr2, dir);
				Rotate(ptr4, dir);
			}
		}
		else if (check[2] == false) {
			if (cnt == 0) {
				Rotate(ptr3, dir);
			}
			if (cnt == 1) {
				Rotate(ptr3, dir);
				dirChange(dir);
				Rotate(ptr2, dir);
			}
			if (cnt == 2) {
				Rotate(ptr3, dir);
				Rotate(ptr1, dir);
				dirChange(dir);
				Rotate(ptr2, dir);
			}
		}
		break;

	case 4:
		for (int i = 2; i >= 0; i--) {
			if (check[i] == true) {
				cnt++;
			}
			else if(check[i]==false) {
				break;
			}
		}
		if (cnt == 0) {
			Rotate(ptr4, dir);
		}
		if (cnt == 1) {
			Rotate(ptr4, dir);
			dirChange(dir);
			Rotate(ptr3, dir);
		}
		else if (cnt == 2) {
			Rotate(ptr4, dir);
			Rotate(ptr2, dir);
			dirChange(dir);
			Rotate(ptr3, dir);
		}
		else if (cnt == 3) {
			Rotate(ptr4, dir);
			Rotate(ptr2, dir);
			dirChange(dir);
			Rotate(ptr3, dir);
			Rotate(ptr1, dir);
		}
		break;
	}
}


int main() {

	// 톱니 정보 저장
	for (int i = 0; i < 4; i++) {
		cin >> Gear[i];
	}
	// 앞으로의 회전 정보 저장
	cin >> K;
	for (int i = 0; i < K; i++) {
		int N_th, dir;
		cin >> N_th >> dir;
		Case(N_th, dir);
	}

	int result = 0;
	if (*ptr1 == '1')result += 1;
	if (*ptr2 == '1')result += 2;
	if (*ptr3 == '1')result += 4;
	if (*ptr4 == '1')result += 8;
	cout << result;


	return 0;
}
