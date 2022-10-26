#include "IntegerArray.h"
#include <iostream>
#include <exception>
using namespace std;

void test();
void print(IntegerArray& ia);

int main()
{
	test();

	return 0;
}

void test()
{
	{
		cout << "Test #1: Negative array" << endl;
		try
		{
			IntegerArray arr(-2);
			arr[4];
		}
		catch (bad_range& br)
		{
			cout << br.what() << endl
				<< "Range: [0.." << br.getLength() - 1 << "]" << endl
				<< "Index: " << br.getIndex() << endl;
		}
		catch (bad_length& bl)
		{
			cout << bl.what() << endl
				<< "Length value: " << bl.getLength() << endl;
		}
		catch (exception& e)
		{
			cout << e.what();
		}
		cout << "Test#1:End" << endl << endl;
	}

	{
		cout << "Test#2:Out fo range" << endl;
		try
		{
			IntegerArray arr(2);
			arr[4];
			arr[0] = 3;
			arr[1] = -8;
			cout << "Arr {" << arr[0] << " , " << arr[1] << "}";
		}
		catch (bad_range& br)
		{
			cout << br.what() << endl
				<< "Range: [0.." << br.getLength() - 1 << "]" << endl
				<< "Index: " << br.getIndex() << endl;
		}
		catch (bad_length& bl)
		{
			cout << bl.what() << endl
				<< "Value of length: " << bl.getLength() << endl;
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}
		cout << "Test#2.End" << endl << endl;
	}

	{
		cout << "Test#3:Simple test" << endl;
		try
		{
			IntegerArray arr(2);
			arr[0] = 3;
			arr[1] = -8;
			cout << "IntegerArray {" << arr[0] << ", " << arr[1] << "}" << endl;
		}
		catch (bad_range& br)
		{
			cout << br.what() << endl
				<< "Range: [0.." << br.getLength() - 1 << "]" << endl
				<< "Index: " << br.getIndex() << endl;
		}
		catch (bad_length& bl)
		{
			cout << bl.what() << endl
				<< "Value of length: " << bl.getLength() << endl;
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}
		cout << "Test#3.End" << endl << endl;
	}

	cout << "Test#4:Copy, insertBeforeFirst, insertAfterLast, Search" << endl;
	try
	{
		IntegerArray ia(3);

		ia[0] = 3;
		ia[1] = 4;
		ia[2] = -8;

		cout << "arr1 = ";
		print(ia);

		cout << "Try copy" << endl;
		IntegerArray ia2 = ia;
		cout << "arr2 = ";
		print(ia2);

		cout << "Try insert before first (arr1)" << endl;
		ia.insertBeforeFirst(10);
		cout << "arr1 = ";
		print(ia);

		cout << "Try insert after last (arr2)" << endl;
		ia2.insertAfterLast(100);
		cout << "arr2 = ";
		print(ia2);

		cout << "Try get index for -8 (arr1)" << endl;
		cout << "Index \"-8\": ";
		if (ia.search(-8) == -1)
		{
			cout << "Not found" << endl;
		}
		else
		{
			cout << ia.search(-8) << endl;
		}

		cout << "Try get index for 43 (arr2)" << endl;
		cout << "Index \"43\": ";
		if (ia2.search(43) == -1)
		{
			cout << "Not found" << endl;
		}
		else
		{
			cout << ia2.search(43) << endl;
		}

	}
	catch (bad_range& br)
	{
		cout << br.what() << endl
			<< "Range: [0.." << br.getLength() - 1 << "]" << endl
			<< "Index: " << br.getIndex() << endl;
	}
	catch (bad_length& bl)
	{
		cout << bl.what() << endl
			<< "Value of length: " << bl.getLength() << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	cout << "Test#4.End" << endl << endl;

	cout << "Test#5:insertBeforeFirst \"3\" into empty array" << endl;
	try
	{
		IntegerArray arr;

		arr.insertBeforeFirst(3);
		print(arr);
	}
	catch (bad_range& br)
	{
		cout << br.what() << endl
			<< "Range: [0.." << br.getLength() - 1 << "]" << endl
			<< "Index: " << br.getIndex() << endl;
	}
	catch (bad_length& bl)
	{
		cout << bl.what() << endl
			<< "Value of length: " << bl.getLength() << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	cout << "Test#5.End" << endl << endl;

	cout << "Test#6:insertAfterLast \"6\" into empty array" << endl;
	try
	{
		IntegerArray arr;

		arr.insertAfterLast(6);
		print(arr);
	}
	catch (bad_range& br)
	{
		cout << br.what() << endl
			<< "Range: [0.." << br.getLength() - 1 << "]" << endl
			<< "Index: " << br.getIndex() << endl;
	}
	catch (bad_length& bl)
	{
		cout << bl.what() << endl
			<< "Value of length: " << bl.getLength() << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	cout << "Test#6.End" << endl << endl;
}

void print(IntegerArray& ia)
{
	cout << "{ ";
	for (int i = 0; i < ia.getLength() - 1; ++i)
	{
		cout << ia[i] << ", ";
	}
	cout << ia[ia.getLength() - 1] << " }" << endl;
}