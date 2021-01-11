/*
# Q
- 원판을 T 번 회전시킨 후 원판에 적힌 수의 합은 ?
# Algo
- 1. i번째 회전할 때, Xi의 배수인 원판을 di 방향으로 ki칸 회전 (di // 0 : 시계 / 1 : 반시계)
- 2. 인접하면서 수가 같은 것을 모두 찾아서 지움
- 3. 없는 경우에는 원판에 적힌 수의 평균을 구함, 평균보다 큰 수에서 1을 빼고, 작은 수에는 1을 더함
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
using namespace std;

#define SIZE 50

int n{}, m{}, t{};
int pan[SIZE][SIZE]{};
int nRes{};

void rotate(int x, int d, int k) {
	// 시계
	if (d == 0) {
		for (int i = 0; i < k; i++) {
			int data = pan[x][m-1];
			for (int j = m - 1; j >= 0; j--) {
				pan[x][j] = pan[x][j-1];
			}
			pan[x][0] = data;
		}
	}
	// 반시계
	else {
		for (int i = 0; i < k; i++) {
			int data = pan[x][0];
			for (int j = 0; j < m - 1;j++) {
				pan[x][j] = pan[x][j+1];
			}
			pan[x][m - 1] = data;
		}
	}
}
void  adjacent(int x) {
	int temp[SIZE][SIZE]{};
	//copy
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			temp[i][j] = pan[i][j];
		}
	}
	bool flag = false;

	// 인접한 것을 찾기
	for (int j = 0; j < n; j++) {
		for (int i = 0;i < m; i++) {
			if (i - 1 >= 0) {
				if (pan[j][i] == pan[x][i - 1]) {
					temp[j][i - 1] = -1;
					flag = true;
				}
			}
			if (i + 1 < n) {
				if (pan[j][i] == pan[x][i + 1]) {
					temp[j][i + 1] = -1;
					flag = true;
				}
			}
			if (j + 1 < n) {
				if (pan[j][i] == pan[x + 1][i] && x + 1 < n) {
					temp[j + 1][i] = -1;
					flag = true;
				}
			}
			if (j - 1 >= 0) {
				if (pan[j][i] == pan[j - 1][i]) {
					temp[j - 1][i] = -1;
					flag = true;
				}
			}
		}
	}
	// 인접한 것이 없을 경우
	if (!flag) {
		int sum = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (pan[i][j] != -1) {
					sum += pan[i][j];
					cnt++;
				}
			}
		}
		int evg = sum / cnt;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (pan[i][j] != -1) {
					if (pan[i][j] > evg)	pan[i][j]++;
					else	pan[i][j]--;
				}
			}
		}
	}
	// update
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			pan[i][j] = temp[i][j];
		}
	}
}

void solve(int x, int d, int k) {
	
	// 회전
	int i = 1;
	while (n > i * x) {
		rotate(x * i, d, k);
		i++;
	}
	adjacent(x * i);
	
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (pan[i][j] != -1) {
				sum += pan[i][j];
			}
		}
	}
	if (sum < 0)	nRes = -1;
	else	nRes = sum;
}

int main() {
	int x{}, d{}, k{};
	
	//input
	scanf("%d %d %d", &n, &m, &t);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &pan[i][j]);
		}
	}
	for (int i = 0; i < t; i++) {
		scanf("%d %d %d", &x, &d, &k);
		//logic
		solve(x-1, d, k);
	}
	//result
	printf("%d\n", nRes);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", pan[i][j]);
		}
		printf("\n");
	}
	return 0;
}