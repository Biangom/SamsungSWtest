#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

int test(int);

// ** 오류 
// map[31][11] 11과 31을 자리를 바꿔놓고 코드를 작성하는 바람에
// 오류찾느라 1시간 소요..

int map[31][11];
int N, M, H; // M 가로선에 놓을 수 있는 갯수
// H행 , N열

int result;



// 입력
// (열, 가로선갯수, 행)
// 가로선 정보 (행, 열)

typedef struct pos{
	int r;
	int c;
}POS;

POS p;

bool testFunc(void) {
	for (int i = 1; i <= N; i++) {
		if (i != test(i)) {
			return false;
		}
	}
	return true;
}
int test(int col) {
	p.r = 1;
	p.c = col;

	while (true) {
		if (map[p.r][p.c] == 1) p.c += 1;
		else if (map[p.r][p.c - 1] == 1) p.c -= 1;

		if (p.r >= H) break;

		p.r++;

		while (map[p.r][p.c] != 1 && map[p.r][p.c -1 ] != 1 && p.r < H) {
			p.r++;
		}
	}
	return p.c;
}

// row부터 탐색시작
// cnt 현재 사용한 사다리 갯 수
void func(int row, int cnt, int max) {
	if (cnt == max) {
		if (testFunc()) {
			result = cnt;
			return;
		}
		return;
	}

	for (int i = row; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			// 양쪽 방문 안했을 시
			if (map[i][j - 1] + map[i][j + 1] + map[i][j] == 0) {
				map[i][j] = 1;
				func(row, cnt + 1, max);
				map[i][j] = 0;
			}
		}
	}

}

int main(void) {
	scanf("%d %d %d", &N, &M, &H); // H행 , N열
	for (int i = 0; i < M; i++) {
		int di, dj;
		scanf("%d %d", &di, &dj);
		map[di][dj] = 1;
	}

	result = -1; // 사다리 갯수
	for (int i = 0; i < 4; i++) {
		// 행, 갯수, 최대갯수
		func(1, 0, i);
		if (result != -1) break;
	}
	printf("%d\n", result);
}

//if (result != -1) return;
//
//if (cnt == max) {
//	if (testFunc()) {
//		result = cnt;
//	}
//	return;
//}
//
//for (int i = row; i <= H; i++) {
//	for (int j = 1; j <= N; j++) {
//		// 양쪽 방문 안했을 시
//		if (map[i][j - 1] + map[i][j + 1] + map[i][j] == 0) {
//			map[i][j] = 1;
//			func(i, cnt + 1, max);
//			map[i][j] = 0;
//		}
//	}
//}