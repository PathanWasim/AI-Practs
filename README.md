# Artificial Intelligence Lab Practicals

This repository contains implementations of various Artificial Intelligence algorithms and concepts as part of the AI Laboratory course.

## List of Practicals

### 1. Game Implementation
- **Pract1_TicTacToe.cpp**: Implementation of TicTacToe game (Human vs Human)
- **Pract1_TicTacToe_AI.cpp**: Implementation of TicTacToe with AI opponent

### 2. Uninformed Search Strategies
- **Pract2_Uninformed_Search.cpp**: Basic implementation of DFS and BFS
- **Pract2_Uninformed_Search_Enhanced.cpp**: Advanced implementation including:
  - Breadth-First Search (BFS)
  - Depth-First Search (DFS)
  - Iterative Deepening DFS (IDDFS)

### 3. Informed Search Strategies
- **Pract3_AStar.cpp**: A* Search Algorithm Implementation
- **Pract3_GreedyBestFirst.cpp**: Greedy Best-First Search Implementation
- **Pract3_HillClimbing.cpp**: Hill Climbing Search with variants:
  - Simple Hill Climbing
  - Steepest Ascent
  - Random Restart
- **Pract3_8Puzzle.cpp**: 8-Puzzle Problem using A* Search

### 4. Constraint Satisfaction Problems (CSP)
- **Pract4_CSP.cpp**: Map Coloring Problem
- **Pract4_NQueens.cpp**: N-Queens Problem with multiple solutions

### 5. Logic Programming
- **Pract5_PredicateLogic.pl**: Predicate Logic implementation in Prolog
  - Family relationships
  - Basic rules and facts

### 6. Expert System
- **Pract6_ExpertSystem.pl**: Medical Diagnosis Expert System in Prolog
  - Knowledge base
  - Inference engine
  - User interface

## How to Run

### C++ Programs
1. Compile using g++:
   ```bash
   g++ -o program_name program_name.cpp
   ```
2. Run the executable:
   ```bash
   ./program_name
   ```

### Prolog Programs
1. Install SWI-Prolog
2. Load the program:
   ```prolog
   swipl program_name.pl
   ```
3. Query the program using the predicates defined in each file

## Requirements
- C++ Compiler (C++11 or later)
- SWI-Prolog for running Prolog programs