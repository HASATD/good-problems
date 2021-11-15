#include<bits/stdc++.h>
using namespace std;
const int maxi = 1e9+7;
int main(){
    int n;
    cin >> n;
    
    bool visit[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c;
                    cin >> c;  
        if(c=='*')visit[i][j]=0;
        else visit[i][j] = 1;
          }}
          
          if(!visit[0][0] || !visit[n-1][n-1]){
              cout<<0<<endl;
              return 0;
          }
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            
            if(visit[i-1][j] && i>=1){
                (dp[i][j]+=dp[i-1][j])%=maxi;
            }
            if(visit[i][j-1] && j>=1){
                (dp[i][j]+=dp[i][j-1])%=maxi;
            }

        }
    }
    
    cout<<dp[n-1][n-1]<<endl;
    


}