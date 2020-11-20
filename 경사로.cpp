#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int n, l, res;
int a[100][100];

void slope(int i, bool c) {
    int cnt = 1;
    for (int j = 0; j < n - 1; j++) {
        int d; // 높이 차이 계산
        if (c == 1) { // 가로
            d = a[i][j + 1] - a[i][j];
        }
        else { // 세로
            d = a[j + 1][i] - a[j][i];
        }
        
        if (d == 0) cnt++;
        else if (d == 1 && cnt >= l) cnt = 1;
        else if (d == -1 && cnt >= 0) cnt = -l + 1;
        else return;
    }
    if (cnt >= 0) res += 1;
}

void solve() {
    for (int i = 0; i < n; i++) {
        slope(i, 1); // 가로
        slope(i, 0); // 세로
    }
}

int main() {
    // Input Data
    scanf("%d %d", &n, &l);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    // Logic
    solve();

    // Result
    printf("%d\n", res);
    return 0;
}
