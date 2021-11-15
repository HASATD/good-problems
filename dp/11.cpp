#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
const int INF = 0x3f3f3f3f;
int main(){
fast_io;
int a,b;
cin >> a >> b;

int dp[a+1][b+1];
memset(dp,0x3f,sizeof(dp));

for(int i=1;i<=a;i++){
    dp[i][1] = i-1;
}
for(int j=1;j<=b;j++){
    dp[1][j] = j-1;
}
for(int i=2;i<=a;i++){
    for(int j=2;j<=b;j++){
        if(i==j)dp[i][j] = 0;
        else {
           for(int k=1;k<max(a,b);k++){
               int x,y;
                x=INF;y=INF;
                if(i>k)x = 1+ dp[i-k][j] + dp[k][j];
                if(j>k) y = 1 + dp[i][j-k] + dp[i][k];
                dp[i][j] = min(min(x,y),dp[i][j]);
              
           } 
        }
    }
}


cout << dp[a][b] << endl;

}