#include "IntegerArray.h"
IntegerArray::IntegerArray(int length) : _length(length)
{
	if (length < 0)
	{
		throw "Array size is less than zero";
	}
	else
	{
		_data = new int[length] {};
	}
}

IntegerArray::~IntegerArray()
{
	delete[] _data;
}

void IntegerArray::erase()
{
	delete[] _data;
	_data = nullptr;
	_length = 0;
}

void IntegerArray::reallocate(int newLength)
{
	erase();

	if (newLength <= 0)
	{
		return;
	}

	_length = newLength;
	_data = new int[_length];
}

void IntegerArray::resize(int newLength)
{
	if (newLength = _length)
	{
		return;
	}
	else if (newLength <= 0)
	{
		erase();
		return;
	}

	int* data =	new int[newLength];

	if (_length > 0)
	{
		int elementsToCopy = { newLength > _length ? _length : newLength };

		for (int i = 0; i < elementsToCopy; ++i)
		{
			data[i] = _data[i];
		}
	}

	delete[] _data;

	_data = data;
	_length = newLength;

}

int& IntegerArray::operator[](int index)
{
	if (index < 0 || index >= _length)
	{
		throw "Invalid index";
	}
	return _data[index];
}
