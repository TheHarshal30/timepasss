#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
vector<int> vis(N,0);
vector<int> adj[N];

void dfs(int node){
    vis[node] = 1;
    cout << node << endl;

    for(int it: adj[node]){
        if(!vis[it]){
            vis[it] = 1;
            dfs(it);
        }
    }
}

int main(){
    int n,m;
    cout << "Enter number of edges and vertices: ";
    cin >> n >> m;
    cout << "Enter edges: " << endl;
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    } 

    dfs(1);

    return 0;
}