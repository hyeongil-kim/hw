// ÇüÀÏ
#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
vector<int> graph[200001];
bool visited[200001];
int color = 0;

void dfs(int x, int c)
{

    if (v[x] != v[c])
    {
        color++;
    }
    visited[x] = true;
    for (int i = 0; i < graph[x].size(); i++)
    {
        int y = graph[x][i];

        if (!visited[y])
        {
            dfs(y, x);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    v.resize(n + 1);
    v[0] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> v[i];
    }

    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1, 0);
    cout << color;
}
