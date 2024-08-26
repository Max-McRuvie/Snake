#include <stdio.h>
#include <stdbool.h> 
#include <windows.h>
#include "config.h"
#include "grid.h"
#include "clear_screen.h"

int main(){
    char grid[ROW][COL];
    create_border(grid);

    while(true){
        ClrScr();
        print_grid(grid);

        Sleep(3000);
    }
    
    return 0;
}