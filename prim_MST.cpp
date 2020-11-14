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
#define inf int(1e9+7)

struct edge{
    int u,v,w;
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<edge> E;
    for(int i = 0;i < m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edge e1 = {u,v,w};
        edge e2 = {v,u,w};
        E.push_back(e1),E.push_back(e2);
    }
    vector<bool> selected(n+1,false);
    selected[1] = true;
    vector<edge>MST;
    int min_edge_weight_sum = 0;
    for(int i = 0;i<n-1;i++){
        edge min_edge = {-1,-1,inf};
        for(edge e: E){
            if(selected[e.u] && !selected[e.v] && e.w < min_edge.w)min_edge = e;
        }
        min_edge_weight_sum += min_edge.w;
        MST.push_back(min_edge);
        selected[min_edge.v] = true;
    }
    cout<<"min edge weight sum ---->>>> "<<min_edge_weight_sum<<"\n";
    for(edge e: MST)cout<<e.u<<" "<<e.v<<" "<<e.w<<"\n";
}

