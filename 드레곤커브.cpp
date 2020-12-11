#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
using namespace std;

#define MAX 101 // 0<= x,y <= 100 -> 101

int n{};
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };
int nRes{};
bool v[110][110]{}; // Map display by dir

int main() {
	int y{}, x{}, d{}, g{};

	// Input Data
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &x, &y, &d, &g);

		// Init
		vector <int> curve{};
		curve.push_back(d);

		// Logic
		for (int j = 0; j < g; j++) {
			vector <int> temp = curve;
			for (int k = temp.size()-1; k >= 0; k--) {
				curve.push_back((temp[k] + 1) % 4);
			}
		}
		v[y][x] = true;
		for (int j = 0; j < curve.size(); j++) {
			y += dy[curve[j]];
			x += dx[curve[j]];
			if (x < 0 || y < 0 || x >= MAX || y >= MAX)	continue;
			v[y][x] = true;
		}
	}
	nRes = 0;
	for (int j = 0; j < MAX-1; j++) {
		for (int k = 0; k < MAX-1; k++) {
			if (v[j][k] && v[j][k + 1] && v[j + 1][k] && v[j + 1][k + 1]) {
				nRes++;
			}
		}
	}

	// Result
	printf("%d\n", nRes);
	return 0;
}