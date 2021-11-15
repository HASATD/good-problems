#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

int main(){
    int n,m;
    cin >> n >> m;
    int x[n+1];
    for(int i=1;i<=n;i++)cin >> x[i];

    int dp[n+1][m+1];

    memset(dp,0,sizeof(dp));

    for(int i=1;i<=m;i++){
        if(x[1]==0||x[1]==i) dp[1][i] = 1;
        else if (x[1]!=i)dp[1][i] = 0;
    }
    
    for(int i=2;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i]==0 || x[i]==j)dp[i][j] = ((dp[i-1][j-1] + dp[i-1][j])%mod + dp[i-1][j+1]%mod)%mod;
            else if(x[i]!=j)dp[i][j] = 0;        
        }
    }
    int ans = 0;
   for(int i=1;i<=m;i++){
        
        (ans+=dp[n][i])%=mod;

   }
   cout << ans <<endl;


}