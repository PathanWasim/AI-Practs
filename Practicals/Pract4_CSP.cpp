#include <iostream>
#include <vector>
#include <map>
using namespace std;

// CSP Implementation for Map Coloring Problem
class MapColoringCSP
{
private:
    map<string, vector<string>> graph; // adjacency list
    map<string, string> colors;        // assigned colors
    vector<string> colorOptions;       // available colors

public:
    MapColoringCSP()
    {
        colorOptions = {"Red", "Green", "Blue"};
    }

    void addRegion(string region, vector<string> neighbors)
    {
        graph[region] = neighbors;
    }

    bool isColorValid(string region, string color)
    {
        for (const string &neighbor : graph[region])
        {
            if (colors.count(neighbor) && colors[neighbor] == color)
            {
                return false;
            }
        }
        return true;
    }

    bool solveCSP(vector<string> &regions, int index)
    {
        if (index == regions.size())
        {
            return true;
        }

        string currentRegion = regions[index];

        for (const string &color : colorOptions)
        {
            if (isColorValid(currentRegion, color))
            {
                colors[currentRegion] = color;

                if (solveCSP(regions, index + 1))
                {
                    return true;
                }

                colors.erase(currentRegion);
            }
        }

        return false;
    }

    void printSolution()
    {
        for (const auto &pair : colors)
        {
            cout << pair.first << " -> " << pair.second << endl;
        }
    }
};

int main()
{
    MapColoringCSP csp;

    // Adding regions and their neighbors
    csp.addRegion("WA", {"NT", "SA"});
    csp.addRegion("NT", {"WA", "SA", "QLD"});
    csp.addRegion("SA", {"WA", "NT", "QLD", "NSW", "VIC"});
    csp.addRegion("QLD", {"NT", "SA", "NSW"});
    csp.addRegion("NSW", {"QLD", "SA", "VIC"});
    csp.addRegion("VIC", {"SA", "NSW"});

    vector<string> regions = {"WA", "NT", "SA", "QLD", "NSW", "VIC"};

    cout << "Map Coloring Solution:\n";
    if (csp.solveCSP(regions, 0))
    {
        csp.printSolution();
    }
    else
    {
        cout << "No solution exists.\n";
    }

    return 0;
}