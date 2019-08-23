#include "Minesweeper.h"

// Minesweeper minesweeper;

void Minesweeper::clear()
{
    system("clear");
}

bool Minesweeper::isValid(int row, int col)
{
    return row >= 0 && row < this->side
        && col >= 0 && col < this->side;
}

bool Minesweeper::isMine(int row, int col, char board[][MAX_SIDE])
{
    if(board[row][col] == '*') return true;
    else return false;
}

void Minesweeper::makeMove(int* x, int* y)
{
    printf("Your move (row, column): ");
    scanf("%d %d", x, y);
}

void Minesweeper::printBoard(char board[][MAX_SIDE])
{
    printf("\t\t\t");

    for(int i = 0; i < this->side; i++)
    {
        if(i > 9) printf("%d ", i / 10);
        else printf("  ");
    }

    printf("\n\t\t\t");

    for(int i = 0; i < this->side; i++)
    {
        printf("%d ", i % 10);
    }

    printf("\n\n");

    for(int i = 0; i < this->side; i++)
    {
        printf("\t\t\t");
        for(int j = 0; j < this->side; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf(" %2d", i);
        printf("\n");
    }

}

int Minesweeper::countAdjacent(int row, int col, int mines[][2], char real_board[][MAX_SIDE])
{
    int count = 0;
    if(this->isValid(row-1, col))
    {
        if(this->isMine(row-1, col, real_board)) count++;
    }

    if(this->isValid(row+1, col))
    {
        if(this->isMine(row+1, col, real_board)) count++;
    }

    if(this->isValid(row, col-1))
    {
        if(this->isMine(row, col-1, real_board)) count++;
    }

    if(this->isValid(row, col+1))
    {
        if(this->isMine(row, col+1, real_board)) count++;
    }

    if(this->isValid(row-1, col-1))
    {
        if(this->isMine(row-1, col-1, real_board)) count++;
    }

    if(this->isValid(row-1, col+1))
    {
        if(this->isMine(row-1, col+1, real_board)) count++;
    }

    if(this->isValid(row+1, col-1))
    {
        if(this->isMine(row+1, col-1, real_board)) count++;
    }

    if(this->isValid(row+1, col+1))
    {
        if(this->isMine(row+1, col+1, real_board)) count++;
    }

    return count;
}

bool Minesweeper::playMinesUntil(char board[][MAX_SIDE], char real_board[][MAX_SIDE], int mines[][2], int row, int col, int* move_left)
{
    if(board[row][col] != '-') return false;

    int i, j;
    if(real_board[row][col] == '*')
    {
        board[row][col] = '*';
        for(i = 0; i < this->mine; i++)
        {
            board[mines[i][0]][mines[i][1]] = '*';
        }
        this->printBoard(board);
        printf("\nEnd Game\n");
        return true;
    }
    else
    {
        int count = this->countAdjacent(row, col, mines, real_board);
        (*move_left)--;
        board[row][col] = count + '0';

        if(!count)
        {
            if(this->isValid(row-1, col))
            {
                if(!this->isMine(row-1, col, real_board))
                {
                    this->playMinesUntil(board, real_board, mines, row-1, col, move_left);
                }
            }

            if(this->isValid(row+1, col))
            {
                if(!this->isMine(row+1, col, real_board))
                {
                    this->playMinesUntil(board, real_board, mines, row+1, col, move_left);
                }
            }

            if(this->isValid(row, col-1))
            {
                if(!this->isMine(row, col-1, real_board))
                {
                    this->playMinesUntil(board, real_board, mines, row, col-1, move_left);
                }
            }

            if(this->isValid(row, col+1))
            {
                if(!this->isMine(row, col+1, real_board))
                {
                    this->playMinesUntil(board, real_board, mines, row, col+1, move_left);
                }
            }

            if(this->isValid(row-1, col-1))
            {
                if(!this->isMine(row-1, col-1, real_board))
                {
                    this->playMinesUntil(board, real_board, mines, row-1, col-1, move_left);
                }
            }

            if(this->isValid(row-1, col+1))
            {
                if(!this->isMine(row-1, col+1, real_board))
                {
                    this->playMinesUntil(board, real_board, mines, row-1, col+1, move_left);
                }
            }

            if(this->isValid(row+1, col-1))
            {
                if(!this->isMine(row+1, col-1, real_board))
                {
                    this->playMinesUntil(board, real_board, mines, row+1, col-1, move_left);
                }
            }

            if(this->isValid(row+1, col+1))
            {
                if(!this->isMine(row+1, col+1, real_board))
                {
                    this->playMinesUntil(board, real_board, mines, row+1, col+1, move_left);
                }
            }
        }
        return false;
    }
}

void Minesweeper::placeMines(int mines[][2], char real_board[][MAX_SIDE])
{
    bool mark[MAX_SIDE * MAX_SIDE];
    memset(mark, false, sizeof(mark));

    for(int i = 0; i < this->mine;)
    {
        int random = rand() % (this->side * this->side);
        int x = random / this->side;
        int y = random % this->side;

        if(!mark[random])
        {
            mines[i][0] = x;
            mines[i][1] = y;

            real_board[mines[i][0]][mines[i][1]] = '*';
            mark[random] = true;
            i++;
        }
    }
}

void Minesweeper::initialize(char board[][MAX_SIDE], char real_board[][MAX_SIDE])
{
    srand(time(NULL));

    for(int i = 0; i < this->side; i++)
    {
        for(int j = 0; j < this->side; j++)
        {
            board[i][j] = real_board[i][j] = '-';
        }
    }
}

void Minesweeper::cheatMines(char real_board[][MAX_SIDE])
{
    this->clear();
    printf("Mines's location:\n");
    this->printBoard(real_board);
}

void Minesweeper::replaceMines(int row, int col, char board[][MAX_SIDE])
{
    for(int i = 0; i < this->side; i++)
    {
        for(int j = 0; j < this->side; j++)
        {
            if(board[i][j] != '*')
            {
                board[i][j] = '*';
                board[row][col] = '-';
                return;
            }
        }
    }
}

void Minesweeper::play()
{
    bool game_over = false;

    char real_board[MAX_SIDE][MAX_SIDE];
    char board[MAX_SIDE][MAX_SIDE];

    int move_left = this->side * this->side - this->mine;
    int x, y;
    int mines[MAX_MINE][2];

    this->initialize(board, real_board);

    this->placeMines(mines, real_board);

    int current_move_index = 0;

    while(!game_over)
    {
        this->clear();
        printf("Current Board:\n");
        this->printBoard(board);
        this->makeMove(&x, &y);

        if(current_move_index == 0)
        {
            if(this->isMine(x, y, real_board))
            {
                this->replaceMines(x, y, real_board);
            }
        }

        current_move_index++;

        game_over = this->playMinesUntil(board, real_board, mines, x, y, &move_left);

        if(!game_over && move_left == 0)
        {
            printf("\nWIN\n");
            game_over = true;
        }
    }
}

void Minesweeper::chooseLevel()
{
    this->clear();
    printf("\n\t\t\t\t\t\tMINESWEEPER");
    printf("\n\n\t\t\tCHOOSE LEVEL:");
    printf("\n\n\t\t\t0. Easy");
    printf("\n\n\t\t\t1. Medium");
    printf("\n\n\t\t\t2. Hard");
    printf("\n\n\t\t\tYou choose (0-2): ");

    int choice;
    std::cin >> choice;
    if(choice == 0)
    {
        this->mine = 9;
        this->side = 10;
    }
    else if(choice == 1)
    {
        this->mine = 40;
        this->side = 16;
    }
    else if(choice == 2)
    {
        this->mine = 99;
        this->side = 25;
    }
    else exit(0);
}