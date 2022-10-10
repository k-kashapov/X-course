#ifndef COORDINATES_H
#define COORDINATES_H

#include "Vector.h"

class CoordSys
{
private:
	double zero_x_ = 0,   zero_y_ = 0;
	double width_  = 100, height_ = 100;

public:
	CoordSys()
	{}

	CoordSys (const double zero_x, const double zero_y):
		zero_x_ (zero_x),
		zero_y_ (zero_y)
	{}

	CoordSys (const double zero_x, const double zero_y,
			  const double width,  const double height):
		zero_x_ (zero_x),
		zero_y_ (zero_y),
		width_  (width),
		height_ (height)
	{}

	CoordSys (const Vector& zero,
			  const double width,  const double height):
		zero_x_ (zero.GetX()),
		zero_y_ (zero.GetY()),
		width_  (width),
		height_ (height)
	{}

	CoordSys (const Vector& zero, const Vector& size):
		zero_x_ (zero.GetX()),
		zero_y_ (zero.GetY()),
		width_  (size.GetX()),
		height_ (size.GetY())
	{}

	CoordSys (const Vector& zero):
		zero_x_ (zero.GetX()),
		zero_y_ (zero.GetY())
	{}

	~CoordSys()
	{}

	int  AddVector  (const Vector* vec);
	void DrawVector (const Vector& start_pos, const Vector& vec) const;
	void DrawVector (const Vector& vec) const;
	void DrawAxes   (double len_x, double len_y) const;
	void DrawAxes   (void) const;
};

#endif // COORDINATES_H
