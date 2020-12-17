#include <iostream> #include <algorithm> using namespace std; char up[9]; char down[9]; char front[9]; char back[9]; char left_my[9]; char right_my[9]; char ans[100][9]; void rotate_surface(char sur, char dir) { char temp[9]; if (sur == 'u') { copy(up, up + 9, temp); if (dir == '+') { up[0] = temp[6]; up[1] = temp[3]; up[2] = temp[0]; up[3] = temp[7]; up[4] = temp[4]; up[5] = temp[1]; up[6] = temp[8]; up[7] = temp[5]; up[8] = temp[2]; } else { up[0] = temp[2]; up[1] = temp[5]; up[2] = temp[8]; up[3] = temp[1]; up[4] = temp[4]; up[5] = temp[7]; up[6] = temp[0]; up[7] = temp[3]; up[8] = temp[6]; } } else if (sur == 'd') { copy(down, down + 9, temp); if (dir == '+') { down[0] = temp[6]; down[1] = temp[3]; down[2] = temp[0]; down[3] = temp[7]; down[4] = temp[4]; down[5] = temp[1]; down[6] = temp[8]; down[7] = temp[5]; down[8] = temp[2]; } else { down[0] = temp[2]; down[1] = temp[5]; down[2] = temp[8]; down[3] = temp[1]; down[4] = temp[4]; down[5] = temp[7]; down[6] = temp[0]; down[7] = temp[3]; down[8] = temp[6]; } } else if (sur == 'f') { copy(front, front + 9, temp); if (dir == '+') { front[0] = temp[6]; front[1] = temp[3]; front[2] = temp[0]; front[3] = temp[7]; front[4] = temp[4]; front[5] = temp[1]; front[6] = temp[8]; front[7] = temp[5]; front[8] = temp[2]; } else { front[0] = temp[2]; front[1] = temp[5]; front[2] = temp[8]; front[3] = temp[1]; front[4] = temp[4]; front[5] = temp[7]; front[6] = temp[0]; front[7] = temp[3]; front[8] = temp[6]; } } else if (sur == 'b') { copy(back, back + 9, temp); if (dir == '+') { back[0] = temp[6]; back[1] = temp[3]; back[2] = temp[0]; back[3] = temp[7]; back[4] = temp[4]; back[5] = temp[1]; back[6] = temp[8]; back[7] = temp[5]; back[8] = temp[2]; } else { back[0] = temp[2]; back[1] = temp[5]; back[2] = temp[8]; back[3] = temp[1]; back[4] = temp[4]; back[5] = temp[7]; back[6] = temp[0]; back[7] = temp[3]; back[8] = temp[6]; } } else if (sur == 'l') { copy(left_my, left_my + 9, temp); if (dir == '+') { left_my[0] = temp[6]; left_my[1] = temp[3]; left_my[2] = temp[0]; left_my[3] = temp[7]; left_my[4] = temp[4]; left_my[5] = temp[1]; left_my[6] = temp[8]; left_my[7] = temp[5]; left_my[8] = temp[2]; } else { left_my[0] = temp[2]; left_my[1] = temp[5]; left_my[2] = temp[8]; left_my[3] = temp[1]; left_my[4] = temp[4]; left_my[5] = temp[7]; left_my[6] = temp[0]; left_my[7] = temp[3]; left_my[8] = temp[6]; } } else /* if (sur == 'r') */ { copy(right_my, right_my + 9, temp); if (dir == '+') { right_my[0] = temp[6]; right_my[1] = temp[3]; right_my[2] = temp[0]; right_my[3] = temp[7]; right_my[4] = temp[4]; right_my[5] = temp[1]; right_my[6] = temp[8]; right_my[7] = temp[5]; right_my[8] = temp[2]; } else { right_my[0] = temp[2]; right_my[1] = temp[5]; right_my[2] = temp[8]; right_my[3] = temp[1]; right_my[4] = temp[4]; right_my[5] = temp[7]; right_my[6] = temp[0]; right_my[7] = temp[3]; right_my[8] = temp[6]; } } } void rotate_up() { char t_1, t_2, t_3; t_1 = right_my[0]; t_2 = right_my[1]; t_3 = right_my[2]; right_my[0] = back[0]; right_my[1] = back[1]; right_my[2] = back[2]; back[0] = left_my[0]; back[1] = left_my[1]; back[2] = left_my[2]; left_my[0] = front[0]; left_my[1] = front[1]; left_my[2] = front[2]; front[0] = t_1; front[1] = t_2; front[2] = t_3; } void rotate_down() { char t_1, t_2, t_3; t_1 = right_my[6]; t_2 = right_my[7]; t_3 = right_my[8]; right_my[6] = front[6]; right_my[7] = front[7]; right_my[8] = front[8]; front[6] = left_my[6]; front[7] = left_my[7]; front[8] = left_my[8]; left_my[6] = back[6]; left_my[7] = back[7]; left_my[8] = back[8]; back[6] = t_1; back[7] = t_2; back[8] = t_3; } void rotate_front() { char t_1, t_2, t_3; t_1 = right_my[0]; t_2 = right_my[3]; t_3 = right_my[6]; right_my[0] = up[6]; right_my[3] = up[7]; right_my[6] = up[8]; up[6] = left_my[8]; up[7] = left_my[5]; up[8] = left_my[2]; left_my[2] = down[8]; left_my[5] = down[7]; left_my[8] = down[6]; down[6] = t_1; down[7] = t_2; down[8] = t_3; } void rotate_back() { char t_1, t_2, t_3; t_1 = right_my[2]; t_2 = right_my[5]; t_3 = right_my[8]; right_my[2] = down[0]; right_my[5] = down[1]; right_my[8] = down[2]; down[0] = left_my[6]; down[1] = left_my[3]; down[2] = left_my[0]; left_my[0] = up[2]; left_my[3] = up[1]; left_my[6] = up[0]; up[0] = t_1; up[1] = t_2; up[2] = t_3; } void rotate_left() { char t_1, t_2, t_3; t_1 = front[0]; t_2 = front[3]; t_3 = front[6]; front[0] = up[0]; front[3] = up[3]; front[6] = up[6]; up[0] = back[8]; up[3] = back[5]; up[6] = back[2]; back[2] = down[2]; back[5] = down[5]; back[8] = down[8]; down[2] = t_3; down[5] = t_2; down[8] = t_1; } void rotate_right() { char t_1, t_2, t_3; t_1 = front[2]; t_2 = front[5]; t_3 = front[8]; front[2] = down[6]; front[5] = down[3]; front[8] = down[0]; down[0] = back[0]; down[3] = back[3]; down[6] = back[6]; back[0] = up[8]; back[3] = up[5]; back[6] = up[2]; up[2] = t_1; up[5] = t_2; up[8] = t_3; } // rotation : 12 possibilities void rotate(char sur, char dir) { char t_1, t_2, t_3; // rotate chosen surface as well rotate_surface(sur, dir); if (sur == 'u') { if (dir == '+') { rotate_up(); } else { rotate_up(); rotate_up(); rotate_up(); } } else if (sur == 'd') { if (dir == '+') { rotate_down(); } else { rotate_down(); rotate_down(); rotate_down(); } } else if (sur == 'f') { if (dir == '+') { rotate_front(); } else { rotate_front(); rotate_front(); rotate_front(); } } else if (sur == 'b') { if (dir == '+') { rotate_back(); } else { rotate_back(); rotate_back(); rotate_back(); } } else if (sur == 'l') { if (dir == '+') { rotate_left(); } else { rotate_left(); rotate_left(); rotate_left(); } } else /* if (sur == 'r') */ { if (dir == '+') { rotate_right(); } else { rotate_right(); rotate_right(); rotate_right(); } } } int main() { int n; int rolls; char inst[3]; cin >> n; for (int test_case = 0; test_case < n; test_case++) { fill(up, up + 9, 'w'); fill(down, down + 9, 'y'); fill(front, front + 9, 'r'); fill(back, back + 9, 'o'); fill(left_my, left_my + 9, 'g'); fill(right_my, right_my + 9, 'b'); cin >> rolls; for (int roll = 0; roll < rolls; roll++) { cin >> inst; rotate(inst[0], inst[1]); } for (int i = 0; i < 9; i++) { ans[test_case][i] = up[i]; } } // print "up" surface for (int k = 0; k < n; k++) { for (int i = 0; i < 3; i++) { for (int j = 0; j < 3; j++) { cout << ans[k][i * 3 + j]; } cout << endl; } } }
#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

