#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct point {
	int y;
	int x;
};

queue <point> Q{};

int n{};
int l{}, r{};
int map[64][64]{};
int res{};

// 차이가 범위에 해당되는지? 해당되면 1 아니면 0
int isBeApplicable(point p) {
	int dx[] = { 0,0,1,-1 };
	int dy[] = { 1,-1,0,0 };

	for (int i = 0; i < 4; i++) {
		int y = p.y + dy[i];
		int x = p.x + dx[i];
		if (y < 0 || x < 0 || y >= n || x >= n)	continue;
		int data = abs(map[y][x] - map[p.y][p.x]);
		if (l <= data && data <= r)	return 1;
	}
	return 0;
}

void solve() {
	int sum = 0;
	//차이가 나는 것 모두 큐에 저장
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (isBeApplicable({ i,j})) {
				Q.push({ i,j });
				sum += map[i][j];
			}
		}
	}
	if (sum == 0)	return;
	int qSize = Q.size();
	res++;
	while (!Q.empty()) {
		point cur = Q.front();
		Q.pop();
		map[cur.y][cur.x] = sum / qSize;
	}
	solve();
}

int main() {
	// Input Data
	scanf("%d", &n);
	scanf("%d %d", &l, &r);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	// Init
	// Logic
	solve();
	// Result
	printf("%d\n", res);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}