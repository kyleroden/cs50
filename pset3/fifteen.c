/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */

#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();

        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }

    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).
 */
void init(void)
{
    // TODO
    int tile_num = (d * d) - 1;
    for(int i = 0; i < d; i++)
    {
        for(int j = 0; j < d; j++)
        {
            //start with the highest number, which would be 8 in a 3x3
            if(d % 2 ==0 && tile_num == 2)
            {
                board[i][j] = 1;
                --tile_num;
            }
            else if(d % 2 ==0 && tile_num == 1)
            {
                board[i][j] = 2;
                --tile_num;
            }
            else
            {
                board[i][j] = tile_num;
                --tile_num;
            }

        }
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // TODO
    for(int i = 0; i < d; i++)
    {
        for(int j = 0; j < d; j++)
        {
            if(board[i][j] < 1)
            {
                printf("%s", "_");
            }
            else
            {
                printf("%d", board[i][j]);
            }
        }
        printf("\n");
    }

}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false.
 */
bool move(int tile)
{
    //variables which will store the location of the blank tile
    int blank_column;
    int blank_row;

    //variables to store the location of our tile
    int tile_column;
    int tile_row;

    //find the blank tile and store its position
    for(int k = 0; k < d; k++)
    {
        for(int y = 0; y < d; y++)
        {
            if(board[k][y] == 0)
            {
                blank_row = k;
                blank_column = y;
            }
        }
    }
    // iterate through all of the board's positions to find the tile which the user wants to move
    for(int i = 0; i < d; i++)
    {
        for(int j = 0; j < d; j++)
        {
            //check if this particular position has the wanted tile
            if(board[i][j] == tile)
            {
                //found the tile.
                tile_row = i;
                tile_column = j;

                //then check that the user's requested tile can be moved
                if((tile_column + 1 == blank_column && tile_row == blank_row) || (tile_column - 1 == blank_column && tile_row == blank_row) || (tile_row - 1 == blank_row && tile_column == blank_column) || (tile_row + 1 == blank_row && tile_column == blank_column))
                {
                    //make a temp variable, to store THE tile being moved
                    int tmp = board[tile_row][tile_column];
                    //then 'move' tile by storing the location of the blank tile into THE tile's location
                    board[tile_row][tile_column] = board[blank_row][blank_column];
                    board[blank_row][blank_column] = tmp;
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration),
 * else false.
 */
bool won(void)
{
    // TODO
    return false;
}
