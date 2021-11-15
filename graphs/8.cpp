#include <bits/stdc++.h>
using namespace std;
#define MAXN 202020
vector<vector<pair<int, int>>> adj(MAXN);

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v, u, w;
        cin >> v >> u >> w;
        adj[v].push_back({u, w});
    }
    long long int d[n + 1];

    memset(d, 0x3f, sizeof(d));
    d[1] = 0;

    using pii = pair<long long int,int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, 1});
    while (!q.empty())
    {

        int min = q.top().second;
        long long int d_v = q.top().first;
        q.pop();
        if (d_v != d[min])
            continue;

        for (auto u : adj[min])
        {
            int x = u.first;
            long long int y = u.second;

            if (d[min] + y < d[x])
            {

                d[x] = d[min] + y;
                q.push({d[x], x});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << d[i] << " ";
    }
}