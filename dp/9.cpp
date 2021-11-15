#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main(){
     
     int dp[1000002][2];
     dp[1000001][0]=dp[1000001][1] = 1;

     for(int i=1000000;i>=2;i--){
          
          dp[i][0] = ((dp[i+1][0]+dp[i+1][0])%mod + dp[i+1][1])%mod;
          dp[i][1] = (((dp[i+1][1] + dp[i+1][0])%mod + dp[i+1][1])%mod + (2*dp[i+1][1])%mod)%mod;

     }
int t;
cin >> t;
while(t--){
    int q;
    cin >> q;
    cout << (dp[1000000-q+2][0] + dp[1000000-q+2][1])%mod << endl;
}




}