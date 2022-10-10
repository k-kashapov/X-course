#include "Button.h"

int Button::Draw()
{
    return Draw (pos_.GetX(), pos_.GetY());
}

int Button::Draw (int x, int y)
{
    Draw (x, y, width_, height_);
    return 0;
}

int Button::Draw (int x, int y, int width, int height)
{
    Color btnColor = state_ ? BLUE : RAYWHITE;
    DrawRectangle (x, y, width, height, btnColor);
    return 0;
}

bool Button::Overlaps (int x, int y)
{
	return 
	(
		x > pos_.GetX()           &&
		x < pos_.GetX() + width_  &&
		y > pos_.GetY()           &&
		y < pos_.GetY() + height_
	);
}

bool Button::Overlaps (const Vector& pos)
{
	return Overlaps (pos.GetX(), pos.GetY());
}
