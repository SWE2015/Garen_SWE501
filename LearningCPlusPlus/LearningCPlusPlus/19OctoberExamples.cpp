//#include<iostream>
//#include<string.h>
//#include<Windows.h>
//using namespace std;
//
//class Demo {
//public:
//	Demo(const char *nm);
//	~Demo();
//private:
//	char name[20];
//};
//
//Demo::Demo(const char *nm) {
//	strncpy_s(name, nm, 20);
//	cout << "Constructor called for " << name << '\n';
//}
//
//Demo::~Demo() {
//	cout << "Destructor called for " << name << "\n";
//}
//
//void func() {
//	Demo LocalFuncObject("LocalFuncObject");
//	static Demo StaticObject("StaticObject");
//	cout << "inside func \n";
//}
//Demo GlobalObject("GlobalObject");
//
//void main() {
//	Demo LocalMainObject("LocalMainObject");
//	cout << "in main, before calling func \n";
//	func();
//	cout << "in main, after calling func \n";
//
//	Sleep(10000000);
//}