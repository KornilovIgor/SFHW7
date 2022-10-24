#pragma once

class IntegerArray
{
private:
	int _length = 0;
	int* _data = 0;

public:
	IntegerArray() = default;
	IntegerArray(int length) throw (const char&);
	~IntegerArray();
	
	void erase();
	void reallocate(int newLength);
	void resize(int newLength);

	int& operator[](int index) throw (const char&);
};