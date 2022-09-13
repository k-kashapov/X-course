#include <iostream>
#include "cmath"

class Vector
{
private:
	// len_ is updated only on demand
	double len_;
	double x_, y_;

public:
	Vector (double x, double y):
		len_ (NAN),
		x_   (x),
		y_   (y)
	{}

	~Vector ()
	{}

	void SetCoord (double x, double y)
	{
		x_   = x;
		y_   = y;
		len_ = NAN;

		return;
	}

	double CalcLen (void);

	double GetX (void) const
	{ 
		return x_;
	}

	double GetY (void) const
	{
		return y_; 
	}

	Vector operator+ (Vector val) const
	{
		return Vector (x_ + val.GetX(), y_ + val.GetY());
	}
};

std::ostream& operator<< (std::ostream& s, Vector& vec);
