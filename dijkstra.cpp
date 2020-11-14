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
#define Fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define f(i, n) for (long long int i = 0; i < n; i++)
#define ll long long int
#define fo(i, a, b) for (long long int i = a; i <= b; i++)
#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)
#define vi vector<int>
#define vl vector<long long int>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long int>>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define newl cout<<"\n"
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll inf = 1e15 + 7;
const ll modc = 998244353;
#define MAX 100002


int main(){
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>>G(n+1);
    f(i,m){
        ll u,v,w;
        cin>>u>>v>>w;
        G[u].pb(mp(v,w));
        G[v].pb(mp(u,w));
    }
    vl D(n+1,inf);
    D[1]=0;
    set<pair<ll,ll>>Q;
    Q.insert(mp(0,1));
    ll P[n+1];
    while(!Q.empty()){
        auto top = Q.begin();
        ll u = top->se;
        Q.erase(top);
        for(auto next: G[u]){
            ll v = next.fi;
            ll w = next.se;
            if(D[v]>D[u]+w){
                if(Q.find(mp(D[v],v))!=Q.end())Q.erase(Q.find(mp(D[v],v)));
                D[v] = D[u]+w;
                P[v] = u;
                Q.insert(mp(D[v],v));
            }
        }
    }
    vl Path;
    for(ll i = n;i!=1;i=P[i])Path.pb(i);
    Path.pb(1);
    reverse(Path.begin(),Path.end());
    for(auto x: Path)cout<<x<<" ";
}