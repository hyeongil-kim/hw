#include <iostream>
#include <vector>
using namespace std;
vector<int> v[51];
int cut;
int bfs(int x)
{
    int count = 0;
    int leaf = 0;
    for (int next : v[x])
    {
        if (next == cut) {
            continue;
        }
        count++;
        leaf += bfs(next);
    }
    if (count == 0)
        return 1;
    return leaf;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int root;

    for (int i = 0; i < n; i++)
    {
        int t;

        cin >> t;
        if (t == -1)
        {
            root = i;
        }
        else
        {
            v[t].push_back(i);
        }
    }
    cin >> cut;
    if (cut == root)
    {
        cout << "0";
    }
    else
        cout << bfs(root);

}
