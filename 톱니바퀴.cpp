#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int tobni[4][8];
int k, n, d;
int res;

void updateTobni(int x, int d) {
    int temp[8];
    if (d == 1) { // 시계 (현->다음)
        for (int i = 0; i < 8; i++) {
            temp[(i + 1) % 8] = tobni[x][i];
        }
    }
    else { // 반시계 (다음->현)
        for (int i = 0; i < 8; i++) {
            temp[i] = tobni[x][(i + 1)%8];
        }
    }
    // copy
    for (int i = 0; i < 8; i++) {
        tobni[x][i] = temp[i];
    }
}

void solve() {
    for(int t=0; t<k; t++){
        scanf("%d %d", &n, &d);

        int direct[4] = { 0 };
        direct[n-1] = d;

        for (int i = n-1; i < 3; i++) {
            if (tobni[i][2] != tobni[i + 1][6]) direct[i + 1] = -direct[i];
        }
        for (int i = n-1; i > 0; i--) {
            if (tobni[i][6] != tobni[i - 1][2]) direct[i - 1] = -direct[i];
        }

        for (int i = 0; i < 4; i++) {
            if (direct[i]) {
                updateTobni(i, direct[i]);
            }
        }
    }
}

int main() {
    // input data
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            scanf("%1d", &tobni[i][j]);
        }
    }
    
    scanf("%d", &k);
    //logic
    solve();
    // calculation
    for (int i = 0; i < 4; i++) {
        if (tobni[i][0]) res += (1 << i);
    }
    // result
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%d ", tobni[i][j]);
        }
        printf("\n");
    }
    printf("%d\n", res);
    return 0;
}