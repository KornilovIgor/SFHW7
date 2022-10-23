#pragma once

class IntegerArray
{
private:
	int _length = 0;
	int* _data = 0;

public:
	IntegerArray() = default;
	IntegerArray(int length);
};

