#include <iostream>
#include <vector>

using namespace std;

void addEdge(vector<pair<int, int> > adj[], int u, int v, int wt) {
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

void DFSUtil(vector<pair<int, int> > adj[], int v, vector<bool>& visited){
    visited[v] = true;
    cout << v << " ";
    for (const auto& u : adj[v]){
        if (!visited[u.first]){
            DFSUtil(adj, u.first, visited);
        }
    }
}

void DFS(vector<pair<int, int> > adj[], int V){
    vector<bool> visited(V, false);
    for (int i = 0; i < V; ++i){
        if (!visited[i]){
            DFSUtil(adj, i, visited);
        }
    }
}

void printGraph(vector<pair<int, int> > adj[], int V) {
    for (int v = 0;  v < V; ++v){
        cout << "\nNode  " << v <<  " makes edge with:\n";
        for (auto it = adj[v].begin(); it != adj[v].end(); ++it){
            int u = it->first;
            int wt = it->second;
            cout << "\tNode " << u << " with weight " << wt << endl; 
        }
        cout << endl;
    }
}

int main(){
    int V = 5;
    vector<pair<int, int> > adj[V];
    addEdge(adj, 0, 1, 10); 
    addEdge(adj, 0, 4, 20); 
    addEdge(adj, 1, 2, 30); 
    addEdge(adj, 1, 3, 40); 
    addEdge(adj, 1, 4, 50); 
    addEdge(adj, 2, 3, 60); 
    addEdge(adj, 3, 4, 70);
    DFS(adj, V); 
    printGraph(adj, V);
}