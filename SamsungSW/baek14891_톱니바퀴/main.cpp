#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int K; // ȸ�� Ƚ��
int result;


// ȸ���ϴ� ��ȣ��
// ȸ���ϴ� ����

int deciPow(int x) {
	int sum = 1;
	for (int i = 0; i < x; i++) {
		sum *= 10;
	}
	return sum;
}

int binPow(int x) {
	int sum = 1;
	for (int i = 0; i < x; i++) {
		sum *= 2;
	}
	return sum;
}


typedef struct info{
	int num;
	int dir;
}INFO;

typedef struct wheel{
	int top = 7;
	int left = 1;
	int right = 5;
	int data;
}WHEEL;

// ��Ϲ��� 4�� ����
// ��Ʈ �����ڷ� �� ����
WHEEL t[5];

vector<INFO> v;

// 1 �ð�  t�� �ڷ�
// -1 �ݽð� t�� ������
void exe(int num, int dir) {

	// ������ �ϴ� �ٲ��
	if (num != 4 && num != 1) {
		int temp = 1 << t[num].top;
		int center_left = (t[num].data / (1 << t[num].left) ) % 2;
		int center_right = (t[num].data / (1 << t[num].right) ) % 2;


		if (center_left != (t[num - 1].data / (1 << t[num].right) ) % 2) {
			// num - 1�� ���� �ؾ��Ѵ�.
			// �ٵ� �ݴ� ��������
			exe(num - 1, dir * -1);
		}
		if (center_right != (t[num + 1].left / (1 << t[num].left) ) % 2) {
			exe(num + 1, dir * -1);
		}
	}

	// t �ٲٱ�
	if (dir == 1) { // �ð�����̸�
		t[num].top = (t[num].top + 1) % 8;
		t[num].left = (t[num].left + 1) % 8;
		t[num].right = (t[num].right + 1) % 8;
	}
	else if (dir == -1) {
		t[num].top = (t[num].top + 7) % 8;
		t[num].left = (t[num].left + 7) % 8;
		t[num].right = (t[num].right + 7) % 8;
	}


}

int main(void) {
	int data;
	
	for (int k = 1; k <= 4; k++) {
		int bin = 0;
		int sum = 0;
		scanf("%d", &data);
		for (int i = 0; i < 8; i++) {
			bin = (data / deciPow(i)) % 10;
			bin = bin * binPow(i);
			sum += bin;
		}
		t[k].data = sum;
		/*printf("%d", t[k].data);*/
	}


	scanf("%d", &K);

	while (K--) {
		INFO temp;
		scanf("%d %d", &temp.num, &temp.dir);
		exe(temp.num, temp.dir);

		v.push_back(temp);
	}
	// N�� 0
	// S�� 1

	printf("%d ", reslut);

	
	//printf("%d\n", 1 << 7);


}