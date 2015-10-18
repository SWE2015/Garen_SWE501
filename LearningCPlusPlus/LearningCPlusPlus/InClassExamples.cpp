#include <iostream>
#include <windows.h>
using namespace std;

//void main()
//{
//	enum Color {
//		red,
//		green,
//		blue
//	};
//	Color myFav;
//	myFav = red;
//	Sleep(10000);
//}

//#include <time.h>
//void displayTime(const struct tm * tim) 
//{
//	cout << 
//}

//struct date {
//	int month;
//	int day;
//	int year;
//};
//void main() {
//	struct date myDate;
//	myDate.month = 10;
//	myDate.day = 6;
//	myDate.month = 2015;
//}
//
//void displatDate(struct date * dt) {
//	static char * name[] = {
//		"zero", "january","February"
//	}
//	printf("%s", "%d", "%d", name[dt->month], dt->day, dt->year);
//}


//class Date {
//public:
//	Date(int mm, int dy, int yr); // constructor
//	void display(); // a function to print date
//	Date(); // destructor
//private:
//	int month, day, year; // private date members
//};
//
//// some useful functions
//inline int max(int a, int b) {
//	if (a > b) return a,
//		return b;
//}
//inline int min(int a, int b) {
//	if (a < b) return a,
//		return b;
//}

//// contructor
//Date::Date(int mn, int dy, int yr) {
//	static int lenght[] = { 0,31,28,31,....,31 };
//	month = max(1, mn);
//	month = min(month, 12);
//	day = max(1, dy);
//	day = min(1, lenght[month]);
//	year = max(1, year);
//}
//// member function display
//void Date : display() {
//	static char *name[] = {
//			"zero", "january", "February"
//	}
//	cout << name[month] << " " << day << " " << year;
//}

//// the destructor
//Date::Date() {
//
//}
//
//void main() {
//	Date myDate(10, 12, 2015);
//	Date yourDate(10, 13, 2015);
//	myDate.display();
//	cout << "\n";
//	yourDate.display();
//	cout << "\n";
//}