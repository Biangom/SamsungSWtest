
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>

#define MAX_STEP 5

//***
// 1. dfs���� �� ���°��� �ʱ�ȭ�ϴ°�
// 2. max���� ���϶��ߴ��� ������ ���°��� �� ���ϴ°� ����./.
// 3. ���°��� �ٽ� �ǵ��ƾ� �ϴ°Ÿ� ...�ͳ�  (��û �߿�)
// ��������.. dfs�������� ���°��� ���󺹱��ؾ���

// 0 ��
// 1 ��
// 2 ��
// 3 ��

using namespace std;

int N;
int _map[20][20];
int init[20][20];

int pre[5][20][20];

int result;

typedef struct number {
	int num;
	bool merge = false;

}NUM;

vector<NUM> v;



void arrExe(int arr[], int len) {


	for (int i = 0; i < len; i++) {
		// arr�� ���ڰ� �� �ִٸ�
		if (arr[i] != 0) {
			NUM temp;
			temp.num = arr[i];
			v.push_back(temp);
			int v_size = v.size();
			// �̹� �ϳ� ��������
			// ���Ұ� 2�� �̻��� �� �պ��Ұ����� ���´�.
			if ( v_size >= 2) {
				int prev = v_size - 2;
				int now = v_size - 1;
				if (v[prev].num == v[now].num) {
					// ���� �պ��� �ȵȻ��¶��
					if (v[prev].merge == false) {
						v[prev].merge = true;
						v[prev].num *= 2;
						v.pop_back();
					}
				}
				
			}
		}
		else {

		}
	}
	int v_size = v.size();
	for (int i = 0; i < len; i++) {
		if (i < v_size)
			arr[i] = v[i].num;
		else
			arr[i] = 0;
	}
}



void exe(int map[20][20],  int dir) {

	// ��
	if(dir == 0) {
		// �� ���� ó��
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				// map�� ���ڰ� �� �ִٸ�
				if (map[i][k] != 0) {
					NUM temp;
					temp.num = map[i][k];
					v.push_back(temp);
					int v_size = v.size();
					// �̹� �ϳ� ��������
					// ���Ұ� 2�� �̻��� �� �պ��Ұ����� ���´�.
					if (v_size >= 2) {
						int prev = v_size - 2;
						int now = v_size - 1;
						if (v[prev].num == v[now].num) {
							// ���� �պ��� �ȵȻ��¶��
							if (v[prev].merge == false) {
								v[prev].merge = true;
								v[prev].num *= 2;
								v.pop_back();
							}
						}

					}
				}
				else {

				}
			}
			int v_size = v.size();
			for (int i = 0; i < N; i++) {
				if (i < v_size)
					map[i][k] = v[i].num;
				else
					map[i][k] = 0;
			}
			// �� �� �������� ���������.
			v.clear();
		}
	}
	// ����
	else if (dir == 1) {
		// �� �྿ ó��
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				// map�� ���ڰ� �� �ִٸ�
				if (map[k][N - i - 1] != 0) {
					NUM temp;
					temp.num = map[k][N - i - 1];
					v.push_back(temp);
					int v_size = v.size();
					// �̹� �ϳ� ��������
					// ���Ұ� 2�� �̻��� �� �պ��Ұ����� ���´�.
					if (v_size >= 2) {
						int prev = v_size - 2;
						int now = v_size - 1;
						if (v[prev].num == v[now].num) {
							// ���� �պ��� �ȵȻ��¶��
							if (v[prev].merge == false) {
								v[prev].merge = true;
								v[prev].num *= 2;
								v.pop_back();
							}
						}

					}
				}
				else {

				}
			}
			int v_size = v.size();
			for (int i = 0; i < N; i++) {
				if (i < v_size)
					map[k][N - i - 1] = v[i].num;
				else
					map[k][N - i - 1] = 0;
			}
			// �� �� �������� ���������.
			v.clear();
		}


	}
	// �Ʒ�
	else if (dir == 2) {
		// �� ���� ó��
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				// map�� ���ڰ� �� �ִٸ�
				if (map[N - 1 - i][k] != 0) {
					NUM temp;
					temp.num = map[N - 1 - i][k];
					v.push_back(temp);
					int v_size = v.size();
					// �̹� �ϳ� ��������
					// ���Ұ� 2�� �̻��� �� �պ��Ұ����� ���´�.
					if (v_size >= 2) {
						int prev = v_size - 2;
						int now = v_size - 1;
						if (v[prev].num == v[now].num) {
							// ���� �պ��� �ȵȻ��¶��
							if (v[prev].merge == false) {
								v[prev].merge = true;
								v[prev].num *= 2;
								v.pop_back();
							}
						}

					}
				}
				// 0 �̶��
				else {

				}
			}
			int v_size = v.size();
			for (int i = 0; i < N; i++) {
				if (i < v_size)
					map[N - 1 - i][k] = v[i].num;
				else
					map[N - 1 - i][k] = 0;
			}
			// �� �� �������� ���������.
			v.clear();
		}


	}
	// ��
	else {
		// �� �྿ ó��
		for(int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				// map�� ���ڰ� �� �ִٸ�
				if (map[k][i] != 0) {
					NUM temp;
					temp.num = map[k][i];
					v.push_back(temp);
					int v_size = v.size();
					// �̹� �ϳ� ��������
					// ���Ұ� 2�� �̻��� �� �պ��Ұ����� ���´�.
					if (v_size >= 2) {
						int prev = v_size - 2;
						int now = v_size - 1;
						if (v[prev].num == v[now].num) {
							// ���� �պ��� �ȵȻ��¶��
							if (v[prev].merge == false) {
								v[prev].merge = true;
								v[prev].num *= 2;
								v.pop_back();
							}
						}

					}
				}
				else {

				}
			}
			int v_size = v.size();
			for (int i = 0; i < N; i++) {
				if (i < v_size)
					map[k][i] = v[i].num;
				else
					map[k][i] = 0;
			}
			// �� �� �������� ���������.
			v.clear();
		}
	}
	
}

void dfs(int map[20][20], int dir, int now) {
	exe(map, dir);
	int temp[20][20];

	if (now == MAX_STEP) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] > result)
					result = map[i][j];
			}
		}
		return;
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			 temp[i][j] = map[i][j];
		}
	}
	dfs(map, 0, now + 1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = temp[i][j];
		}
	}
	dfs(map, 1, now + 1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = temp[i][j];
		}
	}
	dfs(map, 2, now + 1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = temp[i][j];
		}
	}
	dfs(map, 3, now + 1);


}

void initial() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			_map[i][j] = init[i][j];
		}
	}

}

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &init[i][j]);
		}
	}

	// 0 ��
	// 1 ��
	// 2 ��
	// 3 ��

	for (int i = 0; i < 4; i++) {
		initial();
		dfs(_map, i,1);
	}

	// ***

	printf("%d\n", result);
	// ***
}