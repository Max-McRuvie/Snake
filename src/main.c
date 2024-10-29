#include <stdio.h>
#include <stdbool.h> 
#include <windows.h>
#include "config.h"
#include "grid.h"
#include "clear_screen.h"
#include "player.h"

int main(){
    char grid[ROW][COL];
    int player_row = 5, player_col = 5;  // Starting position of the player
    static int score = 0;

    // Initialize the grid
    create_border(grid);
    initialise_player(grid, player_row, player_col);
    spawn_collectible(grid);

    // Game loop
    while (1) {
        ClrScr();  // Clear the terminal for smoother output (Windows specific)
        render_game(grid, score);  // Display the updated grid
        move_player(grid, &player_row, &player_col, &score);  // Pass player position by pointer
        Sleep(100);  // Delay for smoother movement
    }

    return 0;
}