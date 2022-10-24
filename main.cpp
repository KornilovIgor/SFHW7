#include "IntegerArray.h"
#include <iostream>

using namespace std;

int main()
{
	try 
	{
		IntegerArray arr();
	}
	catch (const char* e)
	{
		cout << e << endl;
	}
	

	return 0;
}