
#include  <stdio.h>

int map[501][501];
int visit[501][501];
int N;

int max = 0;

int vectX[4] = { 0,1,0,-1 };
int vectY[4] = { 1,0,-1,0 };


void dfsMap(int y, int x) {
	int nextX, nextY;
	int value = 0;
	for (int i = 0; i<4; i++)
	{
		nextX = x + vectX[i];
		nextY = y + vectY[i];

		if (nextX >= N || nextX<0 || nextY >= N || nextY<0)
			continue;

		if (map[nextY][nextX] < map[y][x])
		{
			if (visit[nextY][nextX] == 0)
				dfsMap(nextY, nextX);


			if (value < visit[nextY][nextX])
				value = visit[nextY][nextX];
		}

	}

	visit[y][x] = value + 1;

	if (max<visit[y][x])
		max = visit[y][x];
}



int main(void)
{

	scanf("%d", &N);

	for (int i = 0; i<N; i++)
		for (int j = 0; j<N; j++)
			scanf("%d", &map[i][j]);


	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++)
		{
			if (visit[i][j] == 0)
				dfsMap(i, j);

		}
	}

	printf("%d\n", max);
	return 0;
}


//#include<stdio.h>
//#include<algorithm>
//#include<iostream>
//
//// 내 풀이
//// if (내꺼 + 1 >= 작은애들.갯수) { 작은애.갯수 = 내꺼 + 1), 작은애 주위애 작은애도 +1
//// if (내주위에 큰거?) if(나 == 0) 나 = 1
//typedef struct point {
//	int num;
//	int cnt = 0;
//
//}POINT;
//
//
//int N;
//
//POINT** map;
//
//int dir[4][2] = {
//	{-1 , 0}, //위
//	{ 0 , 1}, // 오른
//	{ 1 , 0}, // 아래
//	{ 0 ,-1} // 왼
//};
//
//bool isValid(int i, int j) {
//	return i >= 0 && i < N && j >= 0 && j < N;
//}
//void recur(int r, int c) {
//	for (int k = 0; k < 4; k++) {
//		int dirRow = r + dir[k][0];
//		int dirCol = c + dir[k][1];
//
//		// 각 위 , 오른, 아래, 왼이 유효하고
//		if (isValid(dirRow, dirCol)) {
//			// 그리고 그게 나보다 작고
//			if (map[dirRow][dirCol].num <= map[r][c].num) {
//				// cnt가 내꺼 +1 보다 작을경우
//				if (map[dirRow][dirCol].cnt <= map[r][c].cnt + 1) {
//					// 짝은애 = 내꺼 + 1
//					map[dirRow][dirCol].cnt = map[r][c].cnt + 1;
//					recur(dirRow, dirCol);
//				}
//			}
//		}
//
//	}
//}
//void func() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			// 4방향 탐색
//			//for (int k = 0; k < 4; k++) {
//			//	int dirRow = i + dir[k][0];
//			//	int dirCol = j + dir[k][1];
//
//			//	// 각 위 , 오른, 아래, 왼이 유효하다면
//			//	if (isValid(dirRow, dirCol) ) {
//			//		// 그리고 그게 나보다 숫자가 크다면
//			//		if (map[dirRow][dirCol].num >= map[i][j].num) {
//			//			map[i][j].cnt = 1;
//			//		}
//			//	}
//			//}
//
//			for (int k = 0; k < 4; k++) {
//				int dirRow = i + dir[k][0];
//				int dirCol = j + dir[k][1];
//
//				// 각 위 , 오른, 아래, 왼이 유효하다면
//				if (isValid(dirRow, dirCol)) {
//					// 그리고 그게 나보다 작고
//					if (map[dirRow][dirCol].num <= map[i][j].num) {
//						// cnt가 내꺼 +1 보다 작을경우
//						if (map[dirRow][dirCol].cnt <= map[i][j].cnt) {
//							// 짝은애 = 내꺼 + 1
//							map[dirRow][dirCol].cnt = map[i][j].cnt + 1;
//							recur(dirRow, dirCol);
//						}
//					}
//				}
//			}
//		}
//
//	}
//}
//
//int main(void) {
//	scanf("%d", &N);
//
//	map = new POINT*[N];
//	for (int i = 0; i < N; i++) {
//		map[i] = new POINT[N];
//	}
//	//** 동적할당 끝
//
//	
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			scanf("%d", &map[i][j].num);
//		}
//	}
//
//
//
//	func();
//
//
//	/*for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			printf("%d ", map[i][j].cnt);
//		}
//		printf("\n");
//	}*/
//
//	int max = map[0][0].cnt;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			if (map[i][j].cnt > max) max = map[i][j].cnt;
//		}
//	}
//
//	printf("%d", max+1);
//
//
//
//
//
//	//** 메모리 해제
//	for (int i = 0; i < N; i++) {
//		delete[] map[i];
//	}
//	delete[] map;
//}