#include<stdio.h>
#include<algorithm>
#include<iostream>

#include<stdlib.h>

// �ð��� ����
// ���α׷� ó�� ������ �߸��ؼ� �׷��Ե�
// Ž�� ������ ���� �κ��� Ž�� �������� �ٲپ�����ϴµ� �װ� ����. (check�ϴµ� �����ɸ�)
// system("cls"), system("pause") stdlib.h�� Ȱ���ؼ� ���� check�ϴ°� �����ذ��Ҷ� ���� ��
// �׸��� ������ ��Ȯ�� �����ϴ°� ������..
// robot.dir = nowDir;

// 69�� �ҿ�

typedef struct point {
	int i;
	int j;
	int dir;
}POINT;

int init[50][50];
int N, M;

// 0 ��
// 1 ����
// 2 �Ʒ�
// 3 ����

int dir[4][2] = {
	{-1, 0},
	{ 0, 1},
	{ 1, 0},
	{ 0,-1}
};

POINT robot;

void clean() {
	int nowDir;

	int dirRow; // Ž���� ���� ���� row ����
	int dirCol; // 
	int dirVal; // û���� ������ �κ��� ��
	int cnt = 0; // ȸ���� ��������� �� ��

	while(true) {
		if (init[robot.i][robot.j] == 0) {
			init[robot.i][robot.j] = 2; // û��!
			/*system("cls");
			
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					printf("%2d", init[i][j]);
				}
				printf("\n");
			}
			system("pause");*/
		
		}
		nowDir = (robot.dir + 3) % 4; // Ž���� ���� (���ع������� ����)
		dirRow = dir[nowDir][0];
		dirCol = dir[nowDir][1];
		dirVal = init[robot.i + dirRow][robot.j + dirCol];
		// �� ���⿡ û���Ұ� �����ִٸ�
		if (dirVal == 0) {
			// �� �������� �̵�
			robot.i += dirRow;
			robot.j += dirCol;
			 // ������ �ٲ��.
			cnt = 0;
			robot.dir = nowDir;
		}
		// �� ������ û�Ұ� �����ų� ���̶�� 
		// 1. 4���� ��� Ž���Ͽ� �����ؾ��Ѵ�.
		else {
			cnt++;
			robot.dir = nowDir;
			if (cnt == 4) {
				int b_Row = dir[nowDir][0] * -1;
				int b_Col = dir[nowDir][1] * -1;
				// �ڷο� �ִ°� ���̶��
				if (init[robot.i + b_Row][robot.j + b_Col] == 1) {
					return; // �׷� ��
				}
				// �ڷ� �̵�
				else {
					robot.i = robot.i + b_Row;
					robot.j = robot.j + b_Col;
				}
				cnt = 0;
			}
		}
		

	}
}

// 0 ��
// 1 ����
// 2 �Ʒ�
// 3 ����

int main(void) {
	int result = 0;
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &robot.i, &robot.j, &robot.dir);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &init[i][j]);
		}
	}


	clean();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (init[i][j] == 2) result++;
		}
	}


	//printf("%d %d\n", N, M);
	//printf("%d %d %d\n", robot.i, robot.j, robot.dir);
	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < M; j++) {
	//		printf("%2d", init[i][j]);
	//	}
	//	printf("\n");
	//}

	printf("%d\n", result);



	
	

}