#ifndef GRID_H
#define GRID_H

#include "config.h"

void create_border(char grid[ROW][COL]);
void render_game(char grid[ROW][COL], int score);
void spawn_collectible(char grid[ROW][COL]);

#endif