#ifndef PLAYER_H
#define PLAYER_H

#include "grid.h"
#include "player.h"
#include "config.h"
#include <stdio.h>
#include <stdbool.h> 
#include <windows.h>

typedef enum {UP, DOWN, LEFT, RIGHT} Direction;

typedef struct {
    int row;
    int col;
} Position;

void initialise_player(char grid[ROW][COL], int player_row, int player_col);

Direction get_new_direction(Direction current_direction);

void move_in_direction(int* new_row, int* new_col, Direction direction);

bool is_valid_move(char grid[ROW][COL], int row, int col);

void update_player_position(char grid[ROW][COL], int* player_row, int* player_col, int new_row, int new_col, int* score);

void move_player(char grid[ROW][COL], int* player_row, int* player_col, int* score, Direction* current_direction);

#endif