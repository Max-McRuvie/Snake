#ifndef CONFIG_H
#define CONFIG_H

// screen clearing configuration
#define USE_CLS_ON_WINDOWS 1
#define USE_CLEAR_ON_UNIX 1

// same screen size configuration
#define ROW 10
#define COL 15

// frame rate and movement configuration
#define FRAME_DELAY 100            // Frame delay in milliseconds
#define MOVE_INTERVAL 2           // Move every 2 frames for controlled speed

// symbol configurations
#define PLAYER_SYMBOL '$'
#define COLLECTABLE_SYMBOL 'F'
#define BORDER_SYMBOL 'X'
#define EMPTY_SPACE ' '

#endif // CONFIG_H