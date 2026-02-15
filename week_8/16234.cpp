#include <iostream>
#include <queue>
#include<algorithm>

using namespace std;


int N, L, R;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int arr[51][51];


bool bfs(int x, int y, bool visited[51][51])
{
    queue<pair<int, int>>q;
    q.push({x,y});
    vector < pair<int, int>>pos;
    pos.push_back({ x,y });
    int sum = arr[y][x];
    visited[y][x] = true;
    while (!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = a + dx[i];
            int ny = b + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            int diff = abs(arr[b][a]-arr[ny][nx]);
            if (diff<L || diff>R)
                continue;
            if (visited[ny][nx])
                continue;
            
            q.push({ nx,ny });
            visited[ny][nx] = true;

            pos.push_back({ nx,ny });
            sum += arr[ny][nx];
        }
    }
    if (pos.size() == 1)
        return false;
    sum /= (int)pos.size();
    for (int i = 0; i < (int)pos.size(); i++)
    {
        int px = pos[i].first;
        int py = pos[i].second;
        arr[py][px] = sum;
    }
    return true;
}
bool mov()
{
    bool visit[51][51];
    bool check = false;
    for (int i = 0; i < 51; i++)
    {
        for (int j = 0; j < 51; j++)
        {
            visit[i][j] = false;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visit[i][j])
                continue;
            if (bfs(j, i, visit))
            {
                check = true;
            }
        }
    }
    return check;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> L >> R;
    int day = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }
    while (1)
    {
        if (!mov())
            break;
        day++;
    }
    cout << day;

}