/* cube */
char white_U[3][3];
char orange_B[3][3];
char green_L[3][3];
char blue_R[3][3];
char red_F[3][3];
char yellow_D[3][3];
/* //cube */

int T, n;
char cmd_Demesion, cmd_dir;

void initCube() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			white_U[i][j] = 'w';
			orange_B[i][j] = 'o';
			green_L[i][j] = 'g';
			blue_R[i][j] = 'b';
			red_F[i][j] = 'r';
			yellow_D[i][j] = 'y';
		}
	}
}
void simulation(char cmd_Demesion, char cmd_dir) {
	switch (cmd_Demesion)
	{
	case 'L':
		if (cmd_dir == '-') {
			char temp[3][3];
			for (int i = 0; i < 3; i++) {
				temp[i][0] = white_U[i][0];
				white_U[i][0] = red_F[i][0];//
				red_F[i][0] = yellow_D[2 - i][2];
				yellow_D[2 - i][2] = orange_B[2 - i][2];
				orange_B[2 - i][2] = temp[i][0];
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					temp[2 - j][i] = green_L[i][j];
				}
			}
			memcpy(green_L, temp, sizeof(green_L));
		}
		else {
			char temp[3][3];
			for (int i = 0; i < 3; i++) {
				temp[i][0] = white_U[i][0];
				white_U[i][0] = orange_B[2 - i][2];
				orange_B[2 - i][2] = yellow_D[2 - i][2];
				yellow_D[2 - i][2] = red_F[i][0];
				red_F[i][0] = temp[i][0];
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					temp[j][2 - i] = green_L[i][j];
				}
			}
			memcpy(green_L, temp, sizeof(green_L));
		}
		break;

	case 'R':
		if (cmd_dir == '-') {
			char temp[3][3];
			for (int i = 0; i < 3; i++) {
				temp[i][0] = white_U[i][2];
				white_U[i][2] = orange_B[2 - i][0];
				orange_B[2 - i][0] = yellow_D[2 - i][0];
				yellow_D[2 - i][0] = red_F[i][2];
				red_F[i][2] = temp[i][0];
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					temp[2 - j][i] = blue_R[i][j];
				}
			}
			memcpy(blue_R, temp, sizeof(blue_R));
		}
		else {
			char temp[3][3];
			for (int i = 0; i < 3; i++) {
				temp[i][0] = white_U[i][2];
				white_U[i][2] = red_F[i][2];//
				red_F[i][2] = yellow_D[2 - i][0];
				yellow_D[2 - i][0] = orange_B[2 - i][0];
				orange_B[2 - i][0] = temp[i][0];
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					temp[j][2 - i] = blue_R[i][j];
				}
			}
			memcpy(blue_R, temp, sizeof(blue_R));
		}
		break;

	case 'F':
		if (cmd_dir == '-') {
			char temp[3][3];
			for (int i = 0; i < 3; i++) {
				temp[i][0] = white_U[2][i];
				white_U[2][i] = blue_R[i][0];
				blue_R[i][0] = yellow_D[2][i];
				yellow_D[2][i] = green_L[2 - i][2];
				green_L[2 - i][2] = temp[i][0];
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					temp[2 - j][i] = red_F[i][j];
				}
			}
			memcpy(red_F, temp, sizeof(red_F));
		}
		else {
			char temp[3][3];
			for (int i = 0; i < 3; i++) {
				temp[i][0] = white_U[2][i];
				white_U[2][i] = green_L[2 - i][2];
				green_L[2 - i][2] = yellow_D[2][i];
				yellow_D[2][i] = blue_R[i][0];
				blue_R[i][0] = temp[i][0];
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					temp[j][2 - i] = red_F[i][j];
				}
			}
			memcpy(red_F, temp, sizeof(red_F));
		}
		break;

	case 'B':
		if (cmd_dir == '-') {
			char temp[3][3];
			for (int i = 0; i < 3; i++) {
				temp[i][0] = white_U[0][i];
				white_U[0][i] = green_L[2 - i][0];
				green_L[2 - i][0] = yellow_D[0][i];
				yellow_D[0][i] = blue_R[i][2];
				blue_R[i][2] = temp[i][0];
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					temp[2 - j][i] = orange_B[i][j];
				}
			}
			memcpy(orange_B, temp, sizeof(orange_B));
		}
		else {
			char temp[3][3];
			for (int i = 0; i < 3; i++) {
				temp[i][0] = white_U[0][i];
				white_U[0][i] = blue_R[i][2];
				blue_R[i][2] = yellow_D[0][i];
				yellow_D[0][i] = green_L[2 - i][0];
				green_L[2 - i][0] = temp[i][0];
			}

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					temp[j][2 - i] = orange_B[i][j];
				}
			}
			memcpy(orange_B, temp, sizeof(orange_B));
		}
		break;

	case 'U':
		if (cmd_dir == '-') {
			char temp[3][3];
			for (int i = 0; i < 3; i++) {
				temp[i][0] = red_F[0][i];
				red_F[0][i] = green_L[0][i];
				green_L[0][i] = orange_B[0][i];
				orange_B[0][i] = blue_R[0][i];
				blue_R[0][i] = temp[i][0];
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					temp[2 - j][i] = white_U[i][j];
				}
			}
			memcpy(white_U, temp, sizeof(white_U));
		}
		else {
			char temp[3][3];
			for (int i = 0; i < 3; i++) {
				temp[i][0] = red_F[0][i];
				red_F[0][i] = blue_R[0][i];
				blue_R[0][i] = orange_B[0][i];
				orange_B[0][i] = green_L[0][i];
				green_L[0][i] = temp[i][0];
			}

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					temp[j][2 - i] = white_U[i][j];
				}
			}
			memcpy(white_U, temp, sizeof(white_U));
		}
		break;

	case 'D':
		if (cmd_dir == '-') {
			char temp[3][3];
			for (int i = 0; i < 3; i++) {
				temp[i][0] = red_F[2][i];
				red_F[2][i] = blue_R[2][i];
				blue_R[2][i] = orange_B[2][i];
				orange_B[2][i] = green_L[2][i];
				green_L[2][i] = temp[i][0];
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					temp[2 - j][i] = yellow_D[i][j];
				}
			}
			memcpy(yellow_D, temp, sizeof(yellow_D));
		}
		else {
			char temp[3][3];
			for (int i = 0; i < 3; i++) {
				temp[i][0] = red_F[2][i];
				red_F[2][i] = green_L[2][i];
				green_L[2][i] = orange_B[2][i];
				orange_B[2][i] = blue_R[2][i];
				blue_R[2][i] = temp[i][0];
			}

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					temp[j][2 - i] = yellow_D[i][j];
				}
			}
			memcpy(yellow_D, temp, sizeof(yellow_D));
		}
		break;
	}
	return;
}

int main() {
	//Input Data
	scanf("%d ", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d ", &n);
		//Init
		initCube();
		//Logic
		for (int j = 0; j < n; j++) {
			scanf(" %c%c", &cmd_Demesion, &cmd_dir);
			simulation(cmd_Demesion, cmd_dir);
		}
		//Result
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				printf("%c", white_U[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
