#include<bits/stdc++.h>
using namespace std;
const int maxi = 1e9+7;
int main(){
    int n,x;
    cin >> n >> x;
    int c[n];
    for(int i=0;i<n;i++){
        cin >> c[i];
    }
    int dp[n+1][x+1];
    memset(dp,0,sizeof(dp));
        dp[0][0] = 1;

    for(int i=1;i<n+1;i++){        
        for(int j=0;j<=x;j++){
            dp[i][j] = dp[i-1][j];
            if(j>=c[i-1])dp[i][j]=(dp[i][j]+dp[i][j-c[i-1]])%maxi;
        }
    }

    cout << dp[n][x] << endl;
}