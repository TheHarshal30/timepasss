#include<bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    vector<list<int>> adj;
    public:
    Graph(int val){
        this->v = val;
        adj.resize(v);
    }
    void addEdge(int v, int w){
        adj[v].push_back(w);
    }

    void BFS(int s){
        vector<bool> visited;
        visited.resize(v, false);
        list<int> queue;
        visited[s] = true;
        queue.push_back(s);
        while(!queue.empty()){
            s = queue.front();
            cout << s << " ";
            queue.pop_front();

            for(auto adjacent: adj[s]){
                if(!visited[adjacent]){
                    visited[adjacent] = true;
                    queue.push_back(adjacent);
                }
            }
        }
    }
    void DFS(int s){
        vector<bool> visited;
        visited.resize(v,false);
        stack<int> st;
        st.push(s);
        while(!st.empty()){
            s = st.top();
            st.pop();
            if(!visited[s]) {
                cout << s << " ";
                visited[s] = true;
            }

            for(auto temp: adj[s]){
                if(!visited[temp]) st.push(temp);
            }
        }
    }
};

int main(){
      Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
    cout << endl;
    g.DFS(2); 
    return 0;
}