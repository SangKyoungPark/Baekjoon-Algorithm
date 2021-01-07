#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N, K;
int dir[11]; // →:1, ←:2, ↑:3, ↓:4
int board[12][12]; // 0:흰, 1:빨, 2:파
int exitTurn = -1; // 말 4개가 쌓이는 종료턴
bool eixtFlag = false; // 말 4개가 쌓이는 종료조건

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

pair<int, int> v[10]; // 말들의 좌표
vector<int> vInfo[20][20]; // 각각의 셀 안에 쌓이는 말정보 저장

bool check_next(int i) {
	int r = v[i].first;
	int c = v[i].second;

	if (dir[i] == 1) { if (c + 1 >= N || board[r][c + 1] == 2) return false; }
	else if (dir[i] == 2) { if (c - 1 < 0 || board[r][c - 1] == 2) return false; }
	else if (dir[i] == 3) { if (r - 1 < 0 || board[r - 1][c] == 2) return false; }
	else if (dir[i] == 4) { if (r + 1 >= N || board[r + 1][c] == 2) return false; }

	return true;
}

int updateDir(int d) {
	if (d == 1) return 2;
	else if (d == 2) return 1;
	else if (d == 3) return 4;
	else if (d == 4) return 3;
	return 0;
}

void move_piece(int i) {
	int r = v[i].first;
	int c = v[i].second;

	if (dir[i] == 1) { if (c + 1 >= N || board[r][c + 1] == 2) return; }
	else if (dir[i] == 2) { if (c - 1 < 0 || board[r][c - 1] == 2) return; }
	else if (dir[i] == 3) { if (r - 1 < 0 || board[r - 1][c] == 2) return; }
	else if (dir[i] == 4) { if (r + 1 >= N || board[r + 1][c] == 2) return; }

	int pos = 0;
	// 1. 해당 셀에서 말이 업힌 스택 위치 찾음
	for (int p = 0; p < vInfo[r][c].size(); p++) {
		if (vInfo[r][c].at(p) == i) {
			pos = p;
			break;
		}
	}
	// 2. 업힌 위치 뒤로의 벡터 다음 위치로 옮겨줌
	int rr = r + dx[dir[i] - 1];
	int cc = c + dy[dir[i] - 1];
	vector<int> tmp;
	for (int p = pos; p < vInfo[r][c].size(); p++) {
		int pNum = vInfo[r][c].at(p);
		tmp.push_back(pNum);

		v[pNum].first = rr;
		v[pNum].second = cc;
	}

	// 3. 만약 다음 위치가 빨간색이면 말들의 업힌 순서를 뒤집고, 하얀색이면 그대로 둠
	if (board[rr][cc] == 1) reverse(tmp.begin(), tmp.end());
	for (int i = 0; i < tmp.size(); i++) {
		vInfo[rr][cc].push_back(tmp.at(i));
	}

	if (vInfo[rr][cc].size() >= 4) eixtFlag = true;

	int siz = vInfo[r][c].size();
	for (int p = pos; p < siz; p++) vInfo[r][c].pop_back();
}

void solve() {
	for (int i = 0; i < K; i++) {
		if (eixtFlag) break;
		if (!check_next(i)) dir[i] = updateDir(dir[i]);
		move_piece(i);
	}
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		cin >> v[i].first >> v[i].second;
		v[i].first--;
		v[i].second--;
		cin >> dir[i];
		vInfo[v[i].first][v[i].second].push_back(i);
	}

	for (int i = 0; i < 1000; i++) {
		solve();

		if (eixtFlag) {
			exitTurn = i + 1;
			break;
		}
	}

	cout << exitTurn << endl;
	return 0;
}
