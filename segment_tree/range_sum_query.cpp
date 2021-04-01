#include <iostream>
using namespace std;

long long t[4 * 100'000];

void build(int v, int vl, int vr, int a []){
    if (vl == vr){
        t[v] = a[vl];
        return;
    }
    int vm = vl + (vr - vl) / 2;
    build(2 * v + 1, vl, vm, a);
    build(2 * v + 2, vm + 1, vr, a);
    t[v] = t[2 * v + 1] + t[2 * v + 2];
}
long long query(int v, int vl, int vr, int l, int r){
    if (l < vl || r > vr){
        return 0;
    }
    if (l <= vl && vr <= r ){
        return t[v];
    }
    int vm = vl + (vr - vl) / 2;
    long long left = query(2 * v + 1, vl, vm, l, r);
    long long right = query(2 * v + 2, vm + 1, vr, l, r);
    return left + right;
}
int main(){
    int a[100'000];
    int aSize;
    cin >> aSize;
    for (int i = 0;i < aSize; ++i){
        cin >> a[i];
    }
    build(0, 0, aSize - 1, a);
    int queriesCount, l, r;
    cin >> queriesCount;
    while (queriesCount--){
        cin >> l >> r;
        cout << query(0, 0, aSize - 1, l - 1, r - 1) << " ";
    }
}