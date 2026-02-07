#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int Min = 1e9;
int Max = -1e9;
int arr[4];
vector<int> v;

void cal(int result, int p)
{
    if (p == n)
    {
        if (result > Max)
            Max = result;
        if (result < Min)
            Min = result;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (arr[i] > 0)
        {
            arr[i] -= 1;


            if (i == 0)
            {
                int new_r = result + v[p];
                cal(new_r, p + 1);
                arr[i] += 1;
            }

            else if (i == 1)
            {
                int new_r = result - v[p];
                cal(new_r, p + 1);
                arr[i] += 1;
            }
            else if (i == 2)
            {
                int new_r = result * v[p];
                cal(new_r, p + 1);
                arr[i] += 1;
            }
            else if (i == 3)
            {
                int new_r = result / v[p];
                cal(new_r, p + 1);
                arr[i] += 1;
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
    for (int i = 0; i < 4; i++) {
        cin >> arr[i];
    }


    cal(v[0], 1);
    cout << Max << '\n' << Min;
}
