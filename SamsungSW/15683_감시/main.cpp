#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int r, c;
int result = 999999;
int d[8][8];
int test[8][8];

int v_size;


struct cctv {
	int r;
	int c;
	int dir;
	int type;
};


// 동
void go1(int i, int j) {
	for (int k = j; k < c; k++) {
		if (test[i][k] == 6) break;
		if (test[i][k] == 0) test[i][k] = 1;
	}
}

// 남
void go2(int i, int j) {
	for (int k = i; k < r; k++) {
		if (test[k][j] == 6) break;
		if (test[k][j] == 0) test[k][j] = 1;
	}
}

// 서
void go3(int i, int j) {
	for (int k = j; k >= 0; k--) {
		if (test[i][k] == 6) break;
		if (test[i][k] == 0) test[i][k] = 1;
	}
}


// 북
void go4(int i, int j) {
	for (int k = i; k >= 0; k--) {
		if (test[k][j] == 6) break;
		if (test[k][j] == 0) test[k][j] = 1;
	}
}


// 다 세는 함수
void count(vector<cctv> &v) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			test[i][j] = d[i][j];
		}
	}

	for (int k = 0; k < v_size; k++) {
		int _i = v[k].r;
		int _j = v[k].c;
		if (v[k].type == 1) {
			if (v[k].dir == 0) go1(_i, _j);
			else if (v[k].dir == 1) go2(_i, _j);
			else if (v[k].dir == 2) go3(_i, _j);
			else if (v[k].dir == 3) go4(_i, _j);
			//1일때 촥
		}
		else if (v[k].type == 2) {
			if (v[k].dir == 0 || v[k].dir == 2) go1(_i, _j), go3(_i, _j);
			else if (v[k].dir == 1 || v[k].dir == 3) go2(_i, _j), go4(_i, _j);

		}
		else if (v[k].type == 3) {
			if (v[k].dir == 0) go4(_i, _j), go1(_i, _j);
			else if (v[k].dir == 1) go1(_i, _j), go2(_i, _j);
			else if (v[k].dir == 2) go2(_i, _j), go3(_i, _j);
			else if (v[k].dir == 3) go3(_i, _j), go4(_i, _j);
		}

		else if (v[k].type == 4) {
			if (v[k].dir == 0) go3(_i, _j), go4(_i, _j), go1(_i, _j);
			else if (v[k].dir == 1) go4(_i, _j), go1(_i, _j), go2(_i, _j);
			else if (v[k].dir == 2) go1(_i, _j), go2(_i, _j), go3(_i, _j);
			else if (v[k].dir == 3) go2(_i, _j), go3(_i, _j), go4(_i, _j);
		}

		else if (v[k].type == 5) {
			go1(_i, _j);
			go2(_i, _j);
			go3(_i, _j);
			go4(_i, _j);
		}
	}

	int cnt = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (test[i][j] == 0) {
				cnt++;
			}
		}
	}

	result = min(result, cnt);
}


// 배열 채우는 함수 작성


// 재귀함수 작성
void recur(int index, vector<cctv> &v) {

	if (index == v_size) {
		count(v);
		return;
	}

	

	v[index].dir = 0;
	recur(index + 1, v);

	v[index].dir = 1;
	recur(index + 1, v);

	v[index].dir = 2;
	recur(index + 1, v);

	v[index].dir = 3;
	recur(index + 1, v);

}

int main(void) {

	scanf("%d %d", &r, &c);

	vector<cctv> v;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%d", &d[i][j]);
			int temp = d[i][j];
			if (temp != 0 && temp != 6)
				v.push_back({ i, j, 0, temp });
		}
	}
	
	v_size = (int)v.size();
	recur(0, v);

	printf("%d", result);

}

