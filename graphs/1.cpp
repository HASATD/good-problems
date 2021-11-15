#include <bits/stdc++.h>
using namespace std;

int main()
{

    // we'll use bfs for searching
    int n, m;
    scanf("%d %d", &n, &m);
       char c;
    bool visit[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf(" %c", &c);
            visit[i][j] = (c=='#');
        }
    }
    queue<pair<int, int>> q;
    
    int di[] = {1, -1, 0, 0};
    int dj[] = {0, 0, 1, -1};
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visit[i][j])
            {
                q.push({i, j});
                visit[i][j] = true;

                while (!q.empty())
                {
                    int i1 = q.front().first;
                    int j1 = q.front().second;
                    q.pop();
                    
                        for (int k = 0; k < 4; k++)
                        {
                            if (i1+di[k]<n && i1+di[k]>=0 && j1 + dj[k]<m && j1 + dj[k] >= 0 && !visit[i1 + di[k]][j1 + dj[k]])
                            {
                                visit[i1 + di[k]][j1 + dj[k]] = true;
                                q.push({i1 + di[k], j1 + dj[k]});
                            }
                        }
                    
                }
                count++;
            }
        }
    }

    printf("%d\n", count);
}