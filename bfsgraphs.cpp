#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+2;
const int M = 3;
vector<int> adj[N];
vector<int> vis(N, 0);

int main (){
    int n ,m;
    cout << "Enter number of edges and vertices: " ;
    cin >> n >> m;
    for(int i=0;i<n;i++){
    }
    cout << "Enter edges : " << endl;
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue<int> q;
    q.push(1);
    vis[1] = 1;

    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout << x << endl;
        for(int it: adj[x]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }

}