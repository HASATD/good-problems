#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
char step[1000][1000];
int da[1000][1000];
char ans[1000000];
void print(int x, int y)
{

    cout << "YES" << endl
         << da[x][y] << endl;

    for (int i = da[x][y]; i > 0; i--)
    {
        ans[i] = step[x][y];
        if (ans[i] == 'D')
            x--;
        else if (ans[i] == 'U')
            x++;
        else if (ans[i] == 'R')
            y--;
        else if (ans[i] == 'L')
            y++;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    char c[n][m];
    queue<pair<int, int>> q;
    bool visit[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visit[i][j] = false;
        }
    }
    int ax, ay;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c[i][j];
            if (c[i][j] == '#')
                visit[i][j] = true;
            else if (c[i][j] == 'M')
            {
                visit[i][j] = true;
                q.push({i, j});
            }
            else if (c[i][j] == 'A')
            {
                ax = i;
                 ay = j;
            }
        }
    }
    //cout<<ax<<" "<<ay<<endl;

    int d[1000][1000];
    int di[] = {1, -1, 0, 0};
    int dj[] = {0, 0, 1, -1};
    while (!q.empty())
    {    
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            if (!visit[x + di[k]][y + dj[k]] && x + di[k] < n && x + di[k] >= 0 && y + dj[k] < m && y + dj[k] >= 0)
            {     
                d[x + di[k]][y + dj[k]] = d[x][y] + 1;
                q.push({x + di[k], y + dj[k]});
                visit[x + di[k]][y + dj[k]] = true;
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visit[i][j])
                d[i][j] = INF;
            visit[i][j] = (c[i][j] == '#');
        }
    }
    
    

    q.push({ax, ay});
    visit[ax][ay] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int x1 = x + di[k], y1 = y + dj[k];

            if (!visit[x1][y1] && x1 < n && x1 >= 0 && y1 < m && y1 >= 0 && da[x][y]+1 < d[x1][y1])
            {
                if (k == 0)
                    step[x1][y1] = 'D';
                else if (k == 1)
                    step[x1][y1] = 'U';
                else if (k == 2)
                    step[x1][y1] = 'R';
                else if (k == 3)
                    step[x1][y1] = 'L';
                da[x1][y1] = da[x][y] + 1;
                visit[x1][y1] = true;
                q.push({x1, y1});
            }
        }
    }
    

    for (int i = 0; i < n; i++)
    {
        if (c[i][0] != '#' && c[i][0] != 'M' && visit[i][0] )
        {
            print(i, 0);
            for (int j = 1; j <= da[i][0]; j++)
            {
                cout << ans[j];
            }
             cout<<endl;
            return 0;
        }
        else if (c[i][m - 1] != '#' && c[i][m - 1] != 'M' && visit[i][m - 1] )
        {
            print(i, m - 1);
            for (int j = 1; j <= da[i][m - 1]; j++)
            {
                cout << ans[j];
            }
             cout<<endl;
            return 0;
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (c[0][i] != '#' && c[0][i] != 'M' && visit[0][i])
        {
            print(0, i);
            for (int j = 1; j <= da[0][i]; j++)
            {
                cout << ans[j];
            }
            cout<<endl;
            return 0;
        }
        else if (c[n - 1][i] != '#' && c[n - 1][i] != 'M' && visit[n - 1][i] )
        {
            print(n - 1, i);
            for (int j = 1; j <= da[n - 1][i]; j++)
            {
                cout << ans[j];
            }
            cout<<endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}