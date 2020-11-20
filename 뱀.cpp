#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int n, k, m;
int x, y, z, d, ans;
int a[120][120], t[120];
char c[120];
const int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };
const int L[] = { 3, 2, 0, 1 }, D[] = { 2, 3, 1, 0 };
queue<pair<int, int>> q;

void solve() {
    //¹ì ÁÂÇ¥ Å¥¿¡ »ðÀÔ
    a[0][0] = 2;
    q.push({ 0, 0 });

    //logic
    while (true) {
        x += dx[d], y += dy[d];
        ans++;
        if (x < 0 || x >= n || y < 0 || y >= n || a[x][y] == 2) {
            printf("%d\n", ans);
            return;
        }
        if (a[x][y] == 0) {
            int nx = q.front().first, ny = q.front().second; q.pop();
            a[nx][ny] = 0;
        }
        a[x][y] = 2;
        q.push({ x, y });

        if (ans == t[z]) {
            if (c[z] == 'L') d = L[d];
            else d = D[d];
            z++;
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u - 1][v - 1] = 1;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %c", &t[i], &c[i]);
    }
    solve();
    return 0;
}
