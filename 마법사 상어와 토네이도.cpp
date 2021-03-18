#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
using namespace std;

int N{};
int res{};
int cnt{};

vector<vector<int>> map{};

// 움직이는 모래의 정도
double p[9] = { 0.05, 0.1, 0.1, 0.02, 0.02, 0.07, 0.07, 0.01, 0.01 };

// 좌 하 우 상
int dy[] = { 0,1,0,-1 };
int dx[] = { -1, 0,1,0 };
int m_dy[4][10] = {
	{0,-1,1, -2,2,-1,1,-1,1,0},
	{2,1,1,0,0,0,0,-1,-1,1},
	{0,-1,1, -2,2,-1,1,-1,1,0},
	{-2,-1,-1,0,0,0,0,1,1,-1}
};
int m_dx[4][10] = {
	{-2,-1,-1,0,0,0,0,1,1,-1},
	{0,-1,1, -2,2,-1,1,-1,1,0},
	{2,1,1,0,0,0,0,-1,-1,1},
	{0,-1,1, -2,2,-1,1,-1,1,0}
};

void spread() {
	int y = N / 2, x = N / 2; // 배열의 중간 좌표
	int dist = 1;
	int d = 0; // 방향 정보 ( 0 : 좌, 1 : 하, 2 : 우, 3 : 상)
	int cnt = 0; // 두 번 이동 확인용 count 변수
	while (true) {
		cnt++;
		for (int m = 0; m < dist; m++) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			y = ny;
			x = nx;
			int sand = map[ny][nx]; // 이동한 모래 
			for (int k = 0; k < 9; k++) {
				int m_ny = ny + m_dy[d][k]; //흩날리는 모래 y 좌표
				int m_nx = nx + m_dx[d][k]; //흩날리는 모래 x 좌표
				int m_sand = (int)(map[ny][nx] * p[k]); //흩날리는 모래 양
				sand -= m_sand; // 이동한 모래에서 흩날리는 모래를 빼줌
				if (m_ny < 0 || m_ny >= N || m_nx < 0 || m_nx >= N) {
					res += m_sand;
				}
				else {
					map[m_ny][m_nx] += m_sand;
				}
			}
			//나머지 모래 이동
			int m_ny = ny + m_dy[d][9];
			int m_nx = nx + m_dx[d][9];
			if (m_ny < 0 || m_ny >= N || m_nx < 0 || m_nx >= N) {
				res += sand;
			}
			else
				map[m_ny][m_nx] += sand;

			map[ny][nx] = 0; // 이동 후 모래 = 0으로 지정
			if (ny == 0 && nx == 0) //이동 후 좌표가 (0, 0)인 경우 종료
				return;
		}
		if (cnt == 2) {
			//두 번 이동한 경우 dist+=1
			dist++;
			cnt = 0;
		}
		d = (d + 1) % 4; // 이동 방향을 바꿈
	}
}
int main() {
	//input data
	scanf("%d", &N);
	
	map = vector<vector<int> >(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	//모래 이동
	spread();

	//결과 출력
	printf("%d", res);
}