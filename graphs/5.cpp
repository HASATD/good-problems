#include<bits/stdc++.h>
using namespace std;
#define MAXN 202020
vector<vector<int>> adj(MAXN);
void dfs(int v,bool *visit,int *color,int c){

visit[v] = true;
color[v] = c;
for(int u:adj[v]){
    if(!visit[u]){
        
        dfs(u,visit,color,1-c);}
    
}


}
int main(){
    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<m;i++){
        int v,u;
        cin >> v>> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    bool visited[n+1];
    int color[n+1];

   for(int i=1;i<=n;i++){visited[i]=false;color[i]=0;}

   for(int i=1;i<=n;i++){
       if(!visited[i]){
                    dfs(i,visited,color,0);
       }
   }
  
  for(int i=1;i<=n;i++){
      for(int u:adj[i]){
          if(color[i]==color[u]){
              cout << "IMPOSSIBLE";
              return 0;
          }

      }
  }
  for(int i=1;i<=n;i++){
      cout<<color[i]+1<<" ";
  }

}