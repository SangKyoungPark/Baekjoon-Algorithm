#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

char cube[7][4][4] = {
	{{'w','w','w'},
	{'w','w','w'},
	{'w','w','w'}}, // 위
	
	{{'o','o','o'},
	{'o','o','o'},
	{'o','o','o'}}, // 뒤
	
	{{'y','y','y'},
	{'y','y','y'},
	{'y','y','y'}}, // 아래
	
	{{'r','r','r'},
	{'r','r','r'},
	{'r','r','r'}}, // 앞

	{{'g','g','g'},
	{'g','g','g'},
	{'g','g','g'}}, // 좌
	
	{{'b','b','b'},
	{'b','b','b'},
	{'b','b','b'}} // 우
};

// area 면적을 dir 방향으로 돌림
void turnCube(char area, char dir) {
	if (area == 'U') {
		if(dir == '+'){

		}
		else {

		}
	}
}

void printUpside() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%c", cube[0][i][j]);
		}
		printf("\n");
	}
}
int main() {
	int n{};
	int data{};
	char area{}, dir{};

	// Input Data
	scanf("%d", &n);
	for (int t = 0; t < n; t++) {
		scanf("%d", &data);
		for (int i = 0; i < data; i++) {
			scanf(" %1c %1c", &area, &dir);

			// Logic
			turnCube(area, dir);
		}
		printUpside();
	}
	// Init
	// Result
	return 0;
}