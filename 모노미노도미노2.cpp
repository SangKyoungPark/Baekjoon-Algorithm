/*
# Q
- 얻은 점수와 초록, 파란색 보드에 타일이 있는 칸의 개수를 모두 구해라.

# Algo
- 초록, 파란색 보드판 모두 같은 로직에 의해 진행됨
- 2차원 배열 사용

1. 타일을 보드에 배치 (1/2/3 에 맞는 타일)
2. 점수 획득 판단
3. 연한 칸 블록 처리
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n{};
int bCnt{};
int score{};
int num{};
int map[10][4][2];

vector<pair<int, pair<int, int>>> v;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };


void Setting_Block(int Shape, int x, int y){
    if (Shape == 1){
        int B_Idx = y + 1;
        while (B_Idx < 10 && map[B_Idx][x][0] == 0) B_Idx++; B_Idx--;
        map[B_Idx][x][0] = num;

        int G_Idx = x + 1;
        while (G_Idx < 10 && map[G_Idx][y][1] == 0) G_Idx++; G_Idx--;
        map[G_Idx][y][1] = num++;

        bCnt += 2;
    }
    else if (Shape == 2){
        int B_Idx = y + 2;
        while (B_Idx < 10 && map[B_Idx][x][0] == 0) B_Idx++; B_Idx--;
        map[B_Idx][x][0] = num;
        map[B_Idx - 1][x][0] = num;

        int G_Idx = x + 1;
        while (G_Idx < 10 && map[G_Idx][y][1] == 0 && map[G_Idx][y + 1][1] == 0) G_Idx++; G_Idx--;
        map[G_Idx][y][1] = num;
        map[G_Idx][y + 1][1] = num++;

        bCnt += 4;
    }
    else{
        int B_Idx = y + 1;
        while (B_Idx < 10 && map[B_Idx][x][0] == 0 && map[B_Idx][x + 1][0] == 0) B_Idx++; B_Idx--;
        map[B_Idx][x][0] = num;
        map[B_Idx][x + 1][0] = num;

        int G_Idx = x + 2;
        while (G_Idx < 10 && map[G_Idx][y][1] == 0) G_Idx++; G_Idx--;
        map[G_Idx][y][1] = num;
        map[G_Idx - 1][y][1] = num++;

        bCnt += 4;
    }
}

void Remove(int Idx, int Color){
    for (int i = 0; i < 4; i++){
        if (map[Idx][i][Color] == 0) continue;

        map[Idx][i][Color] = 0;
        bCnt--;
    }
}

pair<int, int> Find_Partner(int Idx, int Pos, int Color)
{
    if (Color == 0)
    {
        for (int i = 0; i < 4; i++)
        {
            int n_Idx = Idx + dx[i];
            int n_Pos = Pos + dy[i];

            if (n_Idx >= 4 && n_Idx < 10 && n_Pos >= 0 && n_Pos < 4){
                if (map[Idx][Pos][Color] == map[n_Idx][n_Pos][Color]){
                    if (Idx == n_Idx) return{ 3, i };
                    return{ 2, i };
                }
            }
        }
        return{ 1, -1 };
    }
    else {
        for (int i = 0; i < 4; i++) {
            for (int i = 0; i < 4; i++) {
                int n_Idx = Idx + dx[i];
                int n_Pos = Pos + dy[i];

                if (n_Idx >= 4 && n_Idx < 10 && n_Pos >= 0 && n_Pos < 4)
                {
                    if (map[Idx][Pos][Color] == map[n_Idx][n_Pos][Color])
                    {
                        if (Idx == n_Idx) return{ 2, i };
                        return{ 3, i };
                    }
                }
            }
            return{ 1, -1 };
        }
    }
}

void Move(int Index, int Color){
    if (Index == 3) return;

    int Idx = Index - 1;
    for (int i = 0; i < 4; i++){
        if (map[Idx][i][Color] == 0) continue;

        int Pos = i;
        int F_num = num[map][Idx][i];
        pair<int, int> Shape = Find_Partner(Idx, Pos, Color);

        if (Shape.first == 1){
            int n_Idx = Idx + 1;
            map[n_Idx][i][Color] = map[Idx][i][Color];
            map[Idx][i][Color] = 0;
        }
        else if (Shape.first == 2){
            int P_Idx = Idx + dx[Shape.second];
            int P_Pos = Pos + dy[Shape.second];
            if (Color == 0){
                int Standard_Idx = max(P_Idx, Idx);
                int Partner_Idx = min(P_Idx, Idx);
                int n_Idx = Standard_Idx + 1;
                int nP_Idx = Partner_Idx + 1;
                map[n_Idx][i][Color] = map[Standard_Idx][i][Color];
                map[nP_Idx][i][Color] = map[Partner_Idx][i][Color];
                map[Partner_Idx][i][Color] = 0;
            }
            else{
                int n_Idx = Idx + 1;
                int nP_Idx = P_Idx + 1;
                map[n_Idx][i][Color] = map[Idx][i][Color];
                map[nP_Idx][i][Color] = map[P_Idx][i][Color];
                map[Idx][i][Color] = 0;
                map[P_Idx][i][Color] = 0;
            }
        }
        else{
            int P_Idx = Idx + dx[Shape.second];
            int P_Pos = Pos + dy[Shape.second];
            if (Color == 0){
                int n_Idx = Idx + 1;
                int nP_Idx = P_Idx + 1;
                map[n_Idx][i][Color] = map[Idx][i][Color];
                map[nP_Idx][i][Color] = map[P_Idx][i][Color];
                map[Idx][i][Color] = 0;
                map[P_Idx][i][Color] = 0;
            }
            else{
                int Standard_Idx = max(Idx, P_Idx);
                int Partner_Idx = min(Idx, P_Idx);
                int n_Idx = Standard_Idx + 1;
                int nP_Idx = Partner_Idx + 1;
                map[n_Idx][i][Color] = map[Standard_Idx][i][Color];
                map[nP_Idx][i][Color] = map[Partner_Idx][i][Color];
                map[Partner_Idx][i][Color] = 0;
            }
        }
    }
    Move(Index - 1, Color);
}

void Remove_Full_Block(){
    bool flag = false;
    for (int Color = 0; Color < 2; Color++){
        for (int i = 4; i < 10; i++){
            int cnt = 0;
            for (int j = 0; j < 4; j++){
                if (map[i][j][Color] == 0) break;
                cnt++;
            }

            if (cnt == 4){
                flag = true;
                score++;
                Remove(i, Color);
                Move(i, Color);
            }
        }
    }
    if (flag == true) Remove_Full_Block();
}

void Check_Special_Point(){
    for (int Color = 0; Color < 2; Color++){
        int cnt = 0;
        for (int i = 4; i < 6; i++){
            for (int j = 0; j < 4; j++){
                if (map[i][j][Color] == 0) continue;
                cnt++;
                break;
            }
        }

        for (int i = 0; i < cnt; i++){
            Remove(9, Color);
            Move(9, Color);
        }
    }
}

int main(){
    //input
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(make_pair(a, make_pair(b, c)));
    }
    //init
    num = 1;
    //logic
    for (int i = 0; i < v.size(); i++) {
        int t = v[i].first;
        int x = v[i].second.first;
        int y = v[i].second.second;

        Setting_Block(t, x, y);
        Remove_Full_Block();
        Check_Special_Point();
    }

    //result
    cout << score << "\n" << bCnt << "\n";
    return 0;
}