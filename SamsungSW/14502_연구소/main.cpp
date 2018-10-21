
// 연구소 30분만에 풀었음

#include<iostream>
#include<algorithm>
#include<stdlib.h>

using namespace std;

int R, C;
int map[8][8];
int infest[8][8];
int result;

bool isValid(int i, int j) {
	return i >= 0 && i < R && j >= 0 && j < C;
}

void dfs(int i, int j) {

	infest[i][j] = -3;

	if (isValid(i + 1, j) && infest[i + 1][j] == 0) {
		dfs(i + 1, j);
	}
	if (isValid(i - 1, j) && infest[i - 1][j] == 0) {
		dfs(i - 1, j);
	}
	if (isValid(i, j - 1) && infest[i][j - 1] == 0) {
		dfs(i, j - 1);
	}
	if (isValid(i, j + 1) && infest[i][j + 1] == 0) {
		dfs(i , j + 1);
	}
}

int sem(void) {
	// 구현해야할 부분
	int cnt = 0;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			infest[i][j] = map[i][j]; // 복사
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (infest[i][j] == 2) {
				dfs(i, j);
			}
		}
	}


	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (infest[i][j] == 0)
				cnt++;
		}
	}



	// ----------------
	//if (map[0][1] == 1 && map[1][0] == 1 && map[3][5] == 1) {
	//	for (int i = 0; i < R; i++) {
	//		for (int j = 0; j < C; j++) {
	//			printf("%2d", infest[i][j]);
	//		}
	//		printf("\n");
	//	}
	//}
	//if (cnt == 23) {
	//	for (int i = 0; i < R; i++) {
	//		for (int j = 0; j < C; j++) {
	//			printf("%2d", infest[i][j]);
	//		}
	//		printf("\n");
	//	}
	//}
	// ------------

	return cnt;
}

void func(int row, int now_cnt, int max_cnt) {
	if (now_cnt == max_cnt) {
		result = max(result, sem() );
		return;
	}


	for (int i = row; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				func(i, now_cnt+1, max_cnt);
				map[i][j] = 0;
			}
		}
	}

}



int main(void) {
	scanf("%d %d", &R, &C);

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	
	// row, now_cnt, max_cnt;
	func(0, 0, 3);

	printf("%d", result);

}