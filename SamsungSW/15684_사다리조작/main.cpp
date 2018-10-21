#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

int test(int);

// ** ���� 
// map[31][11] 11�� 31�� �ڸ��� �ٲ���� �ڵ带 �ۼ��ϴ� �ٶ���
// ����ã���� 1�ð� �ҿ�..

int map[31][11];
int N, M, H; // M ���μ��� ���� �� �ִ� ����
// H�� , N��

int result;



// �Է�
// (��, ���μ�����, ��)
// ���μ� ���� (��, ��)

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

// row���� Ž������
// cnt ���� ����� ��ٸ� �� ��
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
			// ���� �湮 ������ ��
			if (map[i][j - 1] + map[i][j + 1] + map[i][j] == 0) {
				map[i][j] = 1;
				func(row, cnt + 1, max);
				map[i][j] = 0;
			}
		}
	}

}

int main(void) {
	scanf("%d %d %d", &N, &M, &H); // H�� , N��
	for (int i = 0; i < M; i++) {
		int di, dj;
		scanf("%d %d", &di, &dj);
		map[di][dj] = 1;
	}

	result = -1; // ��ٸ� ����
	for (int i = 0; i < 4; i++) {
		// ��, ����, �ִ밹��
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
//		// ���� �湮 ������ ��
//		if (map[i][j - 1] + map[i][j + 1] + map[i][j] == 0) {
//			map[i][j] = 1;
//			func(i, cnt + 1, max);
//			map[i][j] = 0;
//		}
//	}
//}