#include<bits/stdc++.h>
using namespace std;
const int maxi = 1e9;
int main(){
    int n,x;
    cin >> n >> x;
    
    int c[n];
    for(int i=0;i<n;i++){
        cin >> c[i];
    }
vector<int> dp(x+1,maxi);
dp[0] = 0;
for(int i=1;i<=x;i++){
        
    for(int j=0;j<n;j++){
        if(i>=c[j]){
        if(dp[i]>dp[i-c[j]]+1)dp[i] = dp[i-c[j]]+1;}

    }

}

if(dp[x]==maxi)cout << -1 <<endl;
else cout << dp[x] << endl;



}