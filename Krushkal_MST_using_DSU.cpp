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

struct edge
{
    int u,v,w;
};

vector<edge> E;
int par[100001];

bool cmp(edge a,edge b)
{
    return a.w < b.w;
}

int findset(int a){
    if(par[a] == a)return a;
    return par[a] = findset(par[a]);
}

void merge_union(int a,int b){
    par[a] = b;
}

int main(){
    int n,m,u,v,w;
    cin>>n>>m;
    for(int i = 0;i<=n;i++)par[i] = i;
    for(int i = 0;i<m;i++){
        cin>>u>>v>>w;
        edge e = {u,v,w};
        E.push_back(e);
    }
    sort(E.begin(),E.end(),cmp);
    int sum = 0;
    cout<<"MST -> \n";
    for(int i = 0;i<m;i++){
        int a = findset(E[i].u);
        int b = findset(E[i].v);

        if(a!=b){
            merge_union(a,b);
            cout<<a<<" "<<b<<"\n";
            sum += E[i].w;
        }
    }
    cout<<sum;

}