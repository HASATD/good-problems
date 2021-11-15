#include <bits/stdc++.h>
using namespace std;
long long int maxi = 1e9 + 7;
int main()
{
    int n;
    cin >> n;

    long long int a[1000001];
    a[0] = 1;
    a[1] = 1;

    for (int i = 2; i <= n; i++)
    {    a[i] = 0;
        for (int j = 1; j <= 6 && j <= i; j++)
        {

            a[i] = (a[i]%maxi + a[i - j]%maxi)%maxi;
        }
    }
    cout << a[n] % maxi << endl;
}