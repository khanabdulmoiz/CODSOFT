#include <iostream>
#include <vector>

using namespace std;

void displayBoard(const vector<vector<char>>& board);
bool makeMove(vector<vector<char>>& board, char currentPlayer, int row, int col);
bool checkWin(const vector<vector<char>>& board, char currentPlayer);
bool checkDraw(const vector<vector<char>>& board);
char switchPlayer(char currentPlayer);
bool playAgain();

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';

    cout << "Welcome to Tic-Tac-Toe!\n";

    do {
        displayBoard(board);

        int row, col;

        do {
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;
        } while (!makeMove(board, currentPlayer, row, col));

        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            if (!playAgain()) {
                break;
            } else {
                board = vector<vector<char>>(3, vector<char>(3, ' '));
                currentPlayer = 'X';
                continue;
            }
        }

        if (checkDraw(board)) {
            displayBoard(board);
            cout << "It's a draw!\n";
            if (!playAgain()) {
                break;
            } else {
                board = vector<vector<char>>(3, vector<char>(3, ' '));
                currentPlayer = 'X';
                continue;
            }
        }

        currentPlayer = switchPlayer(currentPlayer);

    } while (true);

    return 0;
}

void displayBoard(const vector<vector<char>>& board) {
    cout << "Game Board:\n";
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << ' ';
        }
        cout << endl;
    }
}

bool makeMove(vector<vector<char>>& board, char currentPlayer, int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
        cout << "Invalid move. Try again.\n";
        return false;
    }

    board[row][col] = currentPlayer;
    return true;
}

bool checkWin(const vector<vector<char>>& board, char currentPlayer) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }

    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }

    return false;
}

bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}

char switchPlayer(char currentPlayer) {
    return (currentPlayer == 'X') ? 'O' : 'X';
}

bool playAgain() {
    char response;
    cout << "Do you want to play again? (y/n): ";
    cin >> response;
    return (response == 'y' || response == 'Y');
}
