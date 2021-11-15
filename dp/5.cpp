#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int dp[n+1];
    
    dp[0] = 0;

    for(int i=1;i<=9;i++)dp[i] = 1;
    int p;
    int maxi = -1;

    for(int i=10;i<n+1;i++){
    maxi = -1;p = i;
        while(p!=0){
            maxi = max(maxi,p%10);
            p = p/10;            
              }

        dp[i]=dp[i-maxi]+1;
       
    }

    cout << dp[n] << endl;
    
    
}