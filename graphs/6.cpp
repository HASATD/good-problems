#include<bits/stdc++.h>
using namespace std;
#define MAXN 202020

int c_start;
int c_end;
int parent[MAXN];
vector<vector<int>> adj(MAXN);
bool dfs(int v,bool *visit,int par){

    visit[v] = true;
    for(int u:adj[v]){
        if(u==par)continue;
        if(visit[u]){
            c_start = u;
            c_end = v;
            return true;
        }
        parent[u] = v;
        if(dfs(u,visit,parent[u])){
            return true;
        };
    }
    return false;

}


int main(){
  int n,m;
  cin >> n>> m;
  
  
  for(int i=0;i<m;i++){
      int v,u;
      cin >> v>>u;
      adj[v].push_back(u);
      adj[u].push_back(v);
  }
  bool visited[n+1];
  
  
  for(int i=1;i<n+1;i++){
      visited[i]=false;
      parent[i] = -1;

  }
  c_start = -1;
  for(int i=1;i<n+1;i++){
    
     if(!visited[i] && dfs(i,visited,parent[i]))break;
    
  }
  if(c_start == -1){
      cout << "IMPOSSIBLE"<<endl;
      return 0;
  }
  vector<int> cycle;

  for(int v = c_end;v != c_start;v = parent[v]){
    cycle.push_back(v);
  }

  cycle.push_back(c_start);
  reverse(cycle.begin(),cycle.end());
  
  cout << cycle.size()+1<<endl;
  for(int v:cycle){
      cout<<v<<" ";
  }
  cout<<c_start;


  

}