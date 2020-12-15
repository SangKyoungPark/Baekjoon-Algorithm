#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 987987987;

struct point {
	int y{};
	int x{};
};

int n{}, m{};
int map[64][64]{};
int nRes{};

vector <point> home{};
vector <point> store{};

int s[16]{};
int hSize{};
int sSize{};

int getDistance(point h, point s) {
	return abs(h.y - s.y) + abs(h.x - s.x);
}

void solve(int idx) {
	if (idx > sSize)	return;
	if (idx == m) {
		int sum = 0;
		for (int i = 0; i < hSize; i++) {
			int data = MAX;
			for (int j = 0; j < m; j++) {
				data = min(data, getDistance({ home[i].y,home[i].x }, { store[s[j]].y, store[s[j]].x }));
			}
			sum += data;
		}
		nRes = min(nRes, sum);
		return;
	}
	for (int i = idx; i < sSize; i++) {
		s[idx] = i;
		solve(idx + 1);
	}
}

int main() {
	// Input Data
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) home.push_back({ i,j });
			else if (map[i][j] == 2) store.push_back({ i,j });
		}
	}
	// Init
	nRes = MAX;

	// Logic
	solve(0);

	// Result
	printf("%d\n", nRes);
	return 0;
}
