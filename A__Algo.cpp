#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int x, y, g, f;
};

// Comparator for priority queue
struct Compare {
    bool operator()(Node a, Node b) {
        return a.f > b.f;
    }
};

// Heuristic function (Manhattan Distance)
int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// Check valid cell
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

    priority_queue<Node, vector<Node>, Compare> pq;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int,int>>> parent(n,
        vector<pair<int,int>>(m, {-1,-1}));

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int startH = heuristic(start.first, start.second,
                           goal.first, goal.second);

    pq.push({start.first, start.second, 0, startH});

    cout << "\n--- A* Step by Step ---\n";

    while (!pq.empty()) {

        Node curr = pq.top();
        pq.pop();

        int x = curr.x;
        int y = curr.y;

        if (visited[x][y])
            continue;

        visited[x][y] = true;

        // Print current node details
        int h = heuristic(x, y, goal.first, goal.second);

        cout << "\nVisiting Node: (" << x << "," << y << ")";
        cout << "\ng = " << curr.g;
        cout << "\nh = " << h;
        cout << "\nf = g + h = " << curr.f << endl;

        // Goal reached
        if (x == goal.first && y == goal.second) {

            vector<pair<int,int>> path;

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
                     << "," << cell.second << ") ";
            }

            cout << "\nTotal Steps: "
                 << path.size() - 1 << endl;
            return;
        }

        // Explore neighbors
        for (int i = 0; i < 4; i++) {

            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny, n, m, maze)
                && !visited[nx][ny]) {

                int g = curr.g + 1;
                int h = heuristic(nx, ny,
                                  goal.first,
                                  goal.second);
                int f = g + h;

                parent[nx][ny] = {x, y};

                // Print neighbor details
                cout << "  Neighbor: (" << nx << "," << ny << ")";
                cout << " | g=" << g;
                cout << " h=" << h;
                cout << " f=" << f << endl;

                pq.push({nx, ny, g, f});
            }
        }
    }

    cout << "\nNo Path Found!";
}

int main() {

    int n, m;
    cout << "Enter rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> maze(n, vector<int>(m));

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

/*

Application :- Maze Solver

8 8

0 0 0 1 0 0 0 0
1 1 0 1 0 1 1 0
0 0 0 0 0 0 1 0
0 1 1 1 1 0 1 0
0 1 0 0 0 0 0 0
0 1 0 1 1 1 1 0
0 0 0 0 0 0 1 0
1 1 1 1 1 0 0 0

0 0
7 7

*/