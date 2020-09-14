#include <iostream>
#include <list>

using namespace std;

class Graph {
    int V;
    list<int> * adj;
public:
    Graph(int V);
    void addEdge(int u, int v);
    void BFS(int s);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::BFS(int s) {
    char u[V];
    for (int i = 0; i < V; ++i) {
        u[i] = false;
    }
    list<int>::iterator i;
    list<int> queue;
    u[s] = true;
    queue.push_back(s);
    while (!queue.empty()) {
        s = queue.front();
        cout << s << endl;
        queue.pop_front();

        for (i = adj[s].begin(); i != adj[s].end(); ++i) {
            if (!u[*i]) {
                queue.push_back(*i);
                u[*i] = true;
            }
        }
    }
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "BFS traversal starting from vertex 2\n";
    g.BFS(2);
}