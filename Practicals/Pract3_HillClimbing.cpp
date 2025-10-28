#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// Hill Climbing implementation for solving optimization problems
// Example: Finding maximum value in a hilly terrain

class HillClimbing
{
private:
    vector<int> terrain;
    int size;

    // Generate a random terrain for demonstration
    void generateTerrain()
    {
        for (int i = 0; i < size; i++)
        {
            // Generate heights between 0 and 100
            terrain[i] = rand() % 101;
        }
    }

    // Get value at current position
    int getValue(int position)
    {
        return terrain[position];
    }

    // Get neighboring positions
    vector<int> getNeighbors(int position)
    {
        vector<int> neighbors;
        if (position > 0)
            neighbors.push_back(position - 1);
        if (position < size - 1)
            neighbors.push_back(position + 1);
        return neighbors;
    }

public:
    HillClimbing(int n) : size(n)
    {
        terrain.resize(n);
        srand(time(0));
        generateTerrain();
    }

    // Simple Hill Climbing
    int simpleHillClimbing(int start_pos)
    {
        int current_pos = start_pos;
        bool improved;

        do
        {
            improved = false;
            int current_value = getValue(current_pos);
            vector<int> neighbors = getNeighbors(current_pos);

            // Check all neighbors
            for (int next_pos : neighbors)
            {
                int next_value = getValue(next_pos);
                if (next_value > current_value)
                {
                    current_pos = next_pos;
                    improved = true;
                    break;
                }
            }
        } while (improved);

        return current_pos;
    }

    // Steepest Ascent Hill Climbing
    int steepestAscentHillClimbing(int start_pos)
    {
        int current_pos = start_pos;
        bool improved;

        do
        {
            improved = false;
            int current_value = getValue(current_pos);
            vector<int> neighbors = getNeighbors(current_pos);
            int best_neighbor = current_pos;
            int best_value = current_value;

            // Find the best neighbor
            for (int next_pos : neighbors)
            {
                int next_value = getValue(next_pos);
                if (next_value > best_value)
                {
                    best_neighbor = next_pos;
                    best_value = next_value;
                    improved = true;
                }
            }

            current_pos = best_neighbor;
        } while (improved);

        return current_pos;
    }

    // Random Restart Hill Climbing
    int randomRestartHillClimbing(int num_restarts)
    {
        int best_pos = rand() % size;
        int best_value = getValue(best_pos);

        for (int i = 0; i < num_restarts; i++)
        {
            int start_pos = rand() % size;
            int result_pos = steepestAscentHillClimbing(start_pos);
            int result_value = getValue(result_pos);

            if (result_value > best_value)
            {
                best_pos = result_pos;
                best_value = result_value;
            }
        }

        return best_pos;
    }

    // Print the terrain
    void printTerrain()
    {
        cout << "Terrain heights: ";
        for (int height : terrain)
        {
            cout << height << " ";
        }
        cout << endl;
    }
};

int main()
{
    int size = 20; // Size of the terrain
    HillClimbing hc(size);

    // Print the terrain
    cout << "Generated terrain:" << endl;
    hc.printTerrain();

    // Test simple hill climbing
    int start_pos = rand() % size;
    cout << "\nSimple Hill Climbing:" << endl;
    cout << "Starting position: " << start_pos << endl;
    int result1 = hc.simpleHillClimbing(start_pos);
    cout << "Found local maximum at position: " << result1 << endl;

    // Test steepest ascent hill climbing
    cout << "\nSteepest Ascent Hill Climbing:" << endl;
    cout << "Starting position: " << start_pos << endl;
    int result2 = hc.steepestAscentHillClimbing(start_pos);
    cout << "Found local maximum at position: " << result2 << endl;

    // Test random restart hill climbing
    cout << "\nRandom Restart Hill Climbing:" << endl;
    int num_restarts = 5;
    int result3 = hc.randomRestartHillClimbing(num_restarts);
    cout << "Found best maximum at position: " << result3 << endl;

    return 0;
}