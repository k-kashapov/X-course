#include "Coordinates.h"

// Quick reverse sqrt for float32. Copied from Quake III Arena.
static float Q_rsqrt (float number)
{
    int32_t i = 0;
    float x2 = NAN, y = NAN;

    x2 = number * 0.5F;
    y  = number;
    i  = *(int32_t *)&y;               // evil floating point bit level hacking
    i  = 0x5f3759df - (i >> 1);     // what the fuck? 
    y  = *(float *)&i;
    y  = y * (1.5f - (x2 * y * y)); // Newton's method

    return y;
}

void CoordSys::DrawVector (const Vector& start_pos, const Vector& end_pos) const
{
    if ((end_pos - start_pos).isZero())
    {
        return;
    }

    double start_x = start_pos.GetX() + zero_x_,
           start_y = start_pos.GetY() + zero_y_;

    double end_x = end_pos.GetX() + zero_x_,
           end_y = end_pos.GetY() + zero_y_;

    double diff_x = end_x - start_x,
           diff_y = end_y - start_y;

    double diff_len_inv_sqrt = (double) Q_rsqrt ((float) (diff_x * diff_x + diff_y * diff_y));

    diff_x *= diff_len_inv_sqrt * 10.f;
    diff_y *= diff_len_inv_sqrt * 10.f;

    // Base line
    DrawLine 
    (
        start_x, start_y,
        end_x,   end_y,
        BLACK
    );

    // First arrow wing
    DrawLine 
    (
        end_x - diff_x * 2 - diff_y, end_y - diff_y * 2 + diff_x,
        end_x,                   end_y,
        BLACK
    );

    // Second arrow wing
    DrawLine 
    (
        end_x - diff_x * 2 + diff_y, end_y - diff_y * 2 - diff_x,
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
