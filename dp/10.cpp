#include <bits/stdc++.h>
using namespace std;
string s1;
  string s2;
int fn(int i,int j){
    if(s1[i-1]==s2[j-1]) return 0;
    else return 1;
}

int main()
{
    
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    int dp[n+1][m + 1];
    for(int i=0;i<=n;i++){
        dp[i][0] = i;
    }
    for(int j=0;j<=m;j++){
        dp[0][j] = j;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = min(min(1+dp[i-1][j],1+dp[i][j-1]),dp[i-1][j-1]+fn(i,j));

        }
    }
    
    cout << dp[n][m] << endl;

}