#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

#define MAX 10

// 변수와 수식을 변수화할떄는 조심할 것 함부로 하지말것
// 블록 내에서 (변수와 수식)의 변수를 참조 할 수 있으므로
// 빨간색 공, 파란색 공 상태 초기화하는거 잊지말자..
// dir = 1, dir == 1 이거 구분하자..

int R, C; // N, M
char map[10][10];

int dirArr[4][2]{
	//위
	{-1, 0},
	//오른
	{ 0, 1},
	//아래
	{ 1,0},
	//왼
	{ 0, -1}
};

typedef struct point {
	int i;
	int j;
	bool check = false;

}POINT;

POINT red, blue;


int ans = 9999;

// 방향에 B가 있는 지 확인
bool check(char _map[10][10], int dir) {
	int pi = dirArr[dir][0];
	int pj = dirArr[dir][1];

	int cnt = 1;
	while (true) {

		if (_map[red.i + (pi * cnt)][red.j + (pj * cnt)] == '#' || _map[red.i + (pi * cnt)][red.j + (pj * cnt)] == 'O') {
			return false;
		}
		if (_map[red.i + (pi * cnt)][red.j + (pj * cnt)] == 'B') {
			return true;
			
		}
		cnt++;
	}
	return false;

}

int exe(int dir, int now) {
	int result = -10;

	// 4방향다 맞는거 돌아보기
	for (int l = 0; l < 4; l++) {
		if (dir == l) {
			int pi = dirArr[l][0];
			int pj = dirArr[l][1];
			// red 진행방향에 B가 있다면, 앞에 B가 있다면
			if (check( map, dir)) {
			//if (map[red.i + pi ][red.j + pj] == 'B') {
				// B움직
				while (map[blue.i + pi][blue.j + pj] == '.' || map[blue.i + pi][blue.j + pj] == 'O') {
					if (map[blue.i + pi][blue.j + pj] == 'O') {
						return -1;
					}

					map[blue.i][blue.j] = '.';

					if (dir == 0) blue.i--;
					else if (dir == 1) blue.j++;
					else if (dir == 2) blue.i++;
					else if (dir == 3) blue.j--;
						
					map[blue.i][blue.j] = 'B';
				}
				// R움직
				while (map[red.i + pi][red.j + pj] == '.' || map[red.i + pi][red.j + pj] == 'O') {
					if (map[red.i + pi][red.j + pj] == 'O') {
						return 0;
					}
					map[red.i][red.j] = '.';
					
					if (dir == 0) red.i--;
					else if (dir == 1) red.j++;
					else if (dir == 2) red.i++;
					else if (dir == 3) red.j--;
					// 현위치

					map[red.i][red.j] = 'R';
					
				}
			}
			else {
				// R움직
				while (map[red.i + pi][red.j + pj] == '.' || map[red.i + pi][red.j + pj] == 'O') {
					if (map[red.i + pi][red.j + pj] == 'O') {
						//printf("진입하니? : %d \n", now);
						result = 0;
						map[red.i][red.j] = '.';
						break;
					}

					map[red.i][red.j] = '.';
					
					if (dir == 0) red.i--;
					else if (dir == 1) red.j++;
					else if (dir == 2) red.i++;
					else if (dir == 3) red.j--;

					map[red.i][red.j] = 'R';
				}
				// B움직
				// 갈 수 있다면
				while (map[blue.i + pi][blue.j + pj] == '.' || map[blue.i + pi][blue.j + pj] == 'O') {
					if (map[blue.i + pi][blue.j + pj] == 'O') {
						return -1;
					}
					map[blue.i][blue.j] = '.';
					
					if (dir == 0) blue.i--;
					else if (dir == 1) blue.j++;
					else if (dir == 2) blue.i++;
					else if (dir == 3) blue.j--;

						
					map[blue.i][blue.j] = 'B';
				}
			}
			// 0이면 일찍 끝난거
			if (result == 0) {
				return 0;
			}

			// 그냥 굴린거
			return 1;

		}
	}


}

void dfs(int dir, int now) {
	char temp[10][10];


	if (now > MAX) {
		// 10번 초과했으면..
		return;
	}

	int re = exe(dir, now);

	// 0을 반환하면 이미 그안에 성공
	if (re == 0) {

		ans = min(ans, now);
		return;
	}
	if (re == -1) {
		// re가 -1이라는 건 그 회차에 실패했단 얘기
		return;
	}


	// 상태 다시 다 초기화 해야함
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			temp[i][j] = map[i][j];
			if (temp[i][j] == 'R') {
				red.i = i;
				red.j = j;
				red.check = false;
			}
			else if (temp[i][j] == 'B') {
				blue.i = i;
				blue.j = j;
				blue.check = false;
			}
		}
	}

	dfs(0, now + 1);

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			map[i][j] = temp[i][j];
			if (temp[i][j] == 'R') {
				red.i = i;
				red.j = j;
				red.check = false;
			}
			else if (temp[i][j] == 'B') {
				blue.i = i;
				blue.j = j;
				blue.check = false;
			}
		}
	}

	dfs(1, now + 1);

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			map[i][j] = temp[i][j];
			if (temp[i][j] == 'R') {
				red.i = i;
				red.j = j;
				red.check = false;
			}
			else if (temp[i][j] == 'B') {
				blue.i = i;
				blue.j = j;
				blue.check = false;
			}
		}
	}

	dfs(2, now + 1);

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			map[i][j] = temp[i][j];
			if (temp[i][j] == 'R') {
				red.i = i;
				red.j = j;
				red.check = false;
			}
			else if (temp[i][j] == 'B') {
				blue.i = i;
				blue.j = j;
				blue.check = false;
			}
		}
	}

	dfs(3, now + 1);
}


int main(void) {
	scanf("%d %d", &R, &C);
	char temp_main[10][10];

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> temp_main[i][j];

			if (temp_main[i][j] == 'R') {
				red.i = i;
				red.j = j;
				red.check = false;
			}
			else if (temp_main[i][j] == 'B') {
				blue.i = i;
				blue.j = j;
				blue.check = false;
			}
		}
	}
	
	//printf("** %d %d\n", red.i, red.j);

	//printf("** %d %d\n", blue.i, blue.j);

	//dfs(3, 10);
	//dfs(2, 10);
	//dfs(1, 10);
	//dfs(2, 10);
	//dfs(3, 10);
	//printf("%d\n", ans);

	for (int k = 0; k < 4; k++) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				map[i][j] = temp_main[i][j];
				if (temp_main[i][j] == 'R') {
					red.i = i;
					red.j = j;
					red.check = false;
				}
				else if (temp_main[i][j] == 'B') {
					blue.i = i;
					blue.j = j;
					blue.check = false;
				}
			}
		}
		dfs(k, 1);
	}


	//for (int i = 0; i < R; i++) {
	//	for (int j = 0; j < C; j++) {
	//		printf("%c", map[i][j]);
	//	}
	//	printf("\n");
	//}


	if (ans == 9999) ans = -1;
	printf("%d", ans);

}
