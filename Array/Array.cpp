#include "Array.h"
#include <stdexcept>

elem_t& Array::operator[] (const int idx) const
{
	if (idx > cap_ || idx < 0)
	{
		throw (std::out_of_range ("Array idx out of bounds"));
	}

	return data_[idx];
}

// --------------- < operators +, += > -----------------

Array& Array::operator+= (const Array &arr)
{
	if (cap_ != arr.GetCap())
	{
		throw (std::runtime_error ("Array capacities don't match"));
	}

	for (int idx = 0; idx < cap_; idx++)
	{
		data_[idx] += arr[idx];
	}

	return *this;
}

Array Array::operator+ (const Array &arr) const
{
	Array res_arr = Array { arr };

	res_arr += *this;

	return res_arr;
}

// --------------- < operators -, -= > -----------------

Array& Array::operator-= (const Array &arr)
{
	if (cap_ != arr.GetCap())
	{
		throw (std::runtime_error ("Array capacities don't match"));
	}

	for (int idx = 0; idx < cap_; idx++)
	{
		data_[idx] -= arr[idx];
	}

	return *this;
}

Array Array::operator- (const Array &arr) const
{
	Array res_arr = Array { arr };

	res_arr -= *this;

	return res_arr;
}

// --------------- < operators *, *= > -----------------

Array& Array::operator*= (const float scale)
{
	for (int idx = 0; idx < cap_; idx++)
	{
		data_[idx] *= scale;
	}

	return *this;
}

Array operator* (const Array& arr, const float scale)
{
	Array res_arr = Array { arr };

	res_arr *= scale;

	return res_arr;
}

// --------------- < operators /, /= > -----------------

Array& Array::operator/= (const float scale)
{
	for (int idx = 0; idx < cap_; idx++)
	{
		data_[idx] /= scale;
	}

	return *this;
}

Array operator/ (const Array& arr, const float scale)
{
	Array res_arr = Array { arr };

	res_arr /= scale;

	return res_arr;
}