#include <iostream>
#include <windows.h>
using namespace std;

double calcCompoundAmount(double *principal, double *interestRate, int *timesPerYear, double *years) {
	//formula S=P(1 + r/n)^nt
	return	*principal * (pow((1 + (*interestRate / *timesPerYear)), (*timesPerYear * *years)));
}

void main() {
	double principal;
	double interestRate;
	int timesPerYear;
	double years;

	cout << "Welcome to compund amount calculator" << endl;
	cout << "Please answer the questions below" << endl << endl;

	cout << "How much is your principal amount : " << endl;
	cin >> principal;
	cout << "Interest rate : " << endl;
	cin >> interestRate;
	interestRate = interestRate / 100;
	cout << "Number of payment payments you wish to make per year : " << endl;
	cin >> timesPerYear;
	cout << "Due : " << endl;
	cin >> years;

	principal = calcCompoundAmount(&principal, &interestRate, &timesPerYear, &years);
	cout << "You final payment will be: " << principal;

	Sleep(1000000);
}