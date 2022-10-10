#include <iostream>
#include "Button.h"

int main()
{
    const int winWidth  = 1280;
    const int winHeight = 720;

    InitWindow(winWidth, winHeight, "GUI");

    BtnSwitch btn { winWidth / 2, winHeight / 2 };

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground (BLACK);
        if (IsMouseButtonPressed (MOUSE_LEFT_BUTTON))
        {
            if (btn.Overlaps (GetMouseX(), GetMouseY()))
            {
                btn.OnClick ("JOJO");
            }
        }

        btn.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
