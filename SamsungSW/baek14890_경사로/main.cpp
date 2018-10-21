#include<stdio.h>
#include<iostream>
#include<algorithm>

int a[100][100];
int b[100][100];


int N, L;


int check(int i, int map[100][100]) {
	int num[11] = { 0 };
	int prev = map[i][0];
	bool bottom = false;
	bool top = false;
	num[prev]++;

	for (int j = 1; j < N; j++) {
		int data = map[i][j];
		num[data]++;
		// ���� ����� ���
		if (prev == map[i][j]) {

			// �������� �غ��Ϸ��� �������̸�
			if (bottom == true) {
				// �ٵ� �ű⼭ ������ŭ �׾Ҵٸ�
				if (num[data] == L) {
					num[data] = 0; // ��ٸ� ��ġ
					bottom = false;
				}
			}
		}
		// ���̰� 1�� �ƴ϶�� ��� �޾Ƶ��� �� ����.
		else if (abs(prev - data) != 1) {
			return 0;
		}
		// ���������� ���
		else if (prev - data == 1) {
			// �������ε� ������ false
			if (bottom == true) return 0;
			if (num[data] == L) {
				num[data] = 0;
				bottom = false;
			}
			else {
				bottom = true;
			}
		}
		// ���������� ���
		else if (data - prev == 1) {
			// �������ε� ������ false
			if (bottom == true) return 0;


			if (num[prev] < L) return 0;
			else {
				num[prev] = 0;
			}
		}

		// �� �����ߴµ� �����������̸� fail
		if (j == N - 1) {
			if (bottom == true)
				return 0;
		}

		prev = data;
	}
	return 1;
}




int main(void) {
	scanf("%d %d", &N, &L);
	int sum = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d",&a[i][j]);
			b[j][i] = a[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		//printf("%d %d\n", i, checkCol(i));
		sum += check(i,a);
		sum += check(i,b);
	}

	printf("%d", sum);

	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < N; j++) {
	//		printf("%d", map[i][j]);
	//	}
	//	printf("\n");
	//}
}