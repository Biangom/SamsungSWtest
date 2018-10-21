#include<stdio.h>
#include<iostream>
#include<algorithm>

// printf lli
// scanf lld

long long N;
long long A[1000000];
long long B, C;

// 처음에 주감독인거 다 뺀 상태에서
// sum ++
// 남은 수로 부감독 / 해서 목 구하기
// 나머지가 0이 아니면 한번더 sum += 1

long long sum;

void calc(long long input) {
	input -= B;
	sum++;
	if (input <= 0) return;
	else {
		sum += input / C;
		if (input % C != 0) sum += 1;
	}

}

int main(void) {
	scanf("%lld", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &A[i]);
	}
	scanf("%lld %lld", &B, &C);

	for (int i = 0; i < N; i++) {
		calc(A[i]);
	}
	printf("%lli", sum);

	//printf("%d", N);
	//for (int i = 0; i < N; i++) {
	//	printf(" %d", A[i]);
	//}
	//printf("\n");
	//printf("%d %d", B, C);




}