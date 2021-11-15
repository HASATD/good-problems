#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int x[n+1];

   for(int i=1;i<=n;i++)cin >> x[i];

   int dp[n+1][100001];
    
    memset(dp,0,sizeof(dp));
    
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }
     int count = 0;
     bool visit[100001] = {false};
     
     queue<int> q;
        
        for(int j=1;j<=100000;j++){
        for(int i=1;i<=n;i++){
            dp[i][j] = dp[i-1][j];
            if(j>=x[i])dp[i][j]+=dp[i-1][j-x[i]];
            if(dp[i][j]>=1 && !visit[j]){
                visit[j] = true;
                count++;       
                q.push(j);
            }
                    }
    
        }
        
cout << count<<endl;
while(!q.empty()){
    cout << q.front()<<" ";
    q.pop();
}
cout << endl;

}