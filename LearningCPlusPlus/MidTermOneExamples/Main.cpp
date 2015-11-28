#include <iostream>
#include<fstream>
#include<string>
using namespace std;


void main() {
	//question 1)
	/*void SortedType::RetrieveItem(ItemType &item, bool &found) {
		int lowest = 0;
		int highest = n - 1;
		int mid = (lowest + highest) / 2;
		found = false;
		while (lowest <= highest && found == false)
		{
			if (info[mid] < item)
			{
				lowest = mid;
			}
			else if (info[mid] > item)
			{
				highest = mid;
			}
			else
			{
				found = true;
			}
			mid = (lowest + highest) / 2;
		}
	}*/

	//question 1)b)
	//BigO(log2N)

	//question 2)a)
	ifstream file("ReadMe.txt");
	string line;
	int index = 0;
	int numbers[50];
	while (getline(file, line))
	{
		if (index != 50) {
			cout << line;
			stoi(line) >> numbers[index];
			index++;
		}
		else {
			break;
		}
	}

	//Search for y1 y2 y3
	int searchedNumbers[] = { 5, 2, 9 };
	int sizeOfNumbers = sizeof(numbers) / sizeof(numbers[0]);
	for each(int searchedNumber in searchedNumbers) {
		for (size_t i = 0; i < sizeOfNumbers; i++)
		{
			if (numbers[i] == searchedNumber)
			{
				cout << "Found " << searchedNumber << "at index " << numbers[i] << endl;
			}
			else {
				cout << "NO!";
			}
		}
	}


	//question 4)b)
	//enum colors { yellow, black, green = 6, brown, cyan, red, blue, white };


}