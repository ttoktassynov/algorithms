#include <iostream>
#include <algorithm>
using namespace std;

long long t[4 * 100'000];
long long tAdd[4 * 100'000];
int a[100'000];

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
void push(int v, int vl, int vr){
    if (tAdd[v] != 0){
        t[v] += tAdd[v] * (vr - vl + 1);
        if (vl != vr){
            tAdd[2 * v + 1] += tAdd[v];
            tAdd[2 * v + 2] += tAdd[v];
        }
        tAdd[v] = 0;
    }
}
long long query(int v, int vl, int vr, int l, int r){
    push(v, vl, vr);
    if (r < vl || l > vr){
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
void modify(int v, int vl, int vr, int l, int r, int val){
    push(v, vl, vr);
    if (r < vl || vr < l){
        return;
    }
    if (l <= vl && vr <= r){
        tAdd[v] = val;
        push(v, vl, vr);
        return;
    }
    int vm = vl + (vr - vl) / 2;
    modify(2 * v + 1, vl, vm, l, r, val);
    modify(2 * v + 2, vm + 1, vr, l, r, val);
    t[v] = t[2 * v  + 1] + t[2 * v + 2];
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   
    int testCount;
    cin >> testCount;
    for (int testNumber = 1; testNumber <= testCount; ++testNumber){
        int aSize, queriesCount;
        cin >> aSize >> queriesCount;
        fill(t, t + 4 * aSize, 0);
        fill(tAdd, tAdd + 4 * aSize, 0);
        for (int i = 0; i < queriesCount; ++i){
            int type, l, r, val;
            cin >> type >> l >> r;
            if (type == 0){
                cin >> val;
                modify(0, 0, aSize - 1, l - 1, r - 1, val);
            }
            else {
                printf("%lld\n", query(0, 0, aSize - 1, l - 1, r - 1));
            }
        }
    }
}