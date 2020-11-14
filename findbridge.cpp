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

const int MAX = 1002;

vector<vector<int>>G(MAX);
bool vis[MAX] = {false};
vector<int> in,low;
int timer = 0;

void dfs(int x,int par){
    vis[x] = true;
    in[x] = low[x] = timer;
    timer++;
    for(auto child: G[x]){
        if(child == par)continue;
        if(vis[child])low[x] = min(low[x],in[child]); 
        if(!vis[child])dfs(child,x);
        low[x] = min(low[x],low[child]);
        if(low[child]>in[x])cout<<"Bridge b/w "<<x<<" -> "<<child<<"\n";
        // if low[child]<in[x] it means that child is connected to ancestor of x hence it cannot be a bridge
    }

}

int main(){
    int n,m;
    timer = 0;
    cin>>n>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }    
    in.assign(n,-1);
    low.assign(n,-1);//low stores what is the lowest ancestor which is reachable directly  from that node 
    for(int i=1;i<=n;i++){
        if(!vis[i])dfs(i,-1);
    }
}