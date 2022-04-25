#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
    vector<int> components;
    vector<int> sizes;
    unordered_map<int, int> compMaxMap;
public:
    int root(int p) {
        int start = p;
        while(p != components[p]) {
            p = components[p];
        }
        while (star != components[start]) {
            components[start] = p;
        }
        return p;
    }
public:
    UnionFind(int n) : components(n), sizes(n){
        for (int i = 0; i < n; i++) {
            components[i] = i;
            sizes[i] = 1;
            compMaxMap[i] = i;
        }
    }
    void unionize(int p, int q) {
        int rootP = root(p);
        int rootQ = root(q);
        if (sizes[rootQ] > sizes[rootP]) {
            components[rootP] = rootQ;
            sizes[rootQ] += sizes[rootP];
            compMaxMap[rootQ] = max(compMaxMap[rootQ], compMaxMap[rootP]);
        }
        else {
            components[rootQ] = rootP;
            sizes[rootP] += sizes[rootQ];
            compMaxMap[rootP] = max(compMaxMap[rootQ], compMaxMap[rootP]);
        }
        
    }
    bool connected(int p, int q) {
        return components[p] == components[q];
    }
    int find(int p) {
        int rootP = root(p);
        return compMaxMap[rootP];
    } 
    int count() {
        return 0;
    }
};

int main() {
    UnionFind uf(7);
    uf.unionize(0, 1);
    uf.unionize(2, 3);
    uf.unionize(2, 4);
    uf.unionize(3, 0);
    uf.unionize(5, 6);

    cout << uf.connected();
    printf("root of 2 = %d", uf.root(2));
    printf("root of 4 = %d", uf.root(4));
    printf("root of 1 = %d", uf.root(1));
    printf("root of 5 = %d", uf.root(5));
    /*cout << uf.connected(0, 1) << endl;
    cout << uf.connected(2, 4) << endl;
    cout << uf.connected(2, 6) << endl;
    cout << uf.connected(5, 6) << endl;*/
}