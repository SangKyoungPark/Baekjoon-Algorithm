// 2020 Samsung Electronics Coding Test Problem

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <deque>
using namespace std;

#define SIZE 102

int n{}, k{};
int step{};

deque <int> dura{}; // ³»±¸¼º
deque <bool> belt{}; // º§Æ®

void rotate() {
	belt.push_front(belt.back());
	belt.pop_back();
	dura.push_front(dura.back());
	dura.pop_back();

	belt[n - 1] = false;
}

void moveRobot() {
	for (int i = n - 2; i >= 0; i--) {
		if (!belt[i + 1] && dura[i + 1] > 0 && belt[i]) {
			belt[i] = false;
			belt[i + 1] = true;
			dura[i + 1]--;
		}
	}
	belt[n - 1] = false;
}

void putRobot() {
	if (!belt[0] && dura[0] > 0) {
		belt[0] = true;
		dura[0]--;
	}
}

bool isExit() {
	int cnt = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (dura[i] == 0)	cnt++;
	}
	if (cnt >= k)	return true;
	return false;
}

int main() {
	//input data
	scanf("%d %d", &n, &k);
	int len = 2 * n;
	for (int i = 0; i < len; i++) {
		int data{};
		scanf("%d", &data);

		dura.push_back(data);
		belt.push_back(false);
	}

	//init
	step = 1;

	//logic
	/* 
	1. rotate
	2. isMove()  O -> move
				 X -> maintain
	3. robot X -> put on belt -> belt[0]
	4. durability >= k // print(time)
	*/

	while (true) {
		rotate();
		moveRobot();
		putRobot();
		if (isExit())	break;
		step++;
	}

	//result
	printf("%d\n", step);
	return 0;
}
