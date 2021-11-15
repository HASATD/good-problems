#include <bits/stdc++.h>
using namespace std;

int main()
{

    // we'll use bfs for searching
    int n, m;
    scanf("%d %d", &n, &m);
    char c;
    bool visit[n][m];
    int s[n][m];
    int ai,aj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf(" %c", &c);
            s[i][j] = c;
            visit[i][j] = (c == '#');
            if(s[i][j]=='B'){
                   ai = i;aj=j;
            }
        }
    }
    queue<pair<int, int>> q;
    pair<int,int> p[10000];

    int di[] = {1, -1, 0, 0};
    int dj[] = {0, 0, 1, -1};
    int count = 0;
    int dp[n][m];
    char ans[1000000];
    string ans1[n][m];
     char l[1000][1000];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visit[i][j])
            {
                if (s[i][j] == 'A')
                {
                    q.push({i, j});
                    visit[i][j] = true;
                    dp[i][j] = 0;
                   // ans1[i][j]="";
                    
                }

                while (!q.empty())
                {
                    int i1 = q.front().first;
                    int j1 = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++)
                    {
                        if (i1 + di[k] < n && i1 + di[k] >= 0 && j1 + dj[k] < m && j1 + dj[k] >= 0 && !visit[i1 + di[k]][j1 + dj[k]])
                        {

                            visit[i1 + di[k]][j1 + dj[k]] = true;
                            dp[di[k] + i1][dj[k] + j1] = dp[i1][j1] + 1;

                            int i2 = i1+di[k];
                            int j2 = j1 + dj[k];
                            
                            if (k == 0)
                                l[i2][j2] = 'D';
                            else if (k == 1)
                                l[i2][j2] = 'U';
                            else if (k == 2)
                                l[i2][j2] = 'R';
                            else if (k == 3)
                                l[i2][j2] = 'L';
                           // ans1[i2][j2]=ans1[i1][j1]+l[i2][j2];                           
                            q.push({i1 + di[k], j1 + dj[k]});
                        }
                    }
                }
            }
        }
    }
    if(visit[ai][aj]!=1)
    {cout<<"NO"<<endl;return 0;}
    
    cout <<"YES"<<endl<< dp[ai][aj] << endl;
    pair<int,int> P;
    P.first = ai;P.second =aj;
    
    for(int i=dp[ai][aj];i>0;i--){
          ans[i] = l[P.first][P.second];
          if(ans[i]=='D') P = {P.first-1,P.second};
          else if(ans[i]=='U') P = {P.first+1,P.second};
          else if(ans[i]=='R') P = {P.first,P.second-1};
          else if(ans[i]=='L') P = {P.first,P.second+1};
          
    }
    for(int i=1;i<=dp[ai][aj];i++){
        cout<<ans[i];
    }

   // cout<<ans1[ai][aj]<<endl;


}