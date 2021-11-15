#include<bits/stdc++.h>
using namespace std;  
const int mod = 1e9 + 7;

int main(){
     int n;
    cin >> n;
    int k = (n*(n+1))/2;
    if(k%2 != 0){
        cout << 0 << endl;
          return 0;
    }
    k = k/2;


     vector<vector<int>> dp(n+1,vector<int>(k+1,0));
     
     for(int i=0;i<=n;i++){
         dp[i][0] =1;
     }
     for(int i=1;i<=n;i++){
         for(int j=1;j<=k;j++){
             dp[i][j] = dp[i-1][j]%mod;
             if(j>=i)dp[i][j] = (dp[i][j]%mod+dp[i-1][j-i]%mod);
         }
     }
     cout << (dp[n][k]/2)%mod<< endl;
}
