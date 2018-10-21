#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>

// 피드백
// t[num -1] / t[num-1]%2 와 비슷한 연산이 많기 때문에
// 저렇게 변수와 수식이 붙어있는걸 변수로 합하는 것이 중요..
// 그 실수 때문에 1시간 소비한듯.

using namespace std;

int K; // 회전 횟수
int result;


// 회전하는 번호와
// 회전하는 방향

int deciPow(int x) {
	int sum = 1;
	for (int i = 0; i < x; i++) {
		sum *= 10;
	}
	return sum;
}

int binPow(int x) {
	int sum = 1;
	for (int i = 0; i < x; i++) {
		sum *= 2;
	}
	return sum;
}


typedef struct info{
	int num;
	int dir;
}INFO;

typedef struct wheel{
	int top = 7;
	int left = 1;
	int right = 5;
	int data;
}WHEEL;

// 톱니바퀴 4개 선언
// 비트 연산자로 할 예정
WHEEL t[5];
int isChange[5];

//vector<INFO> v;

// 1 시계  t가 뒤로
// -1 반시계 t가 앞으로
void exe(int num, int dir) {

	isChange[num] = 1;
	// 이전에 싹다 바뀌고
	if (num == 2 || num == 3) {
		int center_left = (t[num].data / (1 << t[num].left)) % 2;
		int center_right = (t[num].data / (1 << t[num].right)) % 2;

		// center left와 right가 맞물리다면
		if (center_left != (t[num - 1].data / (1 << t[num-1].right)) % 2) {
			// num - 1도 돌게 해야한다.
			// 근데 반대 방향으로
			if (isChange[num - 1] == 0) {
				isChange[num - 1] = 1;
				exe(num - 1, dir * -1);
			}

		}

		// center right와 left가 맞물리다면
		if (center_right != (t[num + 1].data / (1 << t[num+1].left)) % 2) {
			if (isChange[num + 1] == 0) {
				isChange[num + 1] = 1;
				exe(num + 1, dir * -1);
			}
		}
	}
	// 맨 왼쪽
	else if (num == 1) {
		int temp = 1 << t[num].top;
		int center_right = (t[num].data / (1 << t[num].right)) % 2;

		// center right와 left가 맞물리다면
		if (center_right != (t[num + 1].data / (1 << t[num+1].left)) % 2) {
			if (isChange[num+1] == 0) {
				isChange[num+1] = 1;
				exe(num + 1, dir * -1);
			}
		}

	}
	// 맨 오른쪽
	else if (num == 4) {
		int temp = 1 << t[num].top;
		int center_left = (t[num].data / (1 << t[num].left)) % 2;

		// center left와 right가 맞물리다면
		if (center_left != (t[num - 1].data / (1 << t[num-1].right)) % 2) {
			// num - 1도 돌게 해야한다.
			// 근데 반대 방향으로
			if (isChange[num-1] == 0) {
				isChange[num-1] = 1;
				exe(num - 1, dir * -1);
			}
		}
	}

	// t 바꾸기
	if (dir == 1) { // 시계방향이면
		t[num].top = (t[num].top + 1) % 8;
		t[num].left = (t[num].left + 1) % 8;
		t[num].right = (t[num].right + 1) % 8;
	}
	else if (dir == -1) {
		t[num].top = (t[num].top + 7) % 8;
		t[num].left = (t[num].left + 7) % 8;
		t[num].right = (t[num].right + 7) % 8;
	}
}

void calc() {
	
	for (int i = 1; i <= 4; i++) {
		if ( ((t[i].data / (1 << t[i].top)) % 2) == 1) {
			result += 1 << i-1;
		}
	}
}

int main(void) {
	int data;
	
	
	for (int k = 1; k <= 4; k++) {
		int bin = 0;
		int sum = 0;
		scanf("%d", &data);
		for (int i = 0; i < 8; i++) {
			bin = (data / deciPow(i)) % 10;
			bin = bin * binPow(i);
			sum += bin;
		}
		t[k].data = sum;
		//printf("%d\n", t[k].data);
	}


	scanf("%d", &K);

	while (K--) {
		INFO temp;
		scanf("%d %d", &temp.num, &temp.dir);

		for (int i = 0; i < 5; i++)
			isChange[i] = 0;
		exe(temp.num, temp.dir);


		//v.push_back(temp);
	}
	// N극 0
	// S극 1

	//for (int i = 1; i <= 4; i++) {
	//	printf("** %d\n", t[i].data);
	//}
	calc();

	printf("%d ", result);

	
	//printf("%d\n", 1 << 7);


}