
#include <iostream>
using namespace std;

// Node indices: 0:A, 1:B, 2:C, 3:D, 4:E
float h[5]      = {10, 4, 2, 5, 0};   // initial heuristic cost
bool  isGoal[5] = {false, false, true, true, true};

float aoStar(int node, string indent = "") {
    cout << indent << "Evaluating node ";

    char name = 'A' + node;
    cout << name << " (h = " << h[node] << ")\n";

    // Terminal / goal node
    if (isGoal[node]) {
        cout << indent << " -> Goal node, cost = " << h[node] << "\n";
        return h[node];
    }

    float cost1, cost2;

    if (node == 0) { 
        // Node A
        // Option 1: AND child set {B, C}
        float costB = aoStar(1, indent + "  ");
        float costC = aoStar(2, indent + "  ");
        cost1 = 1 + costB + 1 + costC;   // edges A-B and A-C have cost 1

        // Option 2: OR child {D}
        float costD = aoStar(3, indent + "  ");
        cost2 = 1 + costD;               // edge A-D cost 1

        cout << indent << "Cost via {B,C} (AND) = " << cost1 << endl;
        cout << indent << "Cost via {D}   (OR)  = " << cost2 << endl;

        if (cost1 < cost2) {
            cout << indent << "=> Best choice for A is AND-set {B,C}\n";
            h[node] = cost1;
            return cost1;
        } else {
            cout << indent << "=> Best choice for A is OR-child {D}\n";
            h[node] = cost2;
            return cost2;
        }
    }

    if (node == 1) {
        // Node B
        // Only one OR option: child {E}
        float costE = aoStar(4, indent + "  ");
        cost1 = 1 + costE;   // edge B-E cost 1
        cout << indent << "Cost via {E} = " << cost1 << endl;
        h[node] = cost1;
        return cost1;
    }

    // Should not reach here
    return h[node];
}

int main() {
    cout << "AO* Algorithm on a small AND-OR graph\n";
    float totalCost = aoStar(0);
    cout << "\nFinal best cost from A = " << totalCost << endl;
    cout << "Best solution: A -> D (because it is cheaper than A -> {B,C})\n";
    return 0;
}
