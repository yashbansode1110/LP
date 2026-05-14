#include <bits/stdc++.h>
using namespace std;

// STEP 1: Create Node structure to store position and cost
struct Node {
    int x, y, g, f;
};

// STEP 1: Comparator so priority queue gives smallest f first
struct Compare {
    bool operator()(Node a, Node b) {
        return a.f > b.f;
    }
};

// STEP 10: Heuristic function (estimated distance to goal)
int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// STEP 9: Check if next cell is valid
bool isValid(int x, int y, int n, int m, vector<vector<int>> &maze) {
    return (x >= 0 && y >= 0 &&
            x < n && y < m &&
            maze[x][y] == 0);
}

void astar(vector<vector<int>> &maze,
           pair<int,int> start,
           pair<int,int> goal) {

    int n = maze.size();
    int m = maze[0].size();

    // STEP 1: Create priority queue
    priority_queue<Node, vector<Node>, Compare> pq;

    // STEP 1: Create visited array
    vector<vector<bool>> visited(n,
        vector<bool>(m, false));

    // STEP 1: Create parent array for path tracking
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1,-1}));

    // STEP 8: Direction arrays (Up, Down, Left, Right)
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    // STEP 2: Push start node
    // g = 0, f = heuristic
    pq.push({start.first, start.second, 0,
            heuristic(start.first, start.second,
                      goal.first, goal.second)});

    // STEP 3: Repeat until queue becomes empty
    while (!pq.empty()) {

        // STEP 4: Take best node (smallest f)
        Node curr = pq.top();
        pq.pop();

        int x = curr.x;
        int y = curr.y;

        // STEP 5: Skip if already visited
        if (visited[x][y])
            continue;

        // STEP 6: Mark visited
        visited[x][y] = true;

        // STEP 7: Check goal reached
        if (x == goal.first && y == goal.second) {

            vector<pair<int,int>> path;

            // STEP 7: Backtrack using parent array
            while (!(x == start.first &&
                     y == start.second)) {

                path.push_back({x, y});

                auto p = parent[x][y];
                x = p.first;
                y = p.second;
            }

            path.push_back(start);
            reverse(path.begin(), path.end());

            cout << "\nPath Found:\n";

            for (auto cell : path) {
                cout << "(" << cell.first
                     << "," << cell.second
                     << ") ";
            }

            cout << "\nTotal Steps: "
                 << path.size() - 1 << endl;

            return;
        }

        // STEP 8: Explore all 4 neighbors
        for (int i = 0; i < 4; i++) {

            int nx = x + dx[i];
            int ny = y + dy[i];

            // STEP 9: Check valid and unvisited
            if (isValid(nx, ny, n, m, maze)
                && !visited[nx][ny]) {

                // STEP 10: Calculate new cost
                int g = curr.g + 1;
                int f = g + heuristic(nx, ny,
                                      goal.first,
                                      goal.second);

                // STEP 11: Save parent
                parent[nx][ny] = {x, y};

                // STEP 12: Push neighbor
                pq.push({nx, ny, g, f});
            }
        }
    }

    // STEP 13: No path exists
    cout << "No Path Found!";
}

int main() {

    int n, m;
    cout << "Enter rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> maze(n,
        vector<int>(m));

    cout << "Enter maze (0=free, 1=blocked):\n";

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> maze[i][j];

    pair<int,int> start, goal;

    cout << "Enter start (x y): ";
    cin >> start.first >> start.second;

    cout << "Enter goal (x y): ";
    cin >> goal.first >> goal.second;

    astar(maze, start, goal);

    return 0;
}