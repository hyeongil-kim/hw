#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int M, N;
int arr[1001][1001];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int Max = 0;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    queue<pair<int, int>> q;

    cin >> M >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
            {
                q.push({ j,i });
            }
        }
    }

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N)
                continue;
            if (arr[ny][nx] != 0)
                continue;

            arr[ny][nx] = arr[y][x] + 1;
            q.push({ nx,ny });
        }
   }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 0)
            {
                cout << -1;
                return 0;
            }
            Max = max(Max, arr[i][j]);
        }
    }
    cout << Max - 1;
}
