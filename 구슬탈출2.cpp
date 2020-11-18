/*
# Q
-최소 몇번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는가

# Algo
- 4방향으로 모두 굴려서 모든 경우 판단
- 4방향으로 돌리는 것 재귀 사용
- . 일때, 이동가능 아니면 멈춤 (이때 O에 부딪혔는지 판단)
- 파란색이 먼저 부딪히면 return 빨간색이 먼저 부딪히면 min 값 구하기

*/
#include <iostream>
#include <algorithm>
using namespace std;

struct point {
	int y;
	int x;
};
int INF = 987987987;
char map[20][20];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int n, m;
int myMin = INF;
point R, B, O;

int solve(point r, point b, int cnt, int dir) {
	//escape condition
	if (cnt > 10)	return INF;

	//init
	// 새로운 좌표이동을 위해 직접움직이지 않고 변수활용
	int ry = r.y;
	int rx = r.x;
	int by = b.y;
	int bx = b.x;

	int res = INF;
	if (dir != -1) {
		while (map[ry + dy[dir]][rx + dx[dir]] == '.') {
			ry += dy[dir];
			rx += dx[dir];
			if (ry == O.y && rx == O.x) {
				res = cnt;
				break;
			}
		}
		while (map[by + dy[dir]][bx + dx[dir]] == '.') {
			by += dy[dir];
			bx += dx[dir];
			if (by == O.y && bx == O.x) {
				res = INF;
				return res;
			}
		}

		// 구슬이 어디로든지 이동되지 않을 경우
		if (ry == r.y && rx == r.x && by == b.y && bx == b.x) {
			res = INF;
			return res;
		}

		// 두구슬이 겹칠 경우
		if (ry == by && rx == bx) {
			if (dir == 0) {
				if (r.y < b.y) by++;
				else ry++;
			}
			else if (dir == 1) {
				if (r.y > b.y) by--;
				else ry--;
			}
			else if (dir == 2) {
				if (r.x < b.x) bx++;
				else rx++;
			}
			else if (dir == 3) {
				if (r.x > b.x) bx--;
				else rx--;
			}
		}
	}

	//recursion
	for (int i = 0; i < 4; i++) {
		res = min(res, solve({ ry, rx }, { by, bx }, cnt + 1, i));
	}
	return res;
}

int main() {
	//input
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'R') {
				map[i][j] = '.';
				R.y = i;
				R.x = j;
			}
			else if (map[i][j] == 'B') {
				map[i][j] = '.';
				B.y = i;
				B.x = j;
			}
			else if (map[i][j] == 'O') {
				map[i][j] = '.';
				O.y = i;
				O.x = j;
			}
		}
	}

	//logic
	int res = solve(R, B, 0, -1);
	if (res == INF) {
		res = -1;
	}

	//result
	printf("%d\n", res);

	return 0;
}