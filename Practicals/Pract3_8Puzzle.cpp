#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;

class EightPuzzle
{
private:
    vector<vector<int>> board;
    vector<vector<int>> goal;
    pair<int, int> blank_pos;

    // Manhattan distance heuristic
    int getManhattanDistance()
    {
        int distance = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] != 0)
                {
                    // Find position of current number in goal state
                    for (int x = 0; x < 3; x++)
                    {
                        for (int y = 0; y < 3; y++)
                        {
                            if (goal[x][y] == board[i][j])
                            {
                                distance += abs(x - i) + abs(y - j);
                            }
                        }
                    }
                }
            }
        }
        return distance;
    }

    // Convert board to string for state tracking
    string boardToString()
    {
        string s = "";
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                s += to_string(board[i][j]);
            }
        }
        return s;
    }

    // Check if move is valid
    bool isValidMove(int x, int y)
    {
        return x >= 0 && x < 3 && y >= 0 && y < 3;
    }

public:
    EightPuzzle(vector<vector<int>> initial)
    {
        board = initial;
        // Set goal state
        goal = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

        // Find blank position
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == 0)
                {
                    blank_pos = {i, j};
                    break;
                }
            }
        }
    }

    void printBoard()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    bool solve()
    {
        // Priority queue for A* search
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
        map<string, vector<vector<int>>> states; // Track visited states
        map<string, string> parent;              // Track parent states for path
        map<string, int> g_score;                // Track cost to reach each state

        string initial_state = boardToString();
        pq.push({getManhattanDistance(), initial_state});
        states[initial_state] = board;
        g_score[initial_state] = 0;

        vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Up, Down, Left, Right

        while (!pq.empty())
        {
            string current_state = pq.top().second;
            pq.pop();

            if (current_state == "123456780")
            { // Goal state
                // Print solution path
                vector<string> path;
                string state = current_state;
                while (parent.find(state) != parent.end())
                {
                    path.push_back(state);
                    state = parent[state];
                }
                path.push_back(initial_state);

                cout << "Solution found in " << path.size() - 1 << " moves:\n\n";
                for (int i = path.size() - 1; i >= 0; i--)
                {
                    vector<vector<int>> curr_board = states[path[i]];
                    for (int j = 0; j < 3; j++)
                    {
                        for (int k = 0; k < 3; k++)
                        {
                            cout << curr_board[j][k] << " ";
                        }
                        cout << endl;
                    }
                    cout << endl;
                }
                return true;
            }

            // Get current board state
            board = states[current_state];

            // Find blank position
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (board[i][j] == 0)
                    {
                        blank_pos = {i, j};
                        break;
                    }
                }
            }

            // Try all possible moves
            for (auto move : moves)
            {
                int new_x = blank_pos.first + move.first;
                int new_y = blank_pos.second + move.second;

                if (isValidMove(new_x, new_y))
                {
                    // Create new board state
                    vector<vector<int>> new_board = board;
                    swap(new_board[blank_pos.first][blank_pos.second],
                         new_board[new_x][new_y]);

                    string new_state = "";
                    for (int i = 0; i < 3; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            new_state += to_string(new_board[i][j]);
                        }
                    }

                    int new_g = g_score[current_state] + 1;
                    if (states.find(new_state) == states.end() ||
                        new_g < g_score[new_state])
                    {
                        states[new_state] = new_board;
                        g_score[new_state] = new_g;
                        parent[new_state] = current_state;
                        int f = new_g + getManhattanDistance();
                        pq.push({f, new_state});
                    }
                }
            }
        }

        return false;
    }
};

int main()
{
    // Example initial state
    vector<vector<int>> initial = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 5, 8}};

    cout << "Initial state:\n";
    EightPuzzle puzzle(initial);
    puzzle.printBoard();

    cout << "Solving...\n\n";
    if (!puzzle.solve())
    {
        cout << "No solution found!\n";
    }

    return 0;
}