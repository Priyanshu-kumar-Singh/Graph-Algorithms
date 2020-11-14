


/*  TASK 2                   LABYRINTH ------------->>>>>>>>>>>>

Explanation :- simple BFS and path array


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
#define endl "\n"
using namespace std;
#define MAX 1005
 
int n,m;
string S[MAX];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char D[4] = {'L','R','U','D'};
pair<int,int> start,e;
pair<int,int> P[MAX][MAX];
int vis[MAX][MAX] = {0};
 
int valid(int x,int y){
	if(x>=n || y>=m ||x<0 || y<0 || S[x][y] == '#' || vis[x][y])return 0;
	return 1;
} 

void bfs(){
	P[start.first][start.second] = {-1,-1};
	queue<pair<int,int>>Q;
	Q.push(start);
	vis[start.first][start.second] = 1;
	while(!Q.empty()){
		auto q = Q.front();
		Q.pop();
		if(q == e)break;
		for(int i = 0;i<=3;i++){
			if(valid(q.first+dx[i],q.second+dy[i])){
				Q.push(make_pair(q.first+dx[i],q.second+dy[i]));
				vis[q.first+dx[i]][q.second+dy[i]]=1;
				P[q.first+dx[i]][q.second+dy[i]] = q;
			}
		}
	}
	if(vis[e.first][e.second]!=1){
		cout<<"NO";
		return;
	}
	cout<<"YES\n";
	string ans = "";
	pair<int,int> lst = {-1,-1};
	int cnt = 0;
	//cout<<P[1][2].first<<" "<<P[1][2].second<<"\n";
	for(int i = e.first,j = e.second; i!=-1 || j!= -1; tie(i,j) = P[i][j]){
		// cout<<i<<" "<<j<<" "<<P[i][j].first<<" "<<P[i][j].second<<" "<<lst.first<<" "<<lst.second<<"\n";
		// cnt++;
		// if(cnt == 11)break;
		if(lst == make_pair(-1,-1)){
			lst = {i,j};
			continue;
		}
		if (i-1 == lst.first && j == lst.second)ans = 'U'+ans;
        else if (i+1 == lst.first && j == lst.second)ans = 'D'+ans;
        else if (i == lst.first && j+1 == lst.second)ans = 'R'+ans;
        else if (i == lst.first && j-1 == lst.second)ans = 'L'+ans;
		lst = {i,j};
	}
	cout<<ans.length()<<"\n";
	cout<<ans;
}
 
int main(){
	cin>>n>>m;
	for(int i = 0;i<n;i++)cin>>S[i];
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(S[i][j] == 'A')start = {i,j};
			if(S[i][j] == 'B'){
				e = {i,j};
				break;
			}
		}
	}
	//cout<<start.first<<" "<<start.second<<"\n";
	bfs();
} 

*/







/*       TASk-3  Bulding roads
Explanation :- (simple finding no of connected comp)

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
#define endl "\n"
using namespace std;
#define MAX 200005
 
long long int  n,m,u,v;
vector<vector<long long int>> G(MAX);
int vis[MAX] = {0};

void dfs(long long int x){
	vis[x] = 1;
	for(auto y: G[x]){
		if(!vis[y])dfs(y);
	}
}

int main(){
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	long long int ans = 0;
	vector<pair<long long int,long long int>>A;
	for(int i = 1;i<=n;i++){
		if(!vis[i]){
			if(i!=1)
				A.push_back(make_pair(i-1,i));
			dfs(i);
		}
	}
	cout<<A.size()<<"\n";
	for(auto d: A)cout<<d.first<<" "<<d.second<<"\n";
	return 0;
}  

*/







/* Task -4           MESSAGE ROUTE--------->>>>>>>>>
Explanation:- simple Dijkstra algo to found shortest path between source and destination

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
        ll u,v;
        cin>>u>>v;
        G[u].pb(mp(v,1));
        G[v].pb(mp(u,1));
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
	if(D[n]==inf){
		cout<<"IMPOSSIBLE";
		return 0;
	}
	cout<<D[n]+1<<"\n";
    vl Path;
    for(ll i = n;i!=1;i=P[i])Path.pb(i);
    Path.pb(1);
    reverse(Path.begin(),Path.end());
    for(auto x: Path)cout<<x<<" ";
    return 0;
}

*/










