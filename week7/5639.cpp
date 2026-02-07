// ÇüÀÏ
#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
void postOrder(int left, int right)
{
    if (left > right)
        return;
    int root = v[left];
    int idx = left + 1;

    while (idx <= right && v[idx] < root)
    {
        idx++;
    }

    postOrder(left + 1, idx - 1);
    postOrder(idx, right);
    cout << v[left] << '\n';

}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int num;
    while (cin >> num)
    {
        v.push_back(num);
    }

    postOrder(0, v.size() - 1);

}
