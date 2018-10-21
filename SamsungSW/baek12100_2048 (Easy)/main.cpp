
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>

#define MAX_STEP 5

//***
// 1. dfs돌릴 때 상태공간 초기화하는거
// 2. max값을 구하라했더니 마지막 상태공간 값 구하는거 보소./.
// 3. 상태공간 다시 되돌아야 하는거를 ...와나  (엄청 중요)
// 주의할점.. dfs돌리기전 상태공간 원상복구해야함

// 0 위
// 1 오
// 2 아
// 3 왼

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
		// arr에 숫자가 들어가 있다면
		if (arr[i] != 0) {
			NUM temp;
			temp.num = arr[i];
			v.push_back(temp);
			int v_size = v.size();
			// 이미 하나 넣은다음
			// 원소가 2개 이상일 때 합병할건지를 묻는다.
			if ( v_size >= 2) {
				int prev = v_size - 2;
				int now = v_size - 1;
				if (v[prev].num == v[now].num) {
					// 아직 합병이 안된상태라면
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

	// 위
	if(dir == 0) {
		// 한 열씩 처리
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				// map에 숫자가 들어가 있다면
				if (map[i][k] != 0) {
					NUM temp;
					temp.num = map[i][k];
					v.push_back(temp);
					int v_size = v.size();
					// 이미 하나 넣은다음
					// 원소가 2개 이상일 때 합병할건지를 묻는다.
					if (v_size >= 2) {
						int prev = v_size - 2;
						int now = v_size - 1;
						if (v[prev].num == v[now].num) {
							// 아직 합병이 안된상태라면
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
			// 한 행 돌때마다 비워버린다.
			v.clear();
		}
	}
	// 오른
	else if (dir == 1) {
		// 한 행씩 처리
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				// map에 숫자가 들어가 있다면
				if (map[k][N - i - 1] != 0) {
					NUM temp;
					temp.num = map[k][N - i - 1];
					v.push_back(temp);
					int v_size = v.size();
					// 이미 하나 넣은다음
					// 원소가 2개 이상일 때 합병할건지를 묻는다.
					if (v_size >= 2) {
						int prev = v_size - 2;
						int now = v_size - 1;
						if (v[prev].num == v[now].num) {
							// 아직 합병이 안된상태라면
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
			// 한 행 돌때마다 비워버린다.
			v.clear();
		}


	}
	// 아래
	else if (dir == 2) {
		// 한 열씩 처리
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				// map에 숫자가 들어가 있다면
				if (map[N - 1 - i][k] != 0) {
					NUM temp;
					temp.num = map[N - 1 - i][k];
					v.push_back(temp);
					int v_size = v.size();
					// 이미 하나 넣은다음
					// 원소가 2개 이상일 때 합병할건지를 묻는다.
					if (v_size >= 2) {
						int prev = v_size - 2;
						int now = v_size - 1;
						if (v[prev].num == v[now].num) {
							// 아직 합병이 안된상태라면
							if (v[prev].merge == false) {
								v[prev].merge = true;
								v[prev].num *= 2;
								v.pop_back();
							}
						}

					}
				}
				// 0 이라면
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
			// 한 행 돌때마다 비워버린다.
			v.clear();
		}


	}
	// 왼
	else {
		// 한 행씩 처리
		for(int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				// map에 숫자가 들어가 있다면
				if (map[k][i] != 0) {
					NUM temp;
					temp.num = map[k][i];
					v.push_back(temp);
					int v_size = v.size();
					// 이미 하나 넣은다음
					// 원소가 2개 이상일 때 합병할건지를 묻는다.
					if (v_size >= 2) {
						int prev = v_size - 2;
						int now = v_size - 1;
						if (v[prev].num == v[now].num) {
							// 아직 합병이 안된상태라면
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
			// 한 행 돌때마다 비워버린다.
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

	// 0 위
	// 1 오
	// 2 아
	// 3 왼

	for (int i = 0; i < 4; i++) {
		initial();
		dfs(_map, i,1);
	}

	// ***

	printf("%d\n", result);
	// ***
}