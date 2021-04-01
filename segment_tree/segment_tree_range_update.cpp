#include <iostream>
using namespace std;
int a[100'000];
int t[4 * 100'000];
int tAdd[4 * 100'000];

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
int main(){

}