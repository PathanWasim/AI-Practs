#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'}};

void printBoard()
{
    cout << "\n";
    for (int i = 0; i < 3; i++)
    {
        cout << " ";
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j];
            if (j < 2)
                cout << " | ";
        }
        cout << "\n";
        if (i < 2)
            cout << "---+---+---\n";
    }
    cout << "\n";
}

bool isMovesLeft()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return true;
    return false;
}

int evaluate()
{
    // rows & cols
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            if (board[i][0] == 'O')
                return +10;
            else if (board[i][0] == 'X')
                return -10;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            if (board[0][i] == 'O')
                return +10;
            else if (board[0][i] == 'X')
                return -10;
        }
    }
    // diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        if (board[0][0] == 'O')
            return +10;
        else if (board[0][0] == 'X')
            return -10;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        if (board[0][2] == 'O')
            return +10;
        else if (board[0][2] == 'X')
            return -10;
    }
    return 0;
}

int minimax(bool isMax)
{
    int score = evaluate();
    if (score == 10)
        return score;
    if (score == -10)
        return score;
    if (!isMovesLeft())
        return 0;

    if (isMax)
    {
        int best = -1000;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] != 'X' && board[i][j] != 'O')
                {
                    char save = board[i][j];
                    board[i][j] = 'O';
                    best = max(best, minimax(false));
                    board[i][j] = save;
                }
            }
        }
        return best;
    }
    else
    {
        int best = 1000;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] != 'X' && board[i][j] != 'O')
                {
                    char save = board[i][j];
                    board[i][j] = 'X';
                    best = min(best, minimax(true));
                    board[i][j] = save;
                }
            }
        }
        return best;
    }
}

int findBestMove()
{
    int bestVal = -1000;
    int bestMove = -1;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                char save = board[i][j];
                board[i][j] = 'O';
                int moveVal = minimax(false);
                board[i][j] = save;
                if (moveVal > bestVal)
                {
                    bestMove = (i * 3 + j + 1);
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}

int main()
{
    cout << "Player = X, Computer = O\n";
    printBoard();

    while (true)
    {
        int move;
        cout << "Enter your move (1-9): ";
        cin >> move;

        int r = (move - 1) / 3, c = (move - 1) % 3;
        if (move < 1 || move > 9 || board[r][c] == 'X' || board[r][c] == 'O')
        {
            cout << "Invalid move, try again.\n";
            continue;
        }

        board[r][c] = 'X';
        printBoard();

        if (evaluate() == -10)
        {
            cout << "You win!\n";
            break;
        }
        if (!isMovesLeft())
        {
            cout << "Draw!\n";
            break;
        }

        int bestMove = findBestMove();
        int rr = (bestMove - 1) / 3, cc = (bestMove - 1) % 3;
        board[rr][cc] = 'O';
        cout << "Computer chose: " << bestMove << "\n";
        printBoard();

        if (evaluate() == 10)
        {
            cout << "Computer wins!\n";
            break;
        }
        if (!isMovesLeft())
        {
            cout << "Draw!\n";
            break;
        }
    }
    return 0;
}
