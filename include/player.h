#ifndef PLAYER_H
#define PLAYER_H

void initialise_player(char grid[COL][ROW], int player_row, int player_col);
void get_new_position(int* new_col, int* new_row);
bool is_valid_move(char grid[ROW][COL], int* row, int* col);
void update_player_position(char grid[ROW][COL], int* player_row, int* player_col, int new_row, int new_col, int* score);
void move_player(char grid[ROW][COL], int* player_row, int* player_col, int* score);

#endif