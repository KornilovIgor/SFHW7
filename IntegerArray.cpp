#include "IntegerArray.h"

IntegerArray::IntegerArray(int length) : _length(length)
{
	if (length < 0)
	{
		throw "array size is less than zero";
	}
	else
	{
		_data = new int[length] {};
	}
}