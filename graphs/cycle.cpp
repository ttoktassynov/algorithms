#include <iostream>
#include <vector>

using namespace std;
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

bool hasCycleUtil(vector<int> adj[], int i, vector<bool>& visited, vector<bool>& recStack) {
    if (!visited[i]){
        visited[i] = true;
        recStack[i] = true;
        cout << i << " ";
        for (const auto u : adj[i]) {
            if (!visited[u] && hasCycleUtil(adj, u, visited, recStack))
                return true;
            else if (recStack[u])
                return true;
        }
    }
    recStack[i] = false;
    return false;
}
bool hasCycle(vector<int> adj[], int V) {
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);
    for (int i = 0; i < V; ++i) {
        if (hasCycleUtil(adj, i, visited, recStack))
            return true;
    }
    return false;
}
int main(){
    int V = 4;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 0);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 3);
    if (hasCycle(adj, V))
        cout << "The graph has cycles";
    else
        cout << "No cycles";

}