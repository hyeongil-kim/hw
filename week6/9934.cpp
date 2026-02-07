// ÇüÀÏ
#include <iostream>
#include <vector>
using namespace std;

vector<int>v;
vector<int>v2[10];
int t = 0;
void postOrder(int left, int right, int depth)
{
    if (left > right) return;
    int mid = (left + right) / 2;
    int root = v[mid];
    v2[depth].push_back(root);
    postOrder(left, mid - 1, depth + 1);
    postOrder(mid + 1, right, depth + 1);

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num;
    int k;
    cin >> k;
    while (cin >> num)
    {
        v.push_back(num);
    }
    postOrder(0, v.size() - 1, 0);
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < v2[i].size(); j++)
        {
            cout << v2[i][j] << " ";
        }
        cout << '\n';
    }
}
