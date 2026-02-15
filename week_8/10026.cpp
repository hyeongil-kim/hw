#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int n;
char arr[101][101];
char arr_rg[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool visited[101][101];
bool visited_rg[101][101];


int bfs(int x, int y, bool visit[101][101], char ar[101][101])
{
    queue<pair<int, int>>q;
    q.push({ x,y });
    visit[x][y] = true;

    while (!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = a + dx[i];
            int ny = b + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (visit[nx][ny])
                continue;
            if (ar[a][b] != ar[nx][ny])
                continue;

            q.push({ nx,ny });
            visit[nx][ny] = true;


        }
    }
    return 0;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'G')
            {
                arr_rg[i][j] = 'R';
            }
            else
                arr_rg[i][j] = arr[i][j];
        }
    }
    int num = 0;
    int num_rg = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                bfs(i, j, visited, arr);
                num++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited_rg[i][j])
            {
                bfs(i, j, visited_rg, arr_rg);
                num_rg++;
            }
        }
    }
    cout << num << " " << num_rg;
}
