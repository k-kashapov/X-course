#include "Coordinates.h"

const double EPSILON = 1e-9;

bool doubleEqual (double a, double b)
{
	return fabs (a - b) < EPSILON;
}
