#include <fstream>
#include <string>
#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	ifstream file("ReadMe.txt");
	string content;

	while (getline(file, content))
	{
		cout << content;
	}

	Sleep(100000);
}
