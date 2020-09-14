#include <iostream>
#include <vector>

using namespace std;

enum Color {WHITE, GREY, BLACK};

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

bool hasCycleUtil(vector<int> adj[], int i, int color[]) {
    color[i] = GREY;
    for (const auto u : adj[i]) {
        if (color[u] == GREY)
            return true;
        if (color[u] == WHITE && hasCycleUtil(adj, u, color))
            return true;
        
    }

    color[i] = BLACK;
    return false;
}
bool hasCycle(vector<int> adj[], int V) {
    int * color = new int[V];
    for (int i = 0; i < V; ++i)
        color[i] = WHITE;

    for (int i = 0; i < V; ++i) {
        if (color[i] == WHITE)
            if (hasCycleUtil(adj, i, color))
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