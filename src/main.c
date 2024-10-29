#include <stdio.h>
#include <stdbool.h> 
#include <windows.h>
#include "config.h"
#include "grid.h"
#include "clear_screen.h"
#include "player.h"

int main() {
    char grid[ROW][COL];
    int player_row = 5, player_col = 5, score = 0;
    Direction current_direction = RIGHT;  // Initial direction
    

    // Initialize the grid
    create_border(grid);
    initialise_player(grid, player_row, player_col);
    spawn_collectible(grid);

    int frame_counter = 0;

    // Game loop
    while (1) {
        ClrScr();  // Clear the terminal for smoother output (Windows-specific)
        render_game(grid, score);  // Display the updated grid

        // Update direction based on input
        current_direction = get_new_direction(current_direction);

        // Move player every 'move_interval' frames
        if (FRAME_DELAY % MOVE_INTERVAL == 0) {
            move_player(grid, &player_row, &player_col, &score, &current_direction);
        }

        frame_counter++;
        Sleep(FRAME_DELAY);  // Short delay for more responsive controls
    }

    return 0;
}