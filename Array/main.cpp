#include <iostream>
#include "Array.h"

int main (int argc, char *const *argv)
{
	Array arr { 5, 4 };

	arr[3] = 67;

	std::cout << arr[2] << '\n';
	std::cout << arr[3] << '\n';
	std::cout << arr[4] << '\n';

	Array jojo = arr + arr * 0.01;

	std::cout << jojo[2] << '\n';
	std::cout << jojo[3] << '\n';
	std::cout << jojo[4] << '\n';

	jojo -= Array { 5, 0.4 } / 4;

	std::cout << jojo[2] << '\n';
	std::cout << jojo[3] << '\n';
	std::cout << jojo[4] << '\n';

	return 0;
}