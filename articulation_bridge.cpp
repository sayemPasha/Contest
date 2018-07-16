
#include<bits/stdc++.h>
using namespace std;
vector<int> discovery(1e4), visited(1e4),parent(1e4);
int  low[int(1e4)];
vector <int> adj[int(1e4)];

int ne, nv;

void dfs_ab(int u) //ab= articulation bridge
{
    //dbgA(visited, nv);
    static int dfsTime = 0;
    visited[u] = 1;
    discovery[u] = low[u] = ++dfsTime;

    for(int i=0; i<adj[u].size(); i++){
        int v = adj[u][i];
        if(!visited[v]){
            parent[v] = u;
            dfs_ab(v);
            low[u]  = min(low[u], low[v]);

            if(low[v] > discovery[u]){
                cout << u << " " << v << endl;
//If the lowest vertex reachable from subtree
// under v is  below u in DFS tree, then u-v
// is a bridge
            }
        }
        else if(v != parent[u]){
            low[u] = min(low[u], discovery[v]);
            //update low value of u for parent f.c.
        }
    }
}

inline bool read() {
	if(!(cin >> nv >> ne))
		return false;

	for(int i=0; i<ne; i++)
	{
	    int u,v;
	    cin >> u >> v;
	    adj[u].push_back(v);
	    adj[v].push_back(u);
	}

    return true;
}

inline void solve() {
	dfs_ab(0);
	cout << "solved" << endl;
	for(int i=0; i<nv; i++){
        cout << discovery[i] << " " << low[i] << endl;
	}


}

int main() {

	if(read()) {
		solve();
	}
	return 0;
}
