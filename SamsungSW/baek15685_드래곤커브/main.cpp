#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>

// 0 오른쪽 x + 1
// 1 위쪽 y + 1
// 2 왼쪽 x - 1
// 3 아래쪽 y - 1

int dir_axis[4][2] = {
	{1 , 0},
	{0 , -1},
	{-1, 0},
	{0 ,1}
};

// x -> 0~100
// y -> 0~100
int map[101][101];

// 드래곤의 갯수
int N;

int result;

using namespace std;

typedef struct dragonInfo {
	int x;
	int y;
	int direct;
	int g;
}DRINFO;

// 각 세대의 경로 저장 "->" 기준 
vector<int> vc[11];

DRINFO draArr[20];

bool isValid(int x, int y) {
	return x >= 0 && x <= 100 && y >= 0 && y <= 100;
}

// 정사각형 세는 함수
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

// 주어진 드래곤 정보 바탕으로 100*100에 1을 찍는 함수
void setPoint(DRINFO dra) {
	int x = dra.x;
	int y = dra.y;
	int direct = dra.direct;
	int g = dra.g;

	// direct 기준으로 더해야함.

	map[x][y] = 1;
	for (int i = 0; i < vc[g].size(); i++) {
		int realDirect = (vc[g][i] + direct) % 4;
		x = x + dir_axis[realDirect][0];
		y = y + dir_axis[realDirect][1];
	
		if(isValid(x,y))
			map[x][y] = 1;
	} 
}

// 0~10 방향 0 일 때 드래곤 방향 계산
void calc() {
	for (int i = 1; i <= 10; i++) {
		vc[i] = vc[i - 1];
		int preLen = vc[i - 1].size();
		vector<int> temp;
		for (int j = preLen-1; j >= 0; j--) {
			// 방향을 바꿔서 temp에 저장
			temp.push_back( (vc[i - 1][j] + 1) % 4 ); // +1 %4는 방향체인지
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