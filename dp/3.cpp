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
    int dp[1000001] = {0};
    dp[0] = 1;
    //sort(c,c+n);
    
    for(int i=1;i<=x;i++){

        for(int j=0;j<n;j++){
            if(i-c[j]>=0){
            dp[i]=(dp[i]+dp[i-c[j]])%maxi;}
        }
    }

    cout<<dp[x]%maxi << endl;
}