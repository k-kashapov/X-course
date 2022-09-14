#include "Coordinates.h"

void CoordSys::DrawVector (const Vector& start_pos, const Vector& end_pos) const
{
    double start_x = start_pos.GetX() + zero_x_,
           start_y = start_pos.GetY() + zero_y_;

    double end_x = end_pos.GetX() + zero_x_,
           end_y = end_pos.GetY() + zero_y_;

    double diff_x = end_x - start_x,
           diff_y = end_y - start_y;

    double diff_len = sqrt (diff_x * diff_x + diff_y * diff_y) * 0.1;

    diff_x /= diff_len;
    diff_y /= diff_len;

    // Base line
    DrawLine 
    (
        start_x, start_y,
        end_x,   end_y,
        BLACK
    );

    // end_x - diff_x / len - diff_y / len, end_y - diff_y / len + diff_x / len

    // First arrow wing
    DrawLine 
    (
        end_x - diff_x - diff_y, end_y - diff_y + diff_x,
        end_x,                   end_y,
        BLACK
    );

    // Second arrow wing
    DrawLine 
    (
        end_x - diff_x + diff_y, end_y - diff_y - diff_x,
        end_x,                   end_y,
        BLACK
    );
}

void CoordSys::DrawVector (const Vector& vec) const
{
    DrawVector (Vector {0, 0}, vec);
}

void CoordSys::DrawAxes (double len_x, double len_y) const
{
    DrawVector
    (
        Vector {-len_x, 0}, 
        Vector { len_x, 0}
    );

    DrawVector 
    (
        Vector {0, -len_y}, 
        Vector {0,  len_y}
    );

    DrawText ("x", zero_x_ + len_x, zero_y_,         30, DARKGREEN);
    DrawText ("y", zero_x_,         zero_y_ + len_y, 30, DARKGREEN);
}

void CoordSys::DrawAxes (void) const
{
    DrawAxes (width_, height_);
}
