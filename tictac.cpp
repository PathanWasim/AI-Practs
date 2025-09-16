#include <iostream>
using namespace std;

char board[3][3] = { {'1','2','3'},
                     {'4','5','6'},
                     {'7','8','9'} };

void printBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

bool checkWin(char p) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0]==p && board[i][1]==p && board[i][2]==p) return true;
        if (board[0][i]==p && board[1][i]==p && board[2][i]==p) return true;
    }
    if (board[0][0]==p && board[1][1]==p && board[2][2]==p) return true;
    if (board[0][2]==p && board[1][1]==p && board[2][0]==p) return true;
    return false;
}

bool isMovesLeft() {
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            if (board[i][j] != 'X' && board[i][j] != 'O') return true;
    return false;
}

int main() {
    cout << "Player 1 = X, Player 2 = O\n";
    printBoard();

    char player = 'X';
    while (true) {
        int move;
        cout << "Player " << (player=='X' ? 1:2) 
             << " enter block number (1-9): ";
        cin >> move;

        if (move < 1 || move > 9) {
            cout << "Invalid move, try again.\n";
            continue;
        }

        int r = (move-1)/3;
        int c = (move-1)%3;

        if (board[r][c]=='X' || board[r][c]=='O') {
            cout << "Block already taken, try again.\n";
            continue;
        }

        board[r][c] = player;
        printBoard();

        if (checkWin(player)) {
            cout << "Player " << (player=='X' ? 1:2) << " wins!\n";
            break;
        }
        if (!isMovesLeft()) {
            cout << "Game is a Draw!\n";
            break;
        }

        player = (player=='X') ? 'O':'X';
    }
    return 0;
}
