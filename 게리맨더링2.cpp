#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

#define SIZE 25

int n{};
int map[SIZE][SIZE]{};
int v[SIZE][SIZE]{};
int nMin{};

void checkBoundary(int y,int x, int d1, int d2) {
	// boundary check
	// 1
	for (int i = 0; i <= d1; i++) {
		if (y + i < 0 || y + i >= n || x - i < 0 || x - i >= n) break;
		v[y + i][x - i] = 5;
	}
	// 2
	for (int i = 0; i <= d2; i++) {
		if (y + i < 0 || y + i >= n || x + i < 0 || x + i >= n) break;
		v[y + i][x + i] = 5;
	}
	// 3
	for (int i = 0; i <= d2; i++) {
		if (y + d1 + i < 0 || y + d1 + i >= n || x - d1 + i < 0 || x - d1 + i >= n) break;
		v[y + d1 + i][x - d1 + i] = 5;
	}
	// 4
	for (int i = 0; i <= d1; i++) {
		if (y + d2 + i < 0 || y + d2 + i >= n || x + d2 - i < 0 || x + d2 - i >= n) break;
		v[y + d2 + i][x + d2 - i] = 5;
	}
	// fill to number 5

	// print
	printf("after \n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", v[i][j]);
		}
		printf("\n");
	}
}

int main() {
	// Input Data
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	// Init
	nMin = 987987987;

	// Logic
//	if (d1 >= 1 && d2 >= 1 && 1 <= x
//		&& y < y + d1 + d2 && y + d1 + d2 <= n
//		&& 1 <= x - d1 && x - d1 < x && x < x + d2 && x + d2 <= n)

	checkBoundary(1,3,2,2);

	// Result
	printf("%d\n", nMin);

	return 0;
}