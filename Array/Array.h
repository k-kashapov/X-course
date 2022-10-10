#ifndef ARRAY_H
#define ARRAY_H

typedef float elem_t;

class Array
{
private:
	int cap_;
	elem_t *data_;

public:
	Array(int init_cap):
		cap_  (init_cap),
		data_ (new elem_t[init_cap])
	{}

	Array(int init_cap, elem_t init_val):
		cap_  (init_cap),
		data_ (new elem_t[init_cap])
	{
		for (int idx = 0; idx < init_cap; idx++)
		{
			data_[idx] = init_val;
		}
	}

	Array(const Array& arr):
		cap_  (arr.GetCap()),
		data_ (new elem_t[cap_])
	{
		for (int idx = 0; idx < cap_; idx++)
		{
			data_[idx] = arr[idx];
		}
	}

	~Array()
	{
		delete[] data_;
	}

	inline int GetCap() const
	{
		return cap_;
	}

	elem_t& operator[] (const int   idx)   const;
	Array   operator+  (const Array &arr)  const;
	Array   operator-  (const Array &arr)  const;
	
	Array&  operator+= (const Array &arr);
	Array&  operator-= (const Array &arr);
	Array&  operator*= (const float scale);
	Array&  operator/= (const float scale);
};

Array operator* (const Array& arr, const float scale);
Array operator/ (const Array& arr, const float scale);

#endif // ARRAY_H
