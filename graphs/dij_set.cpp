#include <iostream>
#include <set>
#include <list>
#include <vector>

using namespace std;

#define INF INT_MAX

class Graph {
    int V;
    list<pair<int, int> > * adj;
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void getShortest(int s);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<pair<int, int> > [V];
}
void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
void Graph::getShortest(int s) {
    set<pair<int, int> > setds;
    vector<int> dist(V, INF);
    setds.insert(make_pair(0, s));
    dist[s] = 0;

    while (!setds.empty()) {
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());
        int u = tmp.second;
        list < pair<int,int> >::iterator i;
        for (i = adj[u].begin();i != adj[u].end(); ++i) {
            int v = (*i).first;
            int w = (*i).second;
            if (dist[v] > dist[u] + w) {
                if (dist[v] != INF)
                    setds.erase(setds.find(make_pair(dist[v], v)));
                dist[v] = dist[u] + w;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }
    for (int i = 0 ; i < V; ++i) {
        cout << dist[i] << " ";
    }
}
int main(){
    int V = 9;
    Graph g(V);
    g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7); 
  
    g.getShortest(0);
}