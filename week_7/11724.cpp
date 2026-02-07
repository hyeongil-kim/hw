#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int k;
string Min = "9999999999";
string Max = "0";

vector<char> v;
vector<int>iv;
bool check[10];
void back(string result, int idx)
{
    if (idx == k+1)
    {
        Max = max(Max, result);
        Min = min(Min, result);
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        if (check[i])continue;

        if (idx == 0 || (v[idx - 1] == '<' &&result[idx-1]-'0' < i) ||
            (v[idx - 1] == '>' && result[idx - 1] - '0' > i))
        {
            check[i] = true;
            back(result+char(i+'0'), idx + 1);
            check[i] = false;
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> k;
    for (int i = 0; i < k; i++)
    {
        char t;
        cin >> t;
        v.push_back(t);
    }
    for (int i = 0; i < 10; i++)
    {
        check[i] = true;
        back(string(1,char('0'+i)),1);
        check[i] = false;
    }
    cout << Max << '\n' << Min;

}
