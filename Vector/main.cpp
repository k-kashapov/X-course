#include "Vector.h"

int main (int argc, const char **argv)
{
	Vector vec {5, 12};
	Vector vec2{5, 12};

	std::cout << vec << " of len " << vec.GetLen();

	vec.SetCoord (3, 4);
	
	// std::cout << vec << " of len " << vec.GetLen();	

	vec = vec + vec + vec2;

	return 0;
}
