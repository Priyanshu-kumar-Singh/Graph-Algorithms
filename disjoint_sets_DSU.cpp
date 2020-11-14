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

int parent[100];
int rank1[100];

void makeset()
{
    for(int i = 0;i<100;i++){
        parent[i] = i;
        rank1[i] = 0;
    }
}

int findset(int u)
{
    if(parent[u] == u)return u;
    // this is path optimisation we change parent of all 
	// vertices in between to leader.  ---------->>>>>>>>>>>this is called Path compression
    else return parent[u] = findset(parent[u]);
}

void unionset(int u,int v)
{
    v = findset(v);
    u = findset(u);

    if(u!=v)
    {
        if(rank1[u]>=rank1[v])
        {
            //if ranks are equal we differentiate leaders
		    //rank by incrementing it with one.
            if(rank1[u]==rank1[v])rank1[u]+=1;
            parent[v] = parent[u];
        }
        else 
            parent[u] = parent[v];
    }
    else 
        cout<<"BOTH ARE IN SAME GROUP\n";
}


int main()
{
    makeset();
    unionset(1,2);
    unionset(3,4);
    unionset(2,4);

    int leader1 = findset(4);
    cout<<"leader of group having 4 is "<<leader1<<endl;
    
    int leader2 = findset(3);
    cout<<"leader of group having 3 is "<<leader2<<endl;
    
    int leader3 = findset(2);
    cout<<"leader of group having 2 is "<<leader3<<endl;
    
    int leader4 = findset(1);
    cout<<"leader of group having 1 is "<<leader4<<endl;
}