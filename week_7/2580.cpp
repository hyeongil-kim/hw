#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[9][9];
int num = 0;
bool visited = false;
vector<pair<int, int>> v;
bool check(int a, int b, int n)
{
    for (int i = 0; i < 9; i++)
    {
        if (arr[i][b] == n)
            return false;
        if (arr[a][i] == n)
            return false;
    }

    int x = a / 3;
    int y = b / 3;
    x *= 3;
    y *= 3;
    for (int i = x; i < x + 3; i++)
    {
        for (int j = y; j < y + 3; j++)
        {
            if (arr[i][j] == n)
                return false;
        }
    }
    return true;
}

void sudoku(int n)
{
    if (visited == true) return;

    if (n == num)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << arr[i][j] << ' ';
            }
            cout << '\n';
        }
        visited = true;
    }
    else
    {
        int x = v[n].first;
        int y = v[n].second;

        for (int i = 1; i <= 9; i++)
        {
            if (check(x, y, i))
            {
                arr[x][y] = i;
                sudoku(n + 1);
                arr[x][y] = 0;
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);



    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 0)
            {
                v.push_back({ i,j });
            }
        }
    }
    num = v.size();
    sudoku(0);
}
