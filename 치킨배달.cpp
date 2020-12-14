#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 987987987

struct point {
	int y;
	int x;
};

int n{}, m{};
int map[64][64]{};
int nRes{};

vector <point> home;
vector <point> store;
vector <point> select;

int hSize{};
int sSize{};

int getDistance(point h, point s) {
	return abs(h.y - s.y) + abs(h.x - s.x);
}

void solve(int idx) {
	if (idx > 13)	return;
	if (idx == m) {
		int sum = 0;
		for (int i = 0; i < hSize; i++) {
			int data = MAX;
			for (int j = 0; j < m; j++) {
				data = min(data, getDistance(home[i], select[j]));
			}
			sum += data;
		}
		nRes = min(nRes, sum);
		return;
	}
	for (int i = idx; i < sSize; i++) {
		select.push_back(store[idx]);
		solve(idx + 1);
		select.pop_back();
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
	hSize = home.size();
	sSize = store.size();

	// Logic
	solve(0);

	// Result
	printf("%d\n", nRes);
	return 0;
}