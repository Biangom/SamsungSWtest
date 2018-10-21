#include<stdio.h>
#include<algorithm>
#include<iostream>

#include<stdlib.h>

// 시간끈 요인
// 프로그램 처리 순서를 잘못해서 그렇게됨
// 탐색 방향을 현재 로봇의 탐색 방향으로 바꾸어줘야하는데 그걸 못함. (check하는데 오래걸림)
// system("cls"), system("pause") stdlib.h를 활용해서 상태 check하는거 문제해결할때 좋은 듯
// 그리고 문제를 정확히 이해하는게 좋을듯..
// robot.dir = nowDir;

// 69분 소요

typedef struct point {
	int i;
	int j;
	int dir;
}POINT;

int init[50][50];
int N, M;

// 0 위
// 1 오른
// 2 아래
// 3 왼쪽

int dir[4][2] = {
	{-1, 0},
	{ 0, 1},
	{ 1, 0},
	{ 0,-1}
};

POINT robot;

void clean() {
	int nowDir;

	int dirRow; // 탐색할 방향 기준 row 증감
	int dirCol; // 
	int dirVal; // 청소할 예정인 부분의 값
	int cnt = 0; // 회전을 몇번하지는 지 셈

	while(true) {
		if (init[robot.i][robot.j] == 0) {
			init[robot.i][robot.j] = 2; // 청소!
			/*system("cls");
			
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					printf("%2d", init[i][j]);
				}
				printf("\n");
			}
			system("pause");*/
		
		}
		nowDir = (robot.dir + 3) % 4; // 탐색할 방향 (기준방향으로 왼쪽)
		dirRow = dir[nowDir][0];
		dirCol = dir[nowDir][1];
		dirVal = init[robot.i + dirRow][robot.j + dirCol];
		// 그 방향에 청소할게 남아있다면
		if (dirVal == 0) {
			// 그 방향으로 이동
			robot.i += dirRow;
			robot.j += dirCol;
			 // 방향은 바뀐다.
			cnt = 0;
			robot.dir = nowDir;
		}
		// 그 방향이 청소가 끝난거나 벽이라면 
		// 1. 4방향 모두 탐색하여 후진해야한다.
		else {
			cnt++;
			robot.dir = nowDir;
			if (cnt == 4) {
				int b_Row = dir[nowDir][0] * -1;
				int b_Col = dir[nowDir][1] * -1;
				// 뒤로에 있는게 벽이라면
				if (init[robot.i + b_Row][robot.j + b_Col] == 1) {
					return; // 그럼 끝
				}
				// 뒤로 이동
				else {
					robot.i = robot.i + b_Row;
					robot.j = robot.j + b_Col;
				}
				cnt = 0;
			}
		}
		

	}
}

// 0 위
// 1 오른
// 2 아래
// 3 왼쪽

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