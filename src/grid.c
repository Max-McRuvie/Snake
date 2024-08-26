#include "grid.h"
#include "config.h"
#include <stdio.h>

// print grid to terminal
void print_grid(char grid[ROW][COL]){
    int i, j;
    printf("\n");
    for(i = 0; i < ROW; i++){
        printf("|");
        for(j = 0; j < COL; j++){
            printf(" %c  ", grid[i][j]);
        }
        printf("|");
        printf("\n");
    }
    fflush(stdout);
}

// create border around the grid
void create_border(char grid[ROW][COL]){
    int i, j;
    
    for(i = 0; i < ROW; i++){
        for(j = 0; j < COL; j++){
            if(i == 0 || i == ROW - 1){
                grid[i][j] = 'X';
            }
            else if (j == 0 || j == COL - 1)
            {
                grid[i][j] = 'X';
            }
            else {
                grid[i][j] = ' ';
            }
        }
    }
}