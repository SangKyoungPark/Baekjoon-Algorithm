/*
# Q
-안전 영역의 최대 크기를 구하여라.

# Algo
- 0 칸에서 모두 벽을 세워보는 과정
- bfs로 최대값 판단

# O
- 모든칸을 다 순회 8*8 = 64
- bfs모두 다 순환 8*8 = 64
- 64 * 64 = O(4096)

*/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct point {
	int y;
	int x;
};

int n, m;
int map[10][10]{};
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int myMax{};

// 바이러스 퍼트리는 함수
int bfs() {
	queue <point> Q;
	int check[10][10]{};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 2) {
				check[i][j] = 1;
				Q.push({ i,j });
			}
			else if (map[i][j] == 1) {
				check[i][j] = 1;
			}
		}
	}
	// 바이러스 퍼트리기
	while (Q.size()) {
		point cur = Q.front();
		Q.pop();

		for (int k = 0; k < 4; k++) {
			point pp = { cur.y + dy[k], cur.x + dx[k] };
			if (pp.y < 0 || pp.x < 0 || pp.y >= n || pp.x >= m) continue;
			if (check[pp.y][pp.x] == 0) {
				check[pp.y][pp.x] = 1;
				Q.push(pp);
			}
		}
	}

	// 안전영역 구하기
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0 && check[i][j] == 0)	cnt++;
		}
	}
	//printf("%d\n",cnt);
	return cnt;
}

void recursion(int x) {
	//escape condition
	if (x > 3)	return;
	// bfs condition
	if (x == 3) {
		myMax = max(myMax, bfs());
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				recursion(x + 1);
				map[i][j] = 0;
			}
		}
	}

}

int main() {
	//input
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	//logic
	// recursion -> 3개의 벽을 세우고 -> bfs 진행
	recursion(0);

	//result
	printf("%d\n", myMax);
	return 0;
}