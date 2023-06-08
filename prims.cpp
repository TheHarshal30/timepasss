#include<bits/stdc++.h>
using namespace std;

int main(){
    int N=5, M=6;
    vector<pair<int,int>> adj[N];
    adj[0].push_back({1,2});
	adj[0].push_back({3,6});
	adj[1].push_back({0,2});
	adj[1].push_back({2,3});
	adj[1].push_back({3,8});
	adj[1].push_back({4,5});
	adj[2].push_back({1,3});
	adj[2].push_back({4,7});
	adj[3].push_back({0,6});
	adj[3].push_back({1,8});
	adj[4].push_back({1,5});
	adj[4].push_back({2,7});
    int parent[N];
    int key[N];
    bool mst[N];
    for(int i=0;i<N;i++){
        key[i] = INT_MAX;
        mst[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for(int i=0;i<N-1;i++){
        int mini = INT_MAX, u;
        for(int v=0;v<N;v++){
            if(mst[v] == false and key[v]< mini){
                mini = key[v];
                u = v;
            }
        }
        mst[u] = true;
        for(auto it: adj[u]){
            int v = it.first;
            int w = it.second;
            if(mst[v] == false and w<key[v]){
                parent[v] = u;
                key[v] = w;
            }
        }
    }
    for(int i=1;i<N;i++){
        cout<< parent[i] << " " << i << " " << key[i] << endl; 
    }
    return 0;
}