#include <iostream>
#include <Windows.h>
#include<cmath>
using namespace std;

int power(int a, int b);
int power2(int a, int b);

int main() {
	int base, exp;
	cout << "Enter base number" << endl;
	cin >> base;
	cout << "Enter exponential number" << endl;
	cin >> exp;
	cout << base << "*" << exp << "=" << power(base, exp) << endl;

	cout << base << "*" << exp << "=" << power2(base, exp) << endl;

	Sleep(10000);
	return 0;
}
int power(int base, int exp) {
	if (exp != 1) {
		return (base * power(base, exp - 1));
	}
}

int power2(int base, int exp) {
	if (exp != 1) {
		for (size_t i = 0; i < exp; i++)
		{
			base = base * exp;
		}
		return base;
	}
}