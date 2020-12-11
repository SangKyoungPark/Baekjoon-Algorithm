#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct CCTV{
	int y;
	int x;
	int num;
};
vector <CCTV> cctv;

int n, m;
int map[10][10];
int nRes;
// »óÁÂÇÏ¿ì
int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };

int getBlindSpot() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0)	cnt++;
		}
	}
	return cnt;
}

void updateMap(int y, int x, int dir){
	dir %= 4;
	if (dir == 0) {	// »ó
		for (int i = y; i + dy[dir] >= 0; i += dy[dir]) {
			if (map[i + dy[dir]][x] == 6)	break;
			map[i + dy[dir]][x] = 8;
		}
	}
	else if (dir == 1) { // ÁÂ
		for (int i = x; i + dx[dir] >= 0; i += dx[dir]) {
			if (map[y][i + dx[dir]] == 6)	break;
			map[y][i + dx[dir]] = 8;
		}
	}
	else if (dir == 2) { // ÇÏ
		for (int i = y;i + dy[dir] < n; i += dy[dir]) {
			if (map[i + dy[dir]][x] == 6)	break;
			map[i + dy[dir]][x] = 8;
		}
	}
	else if (dir == 3) { // ¿ì
		for (int i = x; i + dx[dir] < m; i += dx[dir]) {
			if (map[y][i + dx[dir]] == 6)	break;
			map[y][i + dx[dir]] = 8;
		}
	}
}

void solve(int idx) {
	//escape
	if (idx == cctv.size()) {
		nRes = min(nRes, getBlindSpot());
		return;
	}
	//copy map
	int check[10][10]{};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			check[i][j] = map[i][j];
		}
	}
	//update map of cctv
	int y = cctv[idx].y;
	int x = cctv[idx].x;
	int num = cctv[idx].num;

	// logic of direction
	if (num == 1) { // 4
		for (int k = 0; k < 4; k++) {
			updateMap(y, x , k);
			solve(idx + 1);
			for (int i = 0; i < n;i++) {
				for (int j = 0; j < m; j++) {
					map[i][j] = check[i][j];
				}
			}
		}
	}
	else if (num == 2) { // 2
		for (int k = 0; k < 2; k++) { 
			updateMap(y, x , k);
			updateMap(y, x , k+2);
			solve(idx + 1);

			for (int i = 0; i < n;i++) {
				for (int j = 0; j < m; j++) {
					map[i][j] = check[i][j];
				}
			}
		}
	}
	else if (num == 3) { // 4   
		for (int k = 0; k < 4; k++) {
			updateMap(y, x, k);
			updateMap(y, x, k+1);
			solve(idx + 1);

			for (int i = 0; i < n;i++) {
				for (int j = 0; j < m; j++) {
					map[i][j] = check[i][j];
				}
			}
		}
	}
	else if (num == 4) { // 4
		for (int k = 0; k < 4; k++) {
			updateMap(y, x, k);
			updateMap(y, x, k+1);
			updateMap(y, x, k+3);
			solve(idx + 1);

			for (int i = 0; i < n;i++) {
				for (int j = 0; j < m; j++) {
					map[i][j] = check[i][j];
				}
			}
		}
	}
	else if (num == 5) { // 1
		for (int k = 0; k < 4; k++) {
			updateMap(y, x, k);
		}
		solve(idx + 1);
	}
}

int main() {
	//input
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d",&map[i][j]);
			if (map[i][j] > 0 && map[i][j] < 6) {
				cctv.push_back({i, j, map[i][j]});
			}
		}
	}

	//init
	nRes = 987987987;
	
	//logic
	solve(0);	// solvesion all case of cctv
	
	//result
	printf("%d\n", nRes);
}