/*                      Task -5 ----->>>>> Building teams 
explanation ---->>>>> simple dfs

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
#define MAX 200002

ll n,m;
vector<vector<ll>>G(MAX);
int vis[MAX]={0};
vector<ll> ans(MAX);

void dfs(ll node,ll c){
	vis[node] = 1;
	ans[node] = c;
	for(auto child: G[node]){
		if(!vis[child])dfs(child,3-c);
	}
}

int main(){
	cin>>n>>m;
	ll a,b;
	vector<pair<ll,ll>>A;
	for(int i = 0;i<m;i++){
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
		A.push_back(make_pair(a,b));
	}
	for(int i = 1;i<=n;i++){
		if(!vis[i])dfs(i,1);
	}
	for(auto x: A){
		if(ans[x.first]==ans[x.second]){
			cout<<"IMPOSSIBLE";
			return 0;
		}
	}
	for(int i = 1;i<=n;i++)cout<<ans[i]<<" ";
    return 0;
}
*/







/*                TASK - 6-----Round Trip
Explanation :- just find cycle in UNDIRECTED GRAPH

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
#define ll long long int
#define MAX 200002

ll n,m;
vector<vector<ll>>G(MAX);
int col[MAX]={0};
vector<ll> ans(MAX);
vector<ll> parent(MAX,0);
ll cycle_end,cycle_start;

void dfs(ll node,ll par){
	col[node] = 1;
	for(auto child: G[node]){
		if(child==par)continue;
		if(col[child]==0){
			parent[child] = node;
			dfs(child,node);
		}else if(col[child]==1){
			cycle_end = node;
			cycle_start = child;
		}
	}
	col[node]= 2;
}

int main(){
	cin>>n>>m;
	ll a,b;
	for(int i = 0;i<m;i++){
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	cycle_start = -1;
	for(ll i = 1;i<=n;i++){
		if(!col[i])dfs(i,parent[i]);
	}
	if(cycle_start==-1){
		cout<<"IMPOSSIBLE";
		return 0;
	}
	//cout<<cycle_start<<' '<<cycle_end<<"\n";
	vector<ll>cycle;
	for(ll v = cycle_end;v!=cycle_start;v=parent[v])cycle.push_back(v);
	cycle.push_back(cycle_start);
	reverse(cycle.begin(),cycle.end());
	cycle.push_back(cycle_start);
	cout<<cycle.size()<<"\n";
	for(auto x: cycle)cout<<x<<' ';
	return 0;
}






                            Task - 14 Round trip 2
    Explanation :- Find cycle in directed graph :-><


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
#define ll long long int
#define MAX 200002

ll n,m;
vector<vector<ll>>G(MAX);
int col[MAX]={0};
vector<ll> ans(MAX);
vector<ll> parent(MAX,0);
ll cycle_end,cycle_start;

void dfs(ll node,ll par){
	col[node] = 1;
	for(auto child: G[node]){
		//if(child==par)continue;
		if(col[child]==0){
			parent[child] = node;
			dfs(child,node);
		}else if(col[child]==1){
			cycle_end = node;
			cycle_start = child;
		}
	}
	col[node]= 2;
}

int main(){
	cin>>n>>m;
	ll a,b;
	for(int i = 0;i<m;i++){
		cin>>a>>b;
		G[a].push_back(b);
		//G[b].push_back(a);
	}
	cycle_start = -1;
	for(ll i = 1;i<=n;i++){
		if(!col[i])dfs(i,parent[i]);
	}
	if(cycle_start==-1){
		cout<<"IMPOSSIBLE";
		return 0;
	}
	//cout<<cycle_start<<' '<<cycle_end<<"\n";
	vector<ll>cycle;
	for(ll v = cycle_end;v!=cycle_start;v=parent[v])cycle.push_back(v);
	cycle.push_back(cycle_start);
	reverse(cycle.begin(),cycle.end());
	cycle.push_back(cycle_start);
	cout<<cycle.size()<<"\n";
	for(auto x: cycle)cout<<x<<' ';
	return 0;
}

*/




/*                     Task - 9 shortest routes -1
Explanation :- Simple Dijkstra(directed graph)

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

int main(){
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>>G(n+1);
    for(ll i = 0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        G[u].pb(mp(v,w));
        //G[v].pb(mp(u,w));
    }
    vector<ll> D(n+1,inf);
    D[1]=0;
    set<pair<ll,ll>>Q;
    Q.insert(mp(0,1));
    while(!Q.empty()){
        auto top = Q.begin();
        ll u = top->second;
        Q.erase(top);
        for(auto next: G[u]){
            ll v = next.first;
            ll w = next.second;
            if(D[v]>D[u]+w){
                if(Q.find(mp(D[v],v))!=Q.end())Q.erase(Q.find(mp(D[v],v)));
                D[v] = D[u]+w;
                Q.insert(mp(D[v],v));
            }
        }
    }
	for(int i = 1;i<=n;i++){
		cout<<D[i]<<" ";
	}
}


*/








/*                         Task - 10 Shortest route - 2
Explanation:- Floyd warshall algo to find all pairs shotest path

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

*/






/*        Task - 11  HIGH SCORE  
Explanation :- 



*/
