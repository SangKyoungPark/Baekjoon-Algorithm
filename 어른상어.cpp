#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

#define SIZE 20

struct SHARK {
	int y{};
	int x{};
	int dir{};
	int order[5][5]{};
	bool isDead;
};

int n{}, m{}, k{};
int res{};
int map[SIZE][SIZE]{};

pair <int, int> smell[SIZE][SIZE]{};
SHARK shark[SIZE * SIZE]{};

int dy[] = { 0,-1,1,0,0 };
int dx[] = { 0,0,0,-1,1 };

int main(void){
	//input data
	scanf("%d %d %d", &n, &m, &k);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			// shark info
			if (map[i][j]!=0) {
				shark[map[i][j]].y = i;
				shark[map[i][j]].x = j;
				shark[map[i][j]].isDead = false;
				smell[i][j].first = map[i][j];
				smell[i][j].first = k;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &shark[i].dir);
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int l = 1; l <= 4; l++) {
				scanf("%d", &shark[i].order[j][l]);
			}
		}
	}

	//init
	res = 1;

	//logic
	while (res <= 1000) {
		//  move
		for (int i = 1; i <= m; i++) {
			if (shark[i].isDead)	continue;

			bool isGo = false;
			for (int d = 1; d <= 4; d++) {
				//new stage
				int y = shark[i].y + dy[shark[i].order[shark[i].dir][d]];
				int x = shark[i].x + dx[shark[i].order[shark[i].dir][d]];

				if (y < 0 || x < 0 || y >= n || x >= n || smell[y][x].first!= 0)	continue;

				isGo = true;

				//상어가 이동할 때
				if (map[y][x] != 0) {
					if (map[y][x] < i) {
						shark[i].isDead = true;
						map[shark[i].y][shark[i].x] = 0;
					}
					else {
						shark[map[y][x]].isDead = true;

						map[shark[i].y][shark[i].x] = 0;
						shark[i].y = y;
						shark[i].x = x;
						shark[i].dir = shark[i].order[shark[i].dir][d];
						map[y][x] = i;
					}
				}
				else {
					map[shark[i].y][shark[i].x] = 0;
					shark[i].y = y;
					shark[i].x = x;
					shark[i].dir = shark[i].order[shark[i].dir][d];
					map[y][x] = i;
				}
				break;
			}
			// 상어가 이동하지 않을 때
			if (!isGo) {
				for (int d = 1; d <= 4; d++) {
					int y = shark[i].y + dy[shark[i].order[shark[i].dir][d]];
					int x = shark[i].x + dx[shark[i].order[shark[i].dir][d]];

					if (y < 0 || x < 0 || y >= n || x >= n)	continue;

					if (smell[y][x].first == i) {
						map[shark[i].y][shark[i].x] = 0;
						shark[i].y = y;
						shark[i].x = x;
						shark[i].dir = shark[i].order[shark[i].dir][d];
						map[y][x] = i;
						break;
					}
				}
			}
		}
		//move end

		//smell remove
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (smell[i][j].first != 0) {
					smell[i][j].second--;
					if (smell[i][j].second == 0)	smell[i][j].first = 0;
				}
			}
		}
		//smell spread
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] != 0) {
					smell[i][j].first = map[i][j];
					smell[i][j].second = k;
				}
			}
		}

		// 1번 상어만 남았는지?
		bool isEnd = true;
		for (int i = 2; i <= m; i++) {
			if (shark[i].isDead == false) {
				isEnd = false;
				break;
			}
		}
		if (isEnd) {
			printf("%d", res);
			return 0;
		}
		else {
			res++;
		}
	}
	printf("-1");
	return 0;
}