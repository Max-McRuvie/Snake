#include "clear_screen.h"
#include "config.h"
#include <stdio.h>
#include <windows.h>

void ClrScr() {
    #ifdef _WIN32
        #if USE_CLS_ON_WINDOWS
        if (system("cls") != 0) {
            // If cls fails (unlikely on native Windows), fall back to clear
            system("clear");
        }
        #else
        system("clear"); // Just use clear if USE_CLS_ON_WINDOWS is 0
        #endif
    #else
        #if USE_CLEAR_ON_UNIX
        if (system("clear") != 0) {
            // If clear fails, fall back to cls
            system("cls");
        }
        #else
        system("cls"); // Just use cls if USE_CLEAR_ON_UNIX is 0
        #endif
    #endif
}