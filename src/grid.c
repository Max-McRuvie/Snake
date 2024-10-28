#include "grid.h"
#include "config.h"
#include <stdio.h>
#include <stdbool.h> 

// Function to render game in the terminal
void render_game(char grid[ROW][COL], int score){
    int i, j;
    printf("\n");
    printf("SCORE: %d\n", score);

    for(i = 0; i < ROW; i++){
        printf("|");
        for(j = 0; j < COL; j++){
            printf("%c ", grid[i][j]);
        }
        printf("|");
        printf("\n");
    }
    fflush(stdout);
}

// Function to create border around the grid
void create_border(char grid[ROW][COL]){
    int i, j;
    
    for(i = 0; i < ROW; i++){
        for(j = 0; j < COL; j++){
            if(i == 0 || i == ROW - 1){
                grid[i][j] = BORDER_SYMBOL;
            }
            else if (j == 0 || j == COL - 1)
            {
                grid[i][j] = BORDER_SYMBOL;
            }
            else {
                grid[i][j] = ' ';
            }
        }
    }
}

// Function to spawn collectible
void spawn_collectible(char grid[ROW][COL]){
    int row_max = ROW - 2;
    int col_max = COL - 2;
    int row_min = 2;
    int col_min = 2;

    int rd_num_row = rand() % (row_max - row_min + 1) + row_min;
    int rd_num_col = rand() % (col_max - col_min + 1) + col_min;

    bool finished = false;
    
    while(!finished){
        if(grid[rd_num_row][rd_num_col] == SNAKE_SYMBOL || grid[rd_num_row][rd_num_col] == COLLECTABLE_SYMBOL){
            rd_num_row = rand() % (row_max - row_min + 1) + row_min;
            rd_num_col = rand() % (col_max - col_min + 1) + col_min;
        } else {
            grid[rd_num_row][rd_num_col] = COLLECTABLE_SYMBOL;
            finished = true;
        }
    }
}
