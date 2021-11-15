#include <bits/stdc++.h>
using namespace std;
#define MAX 202020

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(MAX);
    for (int i = 0; i < m; i++)
    {
        int v, u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    bool visited[n + 1];
    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
    }

    vector<int> p(n + 1);
    vector<int> d(n + 1);

    if (!visited[1])
    {
        queue<int> q;
        q.push(1);
        p[1] = -1;
        visited[1] = true;

        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (int u : adj[v])
            {
                if (!visited[u])
                {
                    visited[u] = true;
                    q.push(u);
                    p[u] = v;
                    d[u] = d[v] + 1;
                }
            }
        }

        if (visited[n] != true)
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        cout << d[n] + 1 << endl;

        vector<int> path;
        for (int v = n; v != -1; v = p[v])
        {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
        for (int v : path)
        {
            cout << v << " ";
        }
    }
}