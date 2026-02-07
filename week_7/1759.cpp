#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<char> v;
int L, C;
string str;
void num(vector<char>v2, int n, int a, int b)
{
    str.push_back(v2[n]);
    if (v2[n] == 'a' || v2[n] == 'e' || v2[n] == 'i' ||
        v2[n] == 'o' || v2[n] == 'u')
    {
        a++;
    }
    else
        b++;

    if (str.length() == L && a > 0 && b > 1)
    {
        cout << str << '\n';

        return;
    }
    for (int t = n + 1; t < C; t++)
    {
        num(v2, t, a, b);
        str.pop_back();
    }


}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> L >> C;
    for (int i = 0; i < C; i++)
    {
        char t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i <= C - L; i++)
    {
        str = "";
        num(v, i, 0, 0);
    }

}

