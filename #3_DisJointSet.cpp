/*
    TODO: DisJointSet
    ?
*/

#include "bits/stdc++.h"
using namespace std;

class DisJointSet {
public:
    vector<int> parent,size;
    DisJointSet(int n) {
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i] = i;
    }
    int findParent(int node) {
        if(node == parent[node]) return node;
        else return parent[node] = findParent(parent[node]);
    }
    void Union(int u, int v) {
        int ult_u = findParent(u), ult_v = findParent(v);
        if(ult_u == ult_v) return;
        if(size[ult_u] < size[ult_v]) {
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        } else {
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }
};