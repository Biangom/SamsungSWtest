#include<iostream>
#include<algorithm>
#include<vector>

// *** int best_dist = 9999999; // �̰Ŷ����� ���� 20�� ��Ƹ���
// min , max ���� �� �ʱ� ���� ���� Ȥ�� ���Լ����ϴ°� �ݺ��� �ȿ� ���� �ϴ� ��
// �Ű澲��

using namespace std;

int N, M;

//N�� N��
int map[50][50];

vector<pair<int, int>> v;
vector < pair<int, int>> houseV;
int house_size;

int result= 999999;


int exe() {
	int dist;
	int best_dist;
	int sum_dist = 0;
	for (int i = 0; i < house_size; i++) {
		//printf("h: [%d %d] \n", houseV[i].first, houseV[i].second);
		int best_dist = 9999999; // �̰Ŷ����� ���� 20�� ��Ƹ���

		for (int j = 0; j < M; j++) {
			//printf("v: [%d %d] \n", v[j].first, v[j].second);
			dist = abs(houseV[i].first - v[j].first);
			dist += abs(houseV[i].second - v[j].second);
			best_dist = min(best_dist, dist);
			//printf("[%d %d]\n", dist, best_dist);
		}
		sum_dist += best_dist;
		
	}
	//printf("%d \n", sum_dist);
	return sum_dist;
}

void dfs(int row, int now_step) {

	if (now_step == M) {
		result = min( result, exe() );

		return;
	}

	for (int i = row; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 2) {
				map[i][j] = -1;
				v.push_back({ i, j }); // 2 ����

				dfs(i, now_step + 1);

				map[i][j] = 2;
				v.pop_back();
			}
		}
	}

}

int main(void) {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1)
				houseV.push_back({ i, j });
		}
	}

	house_size = houseV.size();

	// max step
	dfs(0, 0);

	printf("%d", result);

}