#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int x[n];
    for (int i = 0; i < n; i++)
        cin >> x[i];

    int dp[n];
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        int y = 0;
        for (int j = 0; j < i; j++)
        {

            if (x[j] < x[i])
                y = max(y, dp[j]);
        }

        dp[i] = 1 + y;
    }
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, dp[i]);
    }
    cout << maxi << endl;
}