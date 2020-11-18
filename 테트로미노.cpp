#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 510;
typedef struct {
    int y, x;
}point;

point moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int N, M;
int map[MAX][MAX];
bool v[MAX][MAX];

//function
int dfs(point p, int cnt);
int middleFinger(int y, int x);

int main(void) {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    int result = -987987987;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            v[i][j] = true;
            result = max(result, dfs({ i,j }, 1));
            result = max(result, middleFinger(i, j));
            v[i][j] = false; //꼭 처리해줘야한다
        }
    }

    printf("%d", result);

    return 0;
}

int dfs(point p, int cnt)
{
    if (cnt == 4)
        return map[p.y][p.x];

    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        int y = p.y + moveDir[i].y;
        int x = p.x + moveDir[i].x;

        if (0 <= y && y < N && 0 <= x && x < M && !v[y][x])
        {
            v[y][x] = true;
            sum = max(sum, map[p.y][p.x] + dfs({ y, x }, cnt + 1));
            v[y][x] = false; //꼭 처리해줘야한다
        }
    }
    return sum;
}


int middleFinger(int y, int x) {

    int result = -987987987;

    //ㅗ (현재 좌표 ㅡ의 가운데)
    if (y >= 1 && x >= 1 && x < M - 1)
        result = max(result, map[y][x - 1] + map[y][x] + map[y - 1][x] + map[y][x + 1]);

    //ㅏ (현재 좌표 ㅣ의 가운데)
    if (y >= 1 && y < N - 1 && x < M - 1)
        result = max(result, map[y - 1][x] + map[y][x] + map[y][x + 1] + map[y + 1][x]);

    //ㅜ (현재 좌표 ㅡ의 가운데)
    if (y >= 0 && y < N - 1 && x < M - 1)
        result = max(result, map[y][x - 1] + map[y][x] + map[y + 1][x] + map[y][x + 1]);

    //ㅓ (현재 좌표 ㅣ의 가운데)
    if (y >= 1 && y < N - 1 && x >= 1)
        result = max(result, map[y - 1][x] + map[y][x] + map[y][x - 1] + map[y + 1][x]);

    return result;
}
