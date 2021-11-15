#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,m,q;
    cin >> n>> m >> q;
    long long int d[501][501];
     memset(d, 0x3f, sizeof(d));
    for(int i=0;i<m;i++){
        int u,v;
        long long int w;
        cin >> u >> v >> w;
        d[u][v] = min(d[u][v],w);
        d[v][u] = min(d[v][u],w);
    }
     for(int i=1;i<=n;i++)d[i][i] = 0;  
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
                                
            }
        }
    }
    pair<int,int> p[q];
    for(int i=0;i<q;i++){
        int u,v;
        cin >> u >> v;
        p[i].first = u;
        p[i].second = v;
    }
    for(int i=0;i<q;i++){
        if(d[p[i].first][p[i].second] < d[0][0])
        cout<< d[p[i].first][p[i].second] << endl;
        else cout << -1<<endl;
    }
   

    cout<<endl;
    

    
}