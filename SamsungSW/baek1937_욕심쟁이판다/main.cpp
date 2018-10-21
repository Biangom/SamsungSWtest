
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
//// �� Ǯ��
//// if (���� + 1 >= �����ֵ�.����) { ������.���� = ���� + 1), ������ ������ �����ֵ� +1
//// if (�������� ū��?) if(�� == 0) �� = 1
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
//	{-1 , 0}, //��
//	{ 0 , 1}, // ����
//	{ 1 , 0}, // �Ʒ�
//	{ 0 ,-1} // ��
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
//		// �� �� , ����, �Ʒ�, ���� ��ȿ�ϰ�
//		if (isValid(dirRow, dirCol)) {
//			// �׸��� �װ� ������ �۰�
//			if (map[dirRow][dirCol].num <= map[r][c].num) {
//				// cnt�� ���� +1 ���� �������
//				if (map[dirRow][dirCol].cnt <= map[r][c].cnt + 1) {
//					// ¦���� = ���� + 1
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
//			// 4���� Ž��
//			//for (int k = 0; k < 4; k++) {
//			//	int dirRow = i + dir[k][0];
//			//	int dirCol = j + dir[k][1];
//
//			//	// �� �� , ����, �Ʒ�, ���� ��ȿ�ϴٸ�
//			//	if (isValid(dirRow, dirCol) ) {
//			//		// �׸��� �װ� ������ ���ڰ� ũ�ٸ�
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
//				// �� �� , ����, �Ʒ�, ���� ��ȿ�ϴٸ�
//				if (isValid(dirRow, dirCol)) {
//					// �׸��� �װ� ������ �۰�
//					if (map[dirRow][dirCol].num <= map[i][j].num) {
//						// cnt�� ���� +1 ���� �������
//						if (map[dirRow][dirCol].cnt <= map[i][j].cnt) {
//							// ¦���� = ���� + 1
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
//	//** �����Ҵ� ��
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
//	//** �޸� ����
//	for (int i = 0; i < N; i++) {
//		delete[] map[i];
//	}
//	delete[] map;
//}