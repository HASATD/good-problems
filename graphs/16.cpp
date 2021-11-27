int dfs(int p){
	
	vis[p]=1;
	int x;
	if(p==n){wt[p]=0;vis[p]=2;return 0;}
	for(int aa:graph[p]){
		
		 if(vis[aa]==-1){
			dfs(aa);
 
		}
		if(wt[aa]==-1)continue;
 
		if(wt[aa]+1>wt[p]){
			//cout<<p<<" "<<aa<<" "<<wt[aa]<<" "<<wt[p]<<" "; 
				wt[p]=wt[aa]+1;
				to[p]=aa;
			//	cout<<wt[p]<<endl;
			}
		
	}
 
 
	vis[p]=2;
	
	return wt[p];
}