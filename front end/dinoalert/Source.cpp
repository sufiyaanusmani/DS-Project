#include "raylib.h"
#include <iostream>


int main() {
    int w = 1440, h = 800;

    InitWindow(w, h, "yousuf ");


    //----------------------------------------------------------------   TEXTURES   ---------------------------------------


    //---------------------------------------------------------------------------------------------------------------------

    SetTargetFPS(60);
    //ToggleFullscreen();

    while (!WindowShouldClose()) {




        

        BeginDrawing();
        ClearBackground(RAYWHITE);


        EndDrawing();
    }
    CloseWindow();
    return 0;
}