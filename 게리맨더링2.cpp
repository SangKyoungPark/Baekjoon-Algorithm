#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define INF 987987987
#define SIZE 25

int n{};
int map[SIZE][SIZE]{};
int nRes{};

int solve(int x, int y, int d1, int d2) {
	vector<int> population[5]{};

	//init
	for (int i = 0; i < 5; i++) {
		population[i].push_back(0);
	}

	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			//1번 선거구
			if (r < x + d1 && c <= y && !(r >= x && c >= y - (r - x))) {
				population[0].at(0) += map[r][c];
			}
			//2번 선거구
			else if (r <= x + d2 && c > y && !(r >= x && c <= y + (r - x))) {
				population[1].at(0) += map[r][c];
			}
			//3번 선거구
			else if (r >= x + d1 && c < y - d1 + d2 && !(r <= x + d1 + d2 && c >= (y - d1 + d2 - (x + d1 + d2 - r)))) {
				population[2].at(0) += map[r][c];
			}
			//4번 선거구
			else if (r > x + d2 && c >= y - d1 + d2 && !(r <= x + d1 + d2 && c <= (y - d1 + d2 + (x + d1 + d2 - r)))) {
				population[3].at(0) += map[r][c];
			}
			//5번 선거구
			else {
				population[4].at(0) += map[r][c];
			}
		}
	}

	int myMax = -987987987;
	int myMin = 987987987;
	for (int i = 0; i < 5; i++) {
		myMin = min(population[i].at(0), myMin);
		myMax = max(population[i].at(0), myMax);
	}

	return myMax - myMin;
}

void getMin() {
	int res = INF;
	for (int x = 1; x <= n - 2; x++) {
		for (int y = 2; y <= n - 1; y++) {
			for (int d1 = 1; d1 <= y - 1 && d1 <= n - x - 1; d1++) {
				for (int d2 = 1; d2 <= n - y && d2 <= n - x - 1; d2++) {
					res = min(res, solve(x, y, d1, d2));
				}
			}
		}
	}
	nRes = res;
}

int main() {
	//input data
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	//logic
	getMin();

	//result
	printf("%d", nRes);
	return 0;
}
