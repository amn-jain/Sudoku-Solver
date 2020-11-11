#include<iostream>
using namespace std;

void display_board(int **Board, int rows, int columns){
    
    for(int i = 0; i < rows; i++)
    {
        if(i%3 == 0 && i != 0)
        {
            cout << "----------------------" << endl;
        }
        for(int j = 0; j < columns; j++)
        {
            if(j%3 == 0 && j != 0)
            {
                cout << "| ";
            }
            if(j != columns - 1)
            {
                cout << Board[i][j] << " ";
            }
            else
            {
                cout << Board[i][j] << endl;
            }
        }
    }
}

int * find_empty(int **Board, int rows, int columns)
{
    int *Pos = (int *)malloc(2*sizeof(int));
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if(Board[i][j] == 0)
            {
                Pos[0] = i;
                Pos[1] = j;
                return Pos;
            }
        }
    }
    return NULL;
}

bool valid(int **Board, int Num, int *Pos, int rows, int columns)
{
    // Check Row
    for(int i = 0; i < columns; i++)
    {
        if(Board[Pos[0]][i] == Num && Pos[1] != i)
        {
            return false;
        }
    }

    // Check Column
    for(int i = 0; i < rows; i++)
    {
        if(Board[i][Pos[1]] == Num && Pos[0] != i)
        {
            return false;
        }
    }

    // Check Box
    int Box_X = Pos[0]/3;
    int Box_Y = Pos[1]/3;
    for(int i = Box_X * 3; i < ((Box_X * 3) + 3); i++)
    {
        for(int j = Box_Y * 3; j < ((Box_Y * 3) + 3); j++)
        {
            if(Board[i][j] == Num && Pos[0] != i && Pos[1] != j)
            {
                return false;
            }
        }
    }

    return true;
}

bool Solve(int ***Board, int rows, int columns)
{
    int *Pos = (int *)malloc(2 * sizeof(int));
    Pos = find_empty(*Board, rows, columns);
    int row, col;
    if(Pos == NULL)
    {
        return true;
    }
    else
    {
        row = Pos[0];
        col = Pos[1];
    }
    
    for(int i = 1; i < 10; i++)
    {
        if(valid(*Board, i, Pos, rows, columns))
        {
            (*Board)[row][col] = i;
            if(Solve(Board, rows, columns))
            {
                return true;
            }
            (*Board)[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    int rows, columns;
    cout << "Enter the value of Rows and Columns." << endl;
    cin >> rows >> columns;
    int **Board = (int **)malloc(rows * sizeof(int *));
    for(int i = 0; i < 9; i++)
    {
        *(Board + i) = (int *)malloc(columns * sizeof(int));
    }
    for(int i = 0; i < rows; i++)
    {
        cout << "Enter the " << (i + 1) << " row of Sudoku" << endl;
        for(int j = 0; j < columns; j++)
        {
            cin >> Board[i][j];  
        }
    }

    display_board(Board, rows, columns);
    cout << endl << endl;
    Solve(&Board, rows, columns);
    display_board(Board, rows, columns);

    return 0;
}
