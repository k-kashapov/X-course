#include "Misc.h"

const double EPSILON = 1e-9;

bool doubleEqual (double a, double b)
{
	return std::fabs (a - b) < EPSILON;
}
