#include "Coordinates.h"

int main (int argc, const char **argv)
{
    const int winWidth  = 1280;
    const int winHeight = 720;

    SetTargetFPS (60);

    InitWindow (winWidth, winHeight, "Vectors");

    Vector zero_L {winWidth / 4,     winHeight / 2};
    Vector zero_R {winWidth * 3 / 4, winHeight / 2};
    Vector vec  {100, 100};

    CoordSys left  (zero_L, winWidth / 5,  winHeight / 5 * 2);
    CoordSys right (zero_R, winWidth / 10, winHeight / 5);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        left.DrawAxes();
        left.DrawVector (-vec - vec.Normal() * 2);
        left.DrawVector (vec);

        right.DrawAxes();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
