// Sliding Tile Puzzle, by Al Sweigart
// Slide the numbered tiles into the correct order.
// This code is available at https ://nostarch.com/big-book-small-python-programming
// #68 SLIDING TILE PUZZLE

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
using namespace std;

string BLANK = "  ";

vector<vector<string>> getNewBoard() {
    // Return a list of lists that represents a new tile puzzle.
    vector<vector<string>> response = { {"1 ", "5 ", "9 ", "13"}, {"2 ", "6 ", "10", "14"}, {"3 ", "7 ", "11", "15"}, {"4 ", "8 ", "12", BLANK} };
    return response;
}

void displayBoard(vector<vector<string>> board) {
    // Display the given board on the screen.
    cout << "+ ------ + ------ + ------ + ------ +\n";
    cout << "|        |        |        |        |\n";
    cout << "|   " << board[0][0] << "   |   " << board[1][0] << "   |   " << board[2][0] << "   |   " << board[3][0] << "   |\n";
    cout << "|        |        |        |        |\n";
    cout << "+ ------ + ------ + ------ + ------ +\n";
    cout << "|        |        |        |        |\n";
    cout << "|   " << board[0][1] << "   |   " << board[1][1] << "   |   " << board[2][1] << "   |   " << board[3][1] << "   |\n";
    cout << "|        |        |        |        |\n";
    cout << "+ ------ + ------ + ------ + ------ +\n";
    cout << "|        |        |        |        |\n";
    cout << "|   " << board[0][2] << "   |   " << board[1][2] << "   |   " << board[2][2] << "   |   " << board[3][2] << "   |\n";
    cout << "|        |        |        |        |\n";
    cout << "+ ------ + ------ + ------ + ------ +\n";
    cout << "|        |        |        |        |\n";
    cout << "|   " << board[0][3] << "   |   " << board[1][3] << "   |   " << board[2][3] << "   |   " << board[3][3] << "   |\n";
    cout << "|        |        |        |        |\n";
    cout << "+ ------ + ------ + ------ + ------ +\n";
}

void findBlankSpace(vector<vector<string>>& board, int& x, int& y) {
    // Return an (x, y) tuple of the blank space's location.
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (board[i][j] == BLANK) {
                x = i;
                y = j;
                return;
            }
        }
    }
}

string askForPlayerMove(vector<vector<string>>& board) {
    // Let the player select a tile to slide.
    int blankx = -1, blanky = -1;
    findBlankSpace(board, blankx, blanky);
    char w, a, s, d;

    if (blanky != 3) {
        w = 'W';
    } else {
        w = ' ';
    }

    if (blankx != 3) {
        a = 'A';
    } else {
        a = ' ';
    }

    if (blanky != 0) {
        s = 'S';
    } else {
        s = ' ';
    }

    if (blankx != 0) {
        d = 'D';
    } else {
        d = ' ';
    }

    while (1) {
        cout << "                          (" << w << ")\n";
        cout << "Enter WASD (or QUIT): (" << a << ") (" << s << ") (" << d << ")\n";
        cout << "> ";
        string response = "";
        getline(cin, response);
        transform(response.begin(), response.end(), response.begin(), ::toupper);
        if (response == "QUIT") {
            exit(0);
        }
        for (char c : response) {
            if (c == w || c == a || c == s || c == d) {
                return response;
            }
        }

    }
}

void makeMove(vector<vector<string>>& board, string& move, int& bx, int& by) {
    // Carry out the given move on the given board.
    // Note : This function assumes that the move is valid.
    findBlankSpace(board, bx, by);
    if (move == "W") {
        swap(board[bx][by], board[bx][by + 1]);
    } else if (move == "A") {
        swap(board[bx][by], board[bx + 1][by]);
    } else if (move == "S") {
        swap(board[bx][by], board[bx][by - 1]);
    } else if (move == "D") {
        swap(board[bx][by], board[bx - 1][by]);
    }
}

void makeRandomMove(vector<vector<string>>& board) {
    // Perform a slide in a random direction.
    int blankx = -1, blanky = -1;
    findBlankSpace(board, blankx, blanky);
    vector<string> validMoves;
    if (blanky != 3) {
        validMoves.push_back("W");
    }
    if (blankx != 3) {
        validMoves.push_back("A");
    }
    if (blanky != 0) {
        validMoves.push_back("S");
    }
    if (blankx != 0) {
        validMoves.push_back("D");
    }
    int start = 0;
    int end = validMoves.size() - 1;

    // Create a random number generator engine
    std::random_device rd;  // Seed the random number generator
    std::mt19937 gen(rd()); // Mersenne Twister PRNG engine
    std::uniform_int_distribution<int> distribution(start, end); // Define the range
    // Generate a random number between 1 and 100
    int random_number = distribution(gen);

    //int x = rand() % (end - start + 1) + start; // Ðåàëèçîâàòü ñëó÷àíîå ÷èñëî
    string choice = validMoves[random_number];
    makeMove(board, choice, blankx, blanky);
}

vector<vector<string>> getNewPuzzle(int moves = 200) {
    // Get a new puzzle by making random slides from a solved state.
    vector<vector<string>> board = getNewBoard();
    for (int i = 0; i < 200; ++i) {
        makeRandomMove(board);
    }
    return board;
}


int main() {
    cout << "Sliding Tile Puzzle\n";
    cout << "Use the WASD keys to move the tiles\n";
    cout << "back into their original order:\n";
    cout << " 1  2  3  4\n 5  6  7  8\n 9 10 11 12\n13 14 15   \n";

    cout << "Press Enter to begin...\n";
    string str;
    getline(cin, str);
    vector<vector<string>> gameBoard = getNewPuzzle();
    while (1) {
        displayBoard(gameBoard);
        string playerMove = askForPlayerMove(gameBoard);
        int x, y;
        findBlankSpace(gameBoard, x, y);
        makeMove(gameBoard, playerMove, x, y);
        if (gameBoard == getNewBoard()) {
            cout << "You won!";
            return 0;
        }
    }

    return 0;
}
