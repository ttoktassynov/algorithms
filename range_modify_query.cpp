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
void modify(int v, int vl, int vr, int pos, int val){
    if (pos < vl || pos > vr){
        return;
    }
    if (vl == vr){
        t[v] = val;
        return;
    }
    int vm = vl + (vr - vl) / 2;
    if (pos <= vm)
        modify(2 * v + 1, vl, vm, pos, val);
    else
        modify(2 * v + 2, vm + 1, vr, pos, val);
    t[v] = t[2 * v + 1] + t[2 * v + 2];
}
int main(){
    int a[100'000];
    int aSize;
    cin >> aSize;
    for (int i = 0;i < aSize; ++i){
        cin >> a[i];
    }
    build(0, 0, aSize - 1, a);
    int queriesCount;
    cin >> queriesCount;
    while (queriesCount--){
        char queryType;
        cin >> queryType;
        if (queryType == 's'){
            int l, r;
            cin >> l >> r;
            printf("%lld", query(0, 0, aSize - 1, l - 1, r - 1));
        }else{
            int pos, val;
            cin >> pos >> val;
            modify(0, 0, aSize - 1, pos - 1, val);
        }
    }
}