/*
# Q
- 로봇청소기가 청소하는 구역의 수

#Algo
- a,b,c,d 기준에 맞춰서 dfs진행
*/
#include <iostream>
using namespace std;

int n, m;
int r, c, d;
int map[60][60]{};
int cnt;
// 북동남서(전진)
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

void dfs(int x, int y, int dir) {
	//벽
	if (map[x][y] == 1)	return;

	//빈칸
	if (map[x][y] == 0) {
		map[x][y] = 2;
		cnt++;
	}

	// 4 방향 검사
	for (int k = 0; k < 4; k++) {
		int nextDir = dir - 1 < 0 ? 3 : dir - 1;
		int next_y = y + dy[nextDir];
		int next_x = x + dx[nextDir];

		if (map[next_x][next_y] == 0) {
			dfs(next_x, next_y, nextDir);
			// 다음 칸으로 넘어간 경우 나머지 검사 X
			return;
		}
		else {
			// 청소를 했거나 벽이면 방향만 바꿈
			dir = nextDir;
		}
	}

	// 네 방향 모두 청소했거나 벽이면 방향을 유지한채로 후진
	// 0 -> 2 / 1-> 3 / 2 -> 0 / 3 -> 1
	int nextDir = (dir + 2) % 4;
	dfs(x + dx[nextDir], y + dy[nextDir], dir);
}

int main() {
	//input
	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &r, &c, &d);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	//init
	cnt = 0;

	//logic
	dfs(r, c, d);

	//result
	printf("%d\n", cnt);

	return 0;
}