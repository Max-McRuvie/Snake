#include "grid.h"
#include "config.h"
#include <stdio.h>
#include <stdbool.h> 
#include <windows.h>

// Function to initialize the player's position on the grid
void initialise_player(char grid[ROW][COL], int player_row, int player_col) {
    grid[player_row][player_col] = '$';  // Place player at the initial position
}

// Function to get the new position based on keyboard input
void get_new_position(int* new_row, int* new_col) {
    if (GetAsyncKeyState('W') & 0x8000) (*new_row)--; // Move up
    if (GetAsyncKeyState('S') & 0x8000) (*new_row)++; // Move down
    if (GetAsyncKeyState('A') & 0x8000) (*new_col)--; // Move left
    if (GetAsyncKeyState('D') & 0x8000) (*new_col)++; // Move right
}

// Helper function to check if a move is valid (not a wall)
bool is_valid_move(char grid[ROW][COL], int* row, int* col) {
    return grid[*row][*col] != BORDER_SYMBOL;  // Check if the position is not a wall
}

// Helper function to update the player's position on the grid
void update_player_position(char grid[ROW][COL], int* player_row, int* player_col, int new_row, int new_col, int* score) {
    if (grid[new_row][new_col] == COLLECTABLE_SYMBOL) {
        (*score)++;  // Increment score for collecting an item
        spawn_collectible(grid);  // Spawn a new collectible
    }

    // Clear the old player position
    grid[*player_row][*player_col] = ' ';
    // Update the player's new position
    *player_row = new_row;
    *player_col = new_col;
    grid[*player_row][*player_col] = '$';  // Place the player at the new position
}

// Main function to move the player
void move_player(char grid[ROW][COL], int* player_row, int* player_col, int* score) {
    int new_row = *player_row;
    int new_col = *player_col;

    get_new_position(&new_row, &new_col);  // Get the new position based on input

    // If the move is valid, update the player's position
    if (is_valid_move(grid, &new_row, &new_col)) {
        update_player_position(grid, player_row, player_col, new_row, new_col, score);
    }
}