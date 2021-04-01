#include <stdio.h>
#include <algorithm>

long long t[4 * 100'000];
long long tAdd[4 * 100'000];
long long tMul[4 * 100'000];
long long tSet[4 * 100'000];

const long long M = 1e9 + 7;
void build(int v, int vl, int vr, int a []){
    tSet[v] = 0;
    tMul[v] = 1;
    tAdd[v] = 0;
    if (vl == vr){
        t[v] = a[vl];
        return;
    }
    int vm = vl + (vr - vl) / 2;
    build(2 * v + 1, vl, vm, a);
    build(2 * v + 2, vm + 1, vr, a);
    t[v] = (t[2 * v + 1] + t[2 * v + 2]) % M;
}
void push(int v, int vl, int vr){
    if (tSet[v] != 0){
        t[v] = (tSet[v] * (vr - vl + 1)) % M;
        if (vl != vr){
            tSet[2 * v + 1] = tSet[v] % M;
            tSet[2 * v + 2] = tSet[v] % M;
            tMul[2 * v + 1] = 1;
            tMul[2 * v + 2] = 1;
            tAdd[2 * v + 1] = 0;
            tAdd[2 * v + 2] = 0;
        }
        tSet[v] = 0;
    }
    if (tMul[v] != 1){
        t[v] = (t[v] * tMul[v]) % M;
        if (vl != vr){
            tMul[2 * v + 1] = (tMul[2 * v + 1] * tMul[v]) % M;
            tMul[2 * v + 2] = (tMul[2 * v + 2] * tMul[v]) % M;
            tAdd[2 * v + 1] = (tAdd[2 * v + 1] * tMul[v]) % M;
            tAdd[2 * v + 2] = (tAdd[2 * v + 2] * tMul[v]) % M;
        }
        tMul[v] = 1;
    }
    if (tAdd[v] != 0){
        t[v] = (t[v] + tAdd[v] * (vr - vl + 1)) % M;
        if (vl != vr){
            tAdd[2 * v + 1] = (tAdd[2 * v + 1] + tAdd[v]) % M;
            tAdd[2 * v + 2] = (tAdd[2 * v + 2] + tAdd[v]) % M;
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
    return (left + right) % M;
}
void modify(int v, int vl, int vr, int l, int r, int set, int mul, int add){
    push(v, vl, vr);
    if (r < vl || vr < l){
        return;
    }
    if (l <= vl && vr <= r){
        if (set != 0){
            tSet[v] = set;
        }
        if (mul != 1){
            tMul[v] = mul;
        }
        if (add != 0){
            tAdd[v] = add;
        }
        push(v, vl, vr);
        return;
    }
    int vm = vl + (vr - vl) / 2;
    modify(2 * v + 1, vl, vm, l, r, set, mul, add);
    modify(2 * v + 2, vm + 1, vr, l, r, set, mul, add);
    t[v] = (t[2 * v  + 1] + t[2 * v + 2]) % M;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   
    int a[100'000];
    int aSize, queriesCount;
    scanf("%d%d", &aSize, &queriesCount);
    for (int i = 0 ; i < aSize; ++i){
        scanf("%d", &a[i]);
    }
    build(0, 0, aSize - 1, a);
    for (int i = 0; i < queriesCount; ++i){
        int type, l, r, val;
        scanf("%d%d%d",&type, &l, &r);
        if (type == 1){
            scanf("%d", &val);
            modify(0, 0, aSize - 1, l - 1, r - 1, 0, 1, val);
        }
        else if (type == 2){
            scanf("%d", &val);
            modify(0, 0, aSize - 1, l - 1, r - 1, 0, val, 0);
        }
        else if (type == 3){
            scanf("%d", &val);
            modify(0, 0, aSize - 1, l - 1, r - 1, val, 1, 0);
        }
        else {
            printf("%lld\n", query(0, 0, aSize - 1, l - 1, r - 1));
        }
    }
    
}