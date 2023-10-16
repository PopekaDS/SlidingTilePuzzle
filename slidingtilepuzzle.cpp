/*

import random, sys




def main():
    print('''Sliding Tile Puzzle, by Al Sweigart al@inventwithpython.com

    Use the WASD keys to move the tiles
    back into their original order:
           1  2  3  4
           5  6  7  8
           9 10 11 12
          13 14 15   ''')
    input('Press Enter to begin...')

    gameBoard = getNewPuzzle()

    while True:
        displayBoard(gameBoard)
        playerMove = askForPlayerMove(gameBoard)
        makeMove(gameBoard, playerMove)

        if gameBoard == getNewBoard():
            print('You won!')
            sys.exit()





def makeMove(board, move):
    """Carry out the given move on the given board."""
    # Note: This function assumes that the move is valid.
    bx, by = findBlankSpace(board)

    if move == 'W':
        board[bx][by], board[bx][by+1] = board[bx][by+1], board[bx][by]
    elif move == 'A':
        board[bx][by], board[bx+1][by] = board[bx+1][by], board[bx][by]
    elif move == 'S':
        board[bx][by], board[bx][by-1] = board[bx][by-1], board[bx][by]
    elif move == 'D':
        board[bx][by], board[bx-1][by] = board[bx-1][by], board[bx][by]


def makeRandomMove(board):
    """Perform a slide in a random direction."""
    blankx, blanky = findBlankSpace(board)
    validMoves = []
    if blanky != 3:
        validMoves.append('W')
    if blankx != 3:
        validMoves.append('A')
    if blanky != 0:
        validMoves.append('S')
    if blankx != 0:
        validMoves.append('D')

    makeMove(board, random.choice(validMoves))


def getNewPuzzle(moves=200):
    """Get a new puzzle by making random slides from a solved state."""
    board = getNewBoard()

    for i in range(moves):
        makeRandomMove(board)
    return board


# If this program was run (instead of imported), run the game:
if __name__ == '__main__':
    main()

*/

// Sliding Tile Puzzle, by Al Sweigart al@inventwithpython.com
// Slide the numbered tiles into the correct order.
// This code is available at https ://nostarch.com/big-book-small-python-programming


#include <iostream>
#include <vector>
#include <string>
using namespace std;

string BLANK = "  "; // Note: This string is two spaces, not one.

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

char askForPlayerMove(vector<vector<string>>& board) {
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
        string response = ""; // Сделать upper
        getline(cin, response);
        if (response == "QUIT") {
            // реализовать завершение программы
        }


        /*
        if response in(w + a + s + d).replace(' ', '') :
            return response
        



        w = 'W'
a = 'A'
s = 'S'
d = 'D'

response = input('> ').upper()
print(w + a + s + d)
if response in (w + a + s + d).replace(' ', ''):
    print(response)

print('YYY')



        */

    }
}


int main() {




    vector<vector<string>> tmp = getNewBoard();
    displayBoard(tmp);
    int x = -1, y = -1;
    findBlankSpace(tmp, x, y);


    return 0;
}