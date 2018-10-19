#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>

// 0 ������ x + 1
// 1 ���� y + 1
// 2 ���� x - 1
// 3 �Ʒ��� y - 1

int dir_axis[4][2] = {
	{1 , 0},
	{0 , -1},
	{-1, 0},
	{0 ,1}
};

// x -> 0~100
// y -> 0~100
int map[101][101];

// �巡���� ����
int N;

int result;

using namespace std;

typedef struct dragonInfo {
	int x;
	int y;
	int direct;
	int g;
}DRINFO;

// �� ������ ��� ���� "->" ���� 
vector<int> vc[11];

DRINFO draArr[20];

bool isValid(int x, int y) {
	return x >= 0 && x <= 100 && y >= 0 && y <= 100;
}

// ���簢�� ���� �Լ�
int squareCalc() {

	int cnt = 0;
	for (int  y = 0; y <= 99; y++) {
		for (int x = 0; x <= 99; x++) {
			if (map[x][y] == 1 &&
				map[x][y + 1] == 1 &&
				map[x + 1][y] == 1 &&
				map[x + 1][y + 1] == 1) {
				cnt++;
			}
		}
	}
	return cnt;
}

// �־��� �巡�� ���� �������� 100*100�� 1�� ��� �Լ�
void setPoint(DRINFO dra) {
	int x = dra.x;
	int y = dra.y;
	int direct = dra.direct;
	int g = dra.g;

	// direct �������� ���ؾ���.

	map[x][y] = 1;
	for (int i = 0; i < vc[g].size(); i++) {
		int realDirect = (vc[g][i] + direct) % 4;
		x = x + dir_axis[realDirect][0];
		y = y + dir_axis[realDirect][1];
	
		if(isValid(x,y))
			map[x][y] = 1;
	} 
}

// 0~10 ���� 0 �� �� �巡�� ���� ���
void calc() {
	for (int i = 1; i <= 10; i++) {
		vc[i] = vc[i - 1];
		int preLen = vc[i - 1].size();
		vector<int> temp;
		for (int j = preLen-1; j >= 0; j--) {
			// ������ �ٲ㼭 temp�� ����
			temp.push_back( (vc[i - 1][j] + 1) % 4 ); // +1 %4�� ����ü����
		}
		for (int j = 0; j < temp.size(); j++) {
			vc[i].push_back(temp[j]);
		}
	}
}

int main(void) {
	vc[0].push_back(0);
	calc();

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &draArr[i].x);
		scanf("%d", &draArr[i].y);
		scanf("%d", &draArr[i].direct);
		scanf("%d", &draArr[i].g);

		setPoint(draArr[i]);
	}
	result = squareCalc();

	//for (int i = 0; i < 11; i++) {
	//	for (int j = 0; j < vc[i].size(); j++)
	//	{
	//		printf("%d ", vc[i][j]);
	//	}
	//	printf("\n");
	//}

	//for (int y = 0; y <= 99; y++) {
	//	for (int x = 0; x <= 99; x++) {
	//		printf("%d", map[x][y]);
	//	}
	//	printf("\n");
	//}
	printf("%d", result);
}