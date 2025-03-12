#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int best;
    unordered_map<int,vector<int>> adjacent;
    unordered_map<int,int> parent;
    unordered_map<int,int> bob_path;
    unordered_map<int,vector<int>> children;

    void dfs(int value, int node, int time, vector<int>& amount) {
        if (bob_path.count(node)) {
            if (bob_path[node] > time) {
                value += amount[node];
            } else if (bob_path[node] == time) {
                value += amount[node] / 2;
            }
        } else {
            value += amount[node];
        }
        if (children.count(node)) {
            for (int child : children[node]) {
                dfs(value,child,time+1,amount);
            }
        } else { // at leaf node
            if (value > best) best = value;
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        best = -100000;
        adjacent = unordered_map<int,vector<int>>();
        // edge list -> adjacency list
        for (vector<int> edge : edges) {
            if (adjacent.count(edge[0])) {
                adjacent[edge[0]].push_back(edge[1]);
            } else {
                adjacent[edge[0]] = {edge[1]};
            }
            if (adjacent.count(edge[1])) {
                adjacent[edge[1]].push_back(edge[0]);
            } else {
                adjacent[edge[1]] = {edge[0]};
            }
        }
        // adjacency list -> list of children and parents
        unordered_set<int> traversed = unordered_set<int>();
        children = unordered_map<int,vector<int>>();
        parent = unordered_map<int,int>();
        stack<int> dfs1 = stack<int>(); dfs1.push(0);
        while (!dfs1.empty()) {
            int top = dfs1.top(); dfs1.pop();
            traversed.insert(top);
            for (int child : adjacent[top]) {
                if (traversed.count(child)) continue;
                else {
                    if (children.count(top)) {
                        children[top].push_back(child);
                    } else {
                        children[top] = {child};
                    }
                    parent[child] = top;
                    dfs1.push(child);
                }
            }
        }
        // if bob will be there at some point, record the step at which he arrives
        bob_path = unordered_map<int,int>();
        // compute bob's path
        int bob_time = 0;
        while (parent.count(bob)) {
            bob_path.insert({bob,bob_time});
            bob = parent[bob];
            bob_time++;
        }
        // perform dfs
        dfs(0,0,0,amount);
        return best;
    }
};

int main() {
    Solution s = Solution();
    vector<vector<int>> edges = {{0,2},{0,5},{1,3},{1,5},{2,4}};
    vector<int> amount = {5018,8388,6224,3466,3808,3456};
    cout << s.mostProfitablePath(edges,4,amount) << endl;
}