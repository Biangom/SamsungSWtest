// made by dragostea
// boj.kr/14501 퇴사

#include<iostream>

#include<cmath>

using namespace std;

// n은 일수 
int n, capacity;
int day[100], need[100];
int cache[1001][100];
string name[100];

//캐리어에 남은 용량이 capacity일 때, item 이후의 물건들을
//담아 얻을 수 있는 최대 가치의 합을 반환한다.
int pack(int capacity, int item)
{
	//기저사례 : 더 담을 물건이 없을 때
	if (item == n) return 0;
	int& ret = cache[capacity][item];
	if (ret != -1) return ret;

	//이 물건을 담지 않을 경우
	ret = pack(capacity, item + 1);
	//이 물건을 담을 경우
	if (capacity >= day[item])
		ret = fmax(ret, pack(capacity - day[item], item + 1) + need[item]);
	return ret;
}

int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &day[i], &need[i]);
	}
	
	printf("%d", pack(0, 0));


}

/*

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, dp[16], t[16], p[16];

//dp[n] n일 일때 최대 가치
// t[i] i번쨰 상담 걸리는 일
// p[i] i번쨰 상담의 가치


//캐리어에 남은 용량이 capacity일 때, item 이후의 물건들을
//담아 얻을 수 있는 최대 가치의 합을 반환한다.
int func(int pos) {
	if (pos == n + 1)return 0;
	if (pos > n + 1)return -987654321;
	int &ret = dp[pos];

	if (ret != -1)return ret;
	// if(ret == -1)
	return ret = max(func(pos + 1), func(pos + t[pos]) + p[pos]);
}
int main() {
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &t[i], &p[i]);
	printf("%d\n", func(1));
	return 0;
}
*/