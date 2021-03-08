#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
using namespace std;

#define SIZE 22

struct S_POS {
	int y{};
	int x{};
};

int n{}, m{}, fuel{};
int map[SIZE][SIZE]{};

S_POS gest[SIZE*SIZE]{};
S_POS dest[SIZE*SIZE]{};
S_POS taxi{};

int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };

bool flag = false;
bool change = false;

bool isPossible(int len) {
	if (fuel < len)	return false;
	return true;
}

void bfs(S_POS target) {
	queue <S_POS> Q{};
	int cost[SIZE][SIZE]{};

	Q.push(taxi);

	while (!Q.empty()) {
		S_POS cur = Q.front();
		Q.pop();

		for (int k = 0; k < 4; k++) {
			S_POS p = { cur.y + dy[k], cur.x + dx[k] };
			if (p.y<1 || p.x <1 || p.y > n || p.x > n)	continue;
			if (p.y == target.y && p.x == target.x) {
				if (isPossible(cost[p.y][p.x])) {
					fuel -= (cost[p.y][p.x]+1);
					taxi.y = p.y;
					taxi.x = p.x;
					if (change) {
						fuel += (2*(cost[p.y][p.x]+1));
					}
					return;
				}
				else {
					fuel = -1;
					flag = true;
					return;
				}
			}
			else if (map[p.y][p.x] == 0) {
				cost[p.y][p.x] = cost[cur.y][cur.x] + 1;
			}
		}
	}
}

int getNearTarget() {
	queue <S_POS> Q{};
	Q.push(taxi);

	while (!Q.empty()) {
		S_POS cur = Q.front();
		Q.pop();

		for (int k = 0; k < 4; k++) {
			S_POS p = { cur.y + dy[k], cur.x + dx[k] };
			if (p.y<1 || p.x <1 || p.y > n || p.x > n)	continue;
			if (map[p.y][p.x] == 0) {
				for (int i = 1; i <= m; i++) {
					if (p.y == gest[i].y && p.x == gest[i].x) {
						return i;
					}
				}
				Q.push(p);
			}
		}
	}
}

bool solve() {
	int idx = getNearTarget();
	//taxi -> gest[idx]
	bfs(gest[idx]);
	if (flag) return true;
	change = true;
	//taxi + gest -> dest[idx]
	bfs(dest[idx]);
	change = false;
	if (flag) return true;
}

int main() {
	//input data
	scanf("%d %d %d", &n, &m, &fuel);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	scanf("%d %d", &taxi.y, &taxi.x);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d %d", &gest[i].y, &gest[i].x, &dest[i].y, &dest[i].x);
	}

	//logic
	for (int i = 1; i <= m; i++) {
		if (solve()) {
			break;
		}
	}

	//result
	printf("%d\n", fuel);

	return 0;
}