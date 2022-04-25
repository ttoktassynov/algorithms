#include <iostream>
#include <vector>

using namespace std;
using Graph = vector<vector<int> >;
enum Color {
    WHITE,
    GREY,
    BLACK
};
/*
 g = {{1, 2}, {3}, {3}, {}};
 colors = [ 1 1 0 2 ]
 dfs(0)
    dfs(1) false
        dfs(3) false
    dfs(2) 

*/
bool dfs(int start, const Graph& g, vector<Color>& colors) {
    colors[start] = Color::GREY;
    for (const auto neigh: g[start]) {
        if (colors[neigh] != Color::GREY) {
            bool cycle = dfs(neigh, g, colors);
            if (cycle) {
                return false;
            }
        }
        else {
            return true;
        }
    }
    colors[start] = Color::BLACK;
    return false;
}
int main() {
    Graph g = {{1, 2}, {3}, {3}, {}};
    const int SIZE = 4;
    vector<Color> colors(SIZE);
    cout << dfs(0, g, colors) << endl;
}