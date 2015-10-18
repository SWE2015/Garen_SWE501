#include <iostream>
#include <windows.h>
using namespace std;

double calcCompoundInterest(double *principal, double *interestRate, int *timesPerYear, double *years) {
	//formula S=P(1 + r/n)^nt
	return	*principal * (pow((1 + (*interestRate / *timesPerYear)), (*timesPerYear * *years)));
}

void main() {
	double principal;
	double interestRate;
	int timesPerYear;
	double years;
	double amount;

	cout << "Welcome to compound interest calculator" << endl;
	cout << "Please answer the questions below and then press \"enter\" to proceed to next step" << endl << endl;

	cout << "How much is your principal amount: " << endl;
	cin >> principal;
	cout << "Interest rate: " << endl;
	cin >> interestRate;
	interestRate = interestRate / 100;
	cout << "Number of payments you wish to make each year: " << endl;
	cin >> timesPerYear;
	cout << "Due: " << endl;
	cin >> years;

	amount = calcCompoundInterest(&principal, &interestRate, &timesPerYear, &years);
	cout << "You final payment will be: " << amount << endl;
	cout << "You will earn: " << amount - principal;

	Sleep(1000000);
}