#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, T, P, answer = -1;
vector<pair<int, int>> info;

void search(int day, int cost)
{
    if (day > N)
    {
        return;
    }
    answer = max(answer, cost);

    for (int i = day; i < info.size(); i++)
    {
        search(i + info[i].first, cost + info[i].second);
    }
}

int main()
{
    cin >> N;
    int a, b; // 날짜, 비용

    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        info.push_back(make_pair(a, b));
    }
    search(0, 0);
    cout << answer;
    return 0;
}