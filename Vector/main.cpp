#include "Coordinates.h"

int main (int argc, const char **argv)
{
    const int winWidth  = 1280;
    const int winHeight = 720;

    SetTargetFPS (60);

    InitWindow (winWidth, winHeight, "Vectors");
    
    Vector vec       {100, 100};
    Vector click_pos {20, 20};

    Vector   zero_L {winWidth / 4,     winHeight / 2};
    CoordSys left   {zero_L, winWidth / 5,  winHeight / 5 * 2};

    Vector   zero_R {winWidth * 3 / 4, winHeight / 2};
    CoordSys right  {zero_R, winWidth / 10, winHeight / 5};
    
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        left.DrawAxes();
        left.DrawVector (-vec - vec.Normal() * 2);
        left.DrawVector (-vec, vec);

        right.DrawAxes();

        if (IsMouseButtonDown (MOUSE_BUTTON_LEFT))
        {
            click_pos.SetCoord (GetMouseX() - zero_R.GetX(), 
                                GetMouseY() - zero_R.GetY());
        }

        right.DrawVector (click_pos);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
