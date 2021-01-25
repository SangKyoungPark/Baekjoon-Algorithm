#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

int n;
int arr[1000010]{};
int b, c;
long long int myMin = 0;

long long int func(int idx) {
    int cnt = 0;
    if (arr[idx] <= 0) return 0;
    cnt += (arr[idx] / c);
    if (arr[idx] % c > 0)   cnt++;
    return cnt;
}

int main() {
    //input
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d %d", &b, &c);

    //logic
    myMin += n; // 각 방에 1명은 무조건 있기 때문에 필요한 총감독관수와 같음
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        arr[i] -= b;
        cnt = func(i);   // arr[i]에 필요한 총감독관 1 + 부감독관 수 return
        myMin += cnt;
    }

    //result
    printf("%lld\n", myMin);
}
