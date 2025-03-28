#include <bits/stdc++.h>
using namespace std;

#define MAX_N 200001
#define MODULO 1000000007

typedef long long ll;

int segtree[4*MAX_N];
set<pair<int,int>> bst;
set<pair<int,int>> bst_flip;
ll expression_prev;
ll expression_flip_prev;

// https://cp-algorithms.com/data_structures/segment_tree.html#implementation
// ( should probably print this out if you're going to ICPC )

void build_segtree(string &a, int v, int tl, int tr) {
    if (tl == tr) {
        segtree[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build_segtree(a, v*2, tl, tm);
        build_segtree(a, v*2+1, tm+1, tr);
        segtree[v] =
            segtree[v*2]
            * // this can be any associative operation
            segtree[v*2+1]
            % MODULO;
    }
}

int query_segtree(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return segtree[v];
    }
    int tm = (tl + tr) / 2;
    return query_segtree(v*2, tl, tm, l, min(r, tm))
           * // this can be any associative operation
           query_segtree(v*2+1, tm+1, tr, max(l, tm+1), r)
           % MODULO;
}

void update_segtree(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        segtree[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update_segtree(v*2, tl, tm, pos, new_val);
        else
            update_segtree(v*2+1, tm+1, tr, pos, new_val);
        segtree[v] = segtree[v*2]
        * // see above comments
        segtree[v*2+1]
        % MODULO;
    }
}

pair<int,int> parse_range(int& i) {
    
}

void init_bst() {
    int i = 0;
    while (i < MAX_N) {
        bst.insert(parse_range(i));
    }
}

int main() {
    // get inputs
    size_t N, M; cin >> N >> M;
    string input_expression; cin >> input_expression;
    // initialize data structures
    build_segtree(input_expression,1,0,input_expression.length());
    bst = set<pair<int,int>>();
    bst_flip = set<pair<int,int>>();
    
}