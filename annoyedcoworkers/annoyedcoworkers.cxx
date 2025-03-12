#include <bits/stdc++.h>

using namespace std;

struct coworker {
    int a;
    int d;
};



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, c; cin >> h >> c;
    priority_queue<coworker, vector<adjlist_edge>, 
        decltype([](adjlist_edge &a, adjlist_edge &b){return a.second > b.second;})> pq;
    vector<coworker> coworkers;
    for (int i = 0; i < c; i++) {
        coworker cw; cin >> cw.a >> cw.d;
        coworkers.push_back(cw);
    }

}