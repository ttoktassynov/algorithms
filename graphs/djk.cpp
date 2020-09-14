#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
#define INF INT_MAX

void add_edge(vector<pair<int, int> > adj[], int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
}

vector<int> dijkstra(vector<pair<int, int> > adj [], int s, int V, int path[]) {
    vector<int> dist(V, INF);
    vector<char> used(V, false);

    dist[s] = 0;

    for (int i = 0; i < V; ++i) {
        int v = -1;

        for (int j = 0; j < V; ++j)
            if (!used[j] && (v == -1 || dist[j] < dist[i]))
                v = j;
        
        if (dist[v] == INF)
            break;
        used[v] = true;

        for (size_t k = 0; k < adj[v].size(); ++k){
            int to = adj[v][k].first;
            int len = adj[v][k].second;
            if (dist[v] + len < dist[to]) {
                dist[to] = dist[v] + len;
                path[to] = v;
            }
        }
    }
    return dist;
}

int main(){
    int V = 4;
    int s = 0;
    vector< pair<int, int> > adj[V];
    add_edge(adj, 0, 1, 1);
    add_edge(adj, 0, 2, 4);
    add_edge(adj, 1, 2, 2);
    add_edge(adj, 1, 3, 6);
    add_edge(adj, 2, 3, 3);
    int path [V];
    vector<int> dist = dijkstra(adj, s, V, path);

    int p = 2;

    vector<int> real_path;
    for (int i = p; i != s; i = path[i]) {
        real_path.push_back(i);
    }
    reverse(begin(real_path), end(real_path));

    for (size_t i = 0; i < real_path.size(); ++i) {
        cout << i << " ";
    }

}