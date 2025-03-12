#include <bits/stdc++.h>

using namespace std;

struct pos {
    int x, y;
};

int main() {
    int n, w, h, l; cin >> n >> w >> h >> l;
    vector<vector<bool>> is_wall;
    vector<vector<pos>> states(1);
    pos goal;
    getchar();
    for (int y = 0; y < h; y++) {
        vector<bool> walls_line;
        for (int x = 0; x < w; x++) {
            char ch = getchar();
            switch (ch) {
                case '.':
                    walls_line.push_back(false);
                    break;
                case 'W':
                    walls_line.push_back(true);
                    break;
                case '1':
                    states[0][0] = {x,y};
                    walls_line.push_back(false);
                    break;
                case '2':
                    states[0][1] = {x,y};
                    walls_line.push_back(false);
                    break;
                case '3':
                    states[0][2] = {x,y};
                    walls_line.push_back(false);
                    break;
                case '4':
                    states[0][3] = {x,y};
                    walls_line.push_back(false);
                    break;
                case 'X':
                    walls_line.push_back(false);
                    goal = {x,y};
                    break;
            }
        }
        getchar();
        is_wall.push_back(walls_line);
    }

    // for each turn
    for (int turn = 0; turn < l; turn++) {
        vector<vector<pos>> new_states;
        // for each state
        for (vector<pos> state : states) {
            // for each robot in that state
            for (int robot = 0; robot < n; robot++) {
                int x;
                // try left
                for (x = state[robot].x; x >= 0; x--) {
                    if (x != 0) {
                        if (is_wall[x-1][state[robot].y]) {
                            break;
                        }
                    }
                    bool can_move;
                    for (int other_robot = 0; other_robot < n; other_robot++) {
                        if (other_robot == robot) {
                            continue;
                        }
                        if (state[other_robot].x == state[robot].x-1) {
                            can_move = false;
                            break;
                        }
                    }
                    if (!can_move) {
                        break;
                    }
                }
                if (x != state[robot].x) {
                    vector<pos> new_state = state;
                    new_state[robot].x = x;
                    new_states.push_back(new_state);
                }
                // try right
                for (x = state[robot].x; x < w; x++) {
                    if (is_wall[x+1][state[robot].y]) {
                        break;
                    }
                    bool can_move;
                    for (int other_robot = 0; other_robot < n; other_robot++) {
                        if (other_robot == robot) {
                            continue;
                        }
                        if (state[other_robot].x == state[robot].x-1) {
                            can_move = false;
                            break;
                        }
                    }
                    if (!can_move) {
                        break;
                    }
                }
                if (x != state[robot].x) {
                    vector<pos> new_state = state;
                    new_state[robot].x = x;
                    new_states.push_back(new_state);
                }
            }
        }
        states = new_states;
    }
}