#include <iostream>
#include <windows.h>
using namespace std;

void main()
{
	//cout << "Hello World";

	/*int x = 1;
	int y = 2;
	cout << x + y;*/

	/*cout << "Size of char : " << sizeof(char) << endl;
	cout << "Size of int : " << sizeof(int) << endl;
	cout << "Size of short int : " << sizeof(short int) << endl;
	cout << "Size of long int : " << sizeof(long int) << endl;
	cout << "Size of float : " << sizeof(float) << endl;
	cout << "Size of double : " << sizeof(double) << endl;
	cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;*/

	//You can create a new name for an existing type using typedef.
	/*typedef int myInt;
	myInt x = 3;
	myInt y = 1;
	cout << x + y;*/


	/*int numbers[] = { 1,2,3 };

	int sum = numbers[0] + numbers[1] + numbers[2];
	cout << sum << " arrayin toplami" << endl;
	cout << sizeof(numbers) << " sizeof numbers" << endl;
	cout << sizeof(numbers[0]) << " sizeof numers[0]" << endl;

	int divided = sum / (sizeof(numbers) / sizeof(numbers[0]));
	cout << divided << " divided result";*/


	/*int numbers[] = { 1,2,3,4,5,6,7,8,9 };
	int numersCount = sizeof(numbers) / sizeof(numbers[0]);
	int sum = 0;
	for (int i = 0; i < numersCount; i++)
	{
		sum += numbers[i];
	}
	cout << sum;*/

/*#include "ItemType.h"
	class UnsotredType {
	public:
		void MakeEmpty();
		bool isFull();
		int Lenghs();
		void RetrievetItem(ItemType &item, bool &found);
		void InsertItem(ItemType item);
		void DeleteItem(ItemType item);
		void ResetList();
		void GetNextItem(ItemType &item);
	private:
		int lenght;
		ItemType info["MAX-ITEMS"];
		int currentPos;
	};*/

	/*
	//Default constructor
	SortedType::SortedType() {
		lenght = 0;
	}
	//Primitive type constructor
	SortedType::SortedType(ItemTyp initialValue) {
		lenght = 0;
		for (size_t i = 0; i < MAX_ITEMS; i++)
		{
			info[i] = initialValue;
		}
	}
	*/



}