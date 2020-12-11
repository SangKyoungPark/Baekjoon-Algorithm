// 50 by 50 map 에서 단지번호 붙이기
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX -987987897
#define MIN 987987987

int arr[15];
int sign[4];
int booho[15];
int n;
int cntBooho;
int cntSign;
int myMax, myMin;

int getCalc() {
	//부호에 따라 계산
	int data = arr[0];

	int k = 1;
	int i = 0;
	while (1) {
		if (k == n + 1) break;

		if (booho[i] == 0) {
			data += arr[k];
		}
		else if (booho[i] == 1) {
			data -= arr[k];
		}
		else if (booho[i] == 2) {
			data *= arr[k];
		}
		else if (booho[i] == 3) {
			data /= arr[k];
		}
		i++;
		k++;
	}
	return data;
}

void setBooho(int cnt, int x) {
	// 개수에 맞게 부호 설정
	if (cnt == 0) {
		int res = getCalc();
		myMax = max(myMax, res);
		myMin = min(myMin, res);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (sign[i]) {
			sign[i]--;
			booho[x] = i;
			setBooho(cnt - 1, x + 1);
			sign[i]++;
		}
	}
}

int main() {
	int data;

	//init
	myMax = MAX;
	myMin = MIN;
	cntSign = 0;

	//input data
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < 4; i++) {
		scanf("%d", &data);
		sign[i] = data;
		cntSign += data;
	}

	//logic
	setBooho(cntSign, 0);
	//result
	printf("%d\n", myMax);
	printf("%d\n", myMin);
	return 0;
}