#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    map<string,string> adj_list;
    map<string,bool> is_person;

    for (int i = 0; i < n; i++) {
        string line; vector<string> strs; string str;
        getline(cin, line); istringstream stream(line);
        while (stream >> str){ strs.push_back(str); }
        string person = strs[0];
        string speaks = strs[1];
        is_person[person] = true;
        adj_list[person] = speaks;
        adj_list[speaks] = person;
        for (int i = 2; i < strs.size(); i++) {
            string understands = strs[i];
            adj_list[understands] = person;
        }
    }
}