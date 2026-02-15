#include <iostream>
#include <queue>
#include<algorithm>
using namespace std;

int n, k;
int e[100001];
bool visited[100001];

int bfs(int start)
{
    queue<int> q;
    q.push(start);

    while (q.size())
    {
        int x = q.front();
        q.pop();
        visited[x] = true;

        if (x == k)
        {
            return e[x];
        }

        int next[3] = { x + 1,x - 1,x * 2 };
        for (int i = 2; i >= 0; i--)
        {
            int nx = next[i];
            if (nx < 0 || nx>100000)continue;
            if (visited[nx])continue;

            visited[nx] = true;
            if (i != 2)
            {
                e[nx] = e[x]+1;
            }
            else
            {
                e[nx] = e[x];
            }
            q.push(nx);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    e[n] = 0;
    cout<<bfs(n);
}
