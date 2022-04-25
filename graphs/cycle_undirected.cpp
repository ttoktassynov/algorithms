#include <iostream>
#include <vector>
using namespace std;

bool hascycle(int s, int parent, const vector<vector<int> >& g, vector<int>& vis) {
    vis[s] = 1;
    for (const auto neigh: g[s]) {
        if (!vis[neigh]) {
            return hascycle(neigh, s, g, vis);
        }
        else if (neigh != parent){
            return true;
        }
    }
    return false;
}
int main() {
    vector<vector<int> > g = {{1,2}, {0, 1, 2}, {1, 0}};
    vector<int> vis(g.size());
    cout << hascycle(0, -1, g, vis) << endl;
}