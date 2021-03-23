#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
using namespace std;

#define SIZE 64

int N, Q;
int map[SIZE][SIZE]{};
int temp[SIZE][SIZE]{};
bool v[SIZE][SIZE]{};
bool c[SIZE][SIZE]{};
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

int dfs(int y, int x) {
	v[y][x] = true;
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N)	continue;
		if (!v[ny][nx] && map[ny][nx] > 0)
			ret += dfs(ny, nx);
	}
	return ret;
}

// 가장 큰 덩어리 찾기 - DFS
int getBiggest() {
	int ret = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (map[i][j] > 0 && !v[i][j])
				ret = max(ret, dfs(i, j));
	return ret;
}

// 얼음 합 반환
int getSum() {
	int ret = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			ret += map[i][j];
	return ret;
}

// 격자 시계방향 회전
void rotate(int y, int x, int L) {
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			temp[i][j] = map[y + L - 1 - j][x + i];
		}
	}
	//copy
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			map[y + i][x + j] = temp[i][j];
		}
	}
}

void rotateMap(int L) {
	L = (1 << L);
	// 모든 격자에 대한 회전
	for (int i = 0; i < N; i += L) {
		for (int j = 0; j < N; j += L) {
			rotate(i, j, L);
		}
	}
}

void melting() {
	memset(c, false, sizeof(c));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0) continue;
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny < 0 || nx < 0 || ny >= N || nx >= N)	continue;
				if (map[ny][nx] > 0) cnt++;
			}
			if (cnt < 3) c[i][j] = true;
		}

	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (c[i][j]) {
				map[i][j]--;
			}
		}
	}
}

int main() {
	//input data
	scanf("%d %d", &N, &Q);
	N = (1 << N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d",&map[i][j]);
		}
	}

	//logic
	while (Q--) {
		int L{};
		scanf("%d",&L);
		rotateMap(L);
		melting();
	}

	//result
	printf("%d\n", getSum());
	printf("%d\n", getBiggest());
	return 0;
}