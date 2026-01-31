// ÇüÀÏ
#include <iostream>
#include <vector>
#include<cstring>
using namespace std;

vector<int>v[100001];
int cnt[100001];
int dfs(int x, int c)
{
    cnt[x] = 1;
    for (int y : v[x])
    {
        if (y == c) continue;
        cnt[x] += dfs(y, x);
    }
    return cnt[x];
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, r, q;
    cin >> n >> r >> q;

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(r, 0);
    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        cout << cnt[t] << '\n';

    }

}