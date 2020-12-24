#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N{}, M{}, K{};
int MAT[11][11]{}, A[11][11]{}, D[11][11]{};

vector <int> vec[101]{};

int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int dx[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

void spring_summer(int loc, int r, int c) {
	for (int i = 0; i < vec[loc].size(); i++) {
		int age = vec[loc][i];
		if (MAT[r][c] >= age) {
			vec[loc][i] = age + 1;
			MAT[r][c] -= age;
		}
		else {
			vec[loc].erase(vec[loc].begin() + i);
			D[r][c] += age / 2;
			i--;
		}
	}
}

void fall(int loc, int r, int c) {
	int num_tree = vec[loc].size();
	for (int i = 0; i < num_tree; i++) {
		int age = vec[loc][i];
		if (age % 5 != 0) continue;

		for (int n = 0; n < 8; n++) {
			int nR = r + dy[n]; int nC = c + dx[n];
			if (nR < 1 || nR > N || nC < 1 || nC > N) continue;
			int next = (nR - 1) * N + nC;
			vec[next].push_back(1);
		}
	}
}

void winter() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			MAT[i][j] += D[i][j] + A[i][j];
			D[i][j] = 0;
		}
	}
}

int main() {
	//input data
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &A[i][j]);
			MAT[i][j] = 5;
			vec[(i - 1) * N + j].clear();
		}
	}
	for (int i = 1; i <= M; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		vec[(x - 1) * N + y].push_back(z);
	}

	//logic
	for (int k = 1; k <= K; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				int loc = (i - 1) * N + j;
				if (vec[loc].size() == 0) continue;
				sort(vec[loc].begin(), vec[loc].end());
				spring_summer(loc, i, j);
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				int loc = (i - 1) * N + j;
				if (vec[loc].size() == 0) continue;
				fall(loc, i, j);
			}
		}
		winter();
	}
	// result
	int cnt = 0;
	for (int i = 1; i <= N * N; i++) {
		if (vec[i].size() == 0) continue;
		cnt += vec[i].size();
	}
	printf("%d", cnt);
}