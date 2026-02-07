#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v[2001];
bool visited[2001];
bool check = false;

void fri(int n, int depth)
{
    if (depth >= 4)
    {
        check = true;
        return;
    }
    for (int i = 0; i < v[n].size(); i++)
    {
        int y = v[n][i];

        if (!visited[y])
        {
            visited[y] = true;
            fri(y, depth + 1);
            visited[y] = false;

            if (check)
                return;
        }

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        visited[i] = true;
        fri(i, 0);
        visited[i] = false;
        if (check)
            break;
    }
    cout << check;
}
