#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct INFO {
	int num{};
	int y{};
	int x{};
	int dir{};
};

int n{}, k{};
int stage[16][16]{};
int nRes{};

vector <INFO> horse{};
stack <int> map[15][15]{};

int dy[] = { 0,0,0,-1,1 };
int dx[] = { 0,1,-1,0,0 };


int moving() {
	for (int i = 1; i <= k; i++) {
		int y = horse[i].y + dy[horse[i].dir];
		int x = horse[i].x + dx[horse[i].dir];

		//map out
		if (y<1 || x<1 || y>n || x>n) {
			if (horse[i].dir == 1)	horse[i].dir = 2;
			else if (horse[i].dir == 2)	horse[i].dir = 1;
			else if (horse[i].dir == 3)	horse[i].dir = 4;
			else if (horse[i].dir == 4)	horse[i].dir = 3;
			map[y + dy[horse[i].dir]][x + dx[horse[i].dir]];
		}
		//white
		if (stage[y][x] == 0) {
			map[horse[i].y][horse[i].x].pop();
			horse[i].y = y;
			horse[i].x = x;
			map[y][x].push(horse[i].num);
		}
		//red
		else if (stage[y][x] == 1) {
			while (!map[horse[i].y][horse[i].x].empty()) {
				map[y][x].push(map[horse[i].y][horse[i].x].top());
				map[horse[i].y][horse[i].x].pop();
			}
		}
		//blue
		else if (stage[y][x] == 2) {
			if (horse[i].dir == 1)	horse[i].dir = 2;
			else if(horse[i].dir == 2)	horse[i].dir = 1;
			else if (horse[i].dir == 3)	horse[i].dir = 4;
			else if (horse[i].dir == 4)	horse[i].dir = 3;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j].size() >= 4)	return 1;
		}
	}
	return 0;
}


int main() {
	int data{};
	int x{}, y{}, d{};
	int cnt{};

	// Input Data
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= n;j++) {
			scanf("%d", &stage[i][j]);
		}
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d %d %d", &y, &x, &d);
		horse.push_back({i,y,x,d});
		map[y][x].push(i);
	}
	// Init
	cnt = 0;
	nRes = 0;

	// Logic
	while (true) {
		if (cnt > 1000) {
			nRes = -1;
			break;
		}
		nRes++;
		if (moving())	break;
	}
	
	// Result
	printf("%d\n", nRes);
	return 0;
}