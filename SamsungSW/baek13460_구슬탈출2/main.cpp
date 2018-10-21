#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

#define MAX 10

// ������ ������ ����ȭ�ҋ��� ������ �� �Ժη� ��������
// ��� ������ (������ ����)�� ������ ���� �� �� �����Ƿ�
// ������ ��, �Ķ��� �� ���� �ʱ�ȭ�ϴ°� ��������..
// dir = 1, dir == 1 �̰� ��������..

int R, C; // N, M
char map[10][10];

int dirArr[4][2]{
	//��
	{-1, 0},
	//����
	{ 0, 1},
	//�Ʒ�
	{ 1,0},
	//��
	{ 0, -1}
};

typedef struct point {
	int i;
	int j;
	bool check = false;

}POINT;

POINT red, blue;


int ans = 9999;

// ���⿡ B�� �ִ� �� Ȯ��
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

	// 4����� �´°� ���ƺ���
	for (int l = 0; l < 4; l++) {
		if (dir == l) {
			int pi = dirArr[l][0];
			int pj = dirArr[l][1];
			// red ������⿡ B�� �ִٸ�, �տ� B�� �ִٸ�
			if (check( map, dir)) {
			//if (map[red.i + pi ][red.j + pj] == 'B') {
				// B����
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
				// R����
				while (map[red.i + pi][red.j + pj] == '.' || map[red.i + pi][red.j + pj] == 'O') {
					if (map[red.i + pi][red.j + pj] == 'O') {
						return 0;
					}
					map[red.i][red.j] = '.';
					
					if (dir == 0) red.i--;
					else if (dir == 1) red.j++;
					else if (dir == 2) red.i++;
					else if (dir == 3) red.j--;
					// ����ġ

					map[red.i][red.j] = 'R';
					
				}
			}
			else {
				// R����
				while (map[red.i + pi][red.j + pj] == '.' || map[red.i + pi][red.j + pj] == 'O') {
					if (map[red.i + pi][red.j + pj] == 'O') {
						//printf("�����ϴ�? : %d \n", now);
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
				// B����
				// �� �� �ִٸ�
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
			// 0�̸� ���� ������
			if (result == 0) {
				return 0;
			}

			// �׳� ������
			return 1;

		}
	}


}

void dfs(int dir, int now) {
	char temp[10][10];


	if (now > MAX) {
		// 10�� �ʰ�������..
		return;
	}

	int re = exe(dir, now);

	// 0�� ��ȯ�ϸ� �̹� �׾ȿ� ����
	if (re == 0) {

		ans = min(ans, now);
		return;
	}
	if (re == -1) {
		// re�� -1�̶�� �� �� ȸ���� �����ߴ� ���
		return;
	}


	// ���� �ٽ� �� �ʱ�ȭ �ؾ���
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
