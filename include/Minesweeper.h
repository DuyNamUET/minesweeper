#include <bits/stdc++.h>
#include <stdlib.h>

// using namespace std;

#define MAX_MINE 99
#define MAX_SIDE 25
#define MAX_MOVE 526 //pow(MAX_SIDE, 2)-MAX_MINE

class Minesweeper
{
public:
    int side; // size of level
    int mine; // number of mines
    
    void clear();
    void play();
    void chooseLevel();
    void makeMove(int* x, int* y);
    void printBoard(char board[][MAX_SIDE]);
    void placeMines(int mines[][2], char real_board[][MAX_SIDE]);
    void initialize(char board[][MAX_SIDE], char real_board[][MAX_SIDE]);
    void replaceMines(int row, int col, char board[][MAX_SIDE]);
    
    int countAdjacent(int row, int col, int mines[][2], char real_board[][MAX_SIDE]);
    
    bool isValid(int row, int col);
    bool isMine(int row, int col, char board[][MAX_SIDE]);
    bool playMinesUntil(char board[][MAX_SIDE], char real_board[][MAX_SIDE], int mines[][2], int row, int col, int* move_left);
    
};