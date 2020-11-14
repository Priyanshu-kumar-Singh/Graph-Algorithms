#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;
#define MAX 10002
#define ll long long int
#define pb push_back
#define mp make_pair
#define inf 1e17+7

ll mini(ll a,ll b){
	if(a>=b)return b;
	return a;
}


int main(){
    ll n,m,u,v,w,q;
    cin>>n>>m>>q;
	ll G[n+1][n+1],dist[n+1][n+1];
	for(int i = 0;i<=n;i++){
		for(int j = 0;j<=n;j++){
			if(i==j)G[i][j] = 0;
			else G[i][j] = inf;
			dist[i][j] = G[i][j];
		}
	}
	for(int i = 0;i<m;i++){
		cin>>u>>v>>w;
		G[u][v] = mini(w,G[u][v]);
		G[v][u] = mini(w,G[v][u]);
		dist[u][v] = G[u][v];
		dist[v][u] = G[v][u];
	}

	for (int k = 1; k <= n; ++k) {
    	for (int i = 1; i <= n; ++i) {
    	    for (int j = 1; j <= n; ++j) {
    	        if (dist[i][k] < inf && dist[k][j] < inf)
    	            dist[i][j] = mini(dist[i][j], dist[i][k] + dist[k][j]); 
    	    }
    	}
	}
	ll a,b;
	while(q--){
		cin>>a>>b;
		if(dist[a][b]==inf)cout<<"-1\n";
		else cout<<dist[a][b]<<"\n";
	}
	
}