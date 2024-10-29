#include "grid.h"
#include "player.h"
#include "config.h"
#include <stdio.h>
#include <stdbool.h> 
#include <windows.h>

// Function to initialize the player's position on the grid
void initialise_player(char grid[ROW][COL], int player_row, int player_col) {
    grid[player_row][player_col] = PLAYER_SYMBOL;  // Place player at the initial position
}

// Function to get the new direction based on keyboard input
Direction get_new_direction(Direction current_direction) {
    if (GetAsyncKeyState('W') & 0x8000 && current_direction != DOWN)  return UP;    // Move up
    if (GetAsyncKeyState('S') & 0x8000 && current_direction != UP)    return DOWN;  // Move down
    if (GetAsyncKeyState('A') & 0x8000 && current_direction != RIGHT) return LEFT;  // Move left
    if (GetAsyncKeyState('D') & 0x8000 && current_direction != LEFT)  return RIGHT; // Move right
    return current_direction;  // No change if no valid key press
}

// Function to update row and column based on direction
void move_in_direction(int* new_row, int* new_col, Direction direction) {
    switch (direction) {
        case UP:    (*new_row)--; break;
        case DOWN:  (*new_row)++; break;
        case LEFT:  (*new_col)--; break;
        case RIGHT: (*new_col)++; break;
    }
}

// Helper function to check if a move is valid (not a wall)
bool is_valid_move(char grid[ROW][COL], int row, int col) {
    // Ensure row and col are within bounds and not hitting the wall
    if (row < 0 || row >= ROW || col < 0 || col >= COL) {
        return false;
    }
    return grid[row][col] != BORDER_SYMBOL;
}

// Helper function to update the player's position on the grid
void update_player_position(char grid[ROW][COL], int* player_row, int* player_col, int new_row, int new_col, int* score) {
    if (grid[new_row][new_col] == COLLECTABLE_SYMBOL) {
        (*score)++;  // Increment score for collecting an item
        spawn_collectible(grid);  // Spawn a new collectible
    }

    // Clear the old player position
    grid[*player_row][*player_col] = EMPTY_SPACE;
    // Update the player's new position
    *player_row = new_row;
    *player_col = new_col;
    grid[*player_row][*player_col] = PLAYER_SYMBOL;  // Place the player at the new position
}

// Main function to move the player
void move_player(char grid[ROW][COL], int* player_row, int* player_col, int* score, Direction* current_direction) {
    int new_row = *player_row;
    int new_col = *player_col;

    // Update the direction based on input, if any
    //*current_direction = get_new_direction(*current_direction);

    // Move in the current direction
    move_in_direction(&new_row, &new_col, *current_direction);

    // If the move is valid, update the player's position
    if (is_valid_move(grid, new_row, new_col)) {
        update_player_position(grid, player_row, player_col, new_row, new_col, score);
    }
}