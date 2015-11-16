#include<iostream>
#include<string> // used for string type and getline() method
#include<vector> // used for being able to return array of objects
#include<cstdlib> // used for exit()
using namespace std;

// Mini Class Management System
// by Garen Yöndem

enum Commands { GET = 0, REMOVE = 1, SHOWALL = 2, HELP = 3, EXIT = 4 };

class Student
{
public:
	string name;
	int age;
	int quizResult;
};

class Class
{
public:
	string name;
	string teacherName;
	vector<Student> students;
};

int index;
static vector<Class> school;

class myMethods {
public:
	static void generateDemoData() {
		// class 1
		Class _class;
		_class.name = "10A";
		_class.teacherName = "Angela";
		// student 1
		Student _student;
		_student.name = "Jack";
		_student.age = 10;
		_student.quizResult = 80;
		_class.students.push_back(_student);
		// student 2
		_student.name = "Rose";
		_student.age = 11;
		_student.quizResult = 47;
		_class.students.push_back(_student);
		// student 3
		_student.name = "Lena";
		_student.age = 13;
		_student.quizResult = 63;
		_class.students.push_back(_student);
		school.push_back(_class);

		// class 2
		_class.name = "11C";
		_class.teacherName = "Ben";
		// class 2 student 1
		_student.name = "Marty";
		_student.age = 15;
		_student.quizResult = 66;
		_class.students.push_back(_student);
		// class 2 student 2
		_student.name = "Yolo";
		_student.age = 14;
		_student.quizResult = 82;
		_class.students.push_back(_student);
		// class 2 student 3
		_student.name = "Jaina";
		_student.age = 18;
		_student.quizResult = 61;
		_class.students.push_back(_student);
		school.push_back(_class);
	}

	static void showAll() {
		for each(Class _class in getAllClasses()) {
			cout << "Instructor name: " << _class.teacherName << endl;
			cout << "Student count in this class: " << _class.students.size() << endl << endl;
			if (_class.students.size() > 0)
			{
				for each(Student _student in _class.students) {
					cout << "Student name: " << _student.name << endl;
					cout << "Student age: " << _student.age << endl;
					cout << "Student quiz result: " << _student.quizResult << endl << endl;
				}
			}
		}
		cout << "Number of total classes in school is: " << countAllClasses() << endl;
	}

	static vector<Class> getAllClasses()
	{
		vector<Class> tempSchool;
		for each(auto _class in school) {
			tempSchool.push_back(_class);
		}
		return tempSchool;
	}

	static int countAllClasses() {
		return school.size();
	}

	static Class getClassByIndex(int classIndex) {
		return school.at(classIndex - 1);
	}

	static Student getStudentByIndex(Class _class, int stidentIndex) {
		return _class.students.at(stidentIndex - 1);
	}

	static void retrieveStudent() {
		cin.clear();
		cin.ignore();
		cout << "Type the number of class you want to find" << endl;
		cin >> index;
		if (!cin.fail()) {
			try
			{
				auto _class = getClassByIndex(index);
				cout << "Class gathered successfully. Type the number of student you want to find" << endl;
				cin >> index;
				auto _student = getStudentByIndex(_class, index);
				cout << "Student gathered successfully." << endl << "Name: " << _student.name << endl << "Age: " << _student.age << endl << "Quiz Result: " << _student.quizResult << endl;
			}
			catch (const std::exception&)
			{
				cout << "Unable to find the class or student you typed" << endl;
				retrieveStudent();
			}
		}
		else {
			cout << "Please type a integer value" << endl;
			retrieveStudent();
		}
	}

	static void deleteStudent() {
		cin.clear();
		cin.ignore();
		cout << "Type the number of class you want to find" << endl;
		cin >> index;
		if (!cin.fail()) {
			try
			{
				auto _class = getClassByIndex(index);
				cout << "Class gathered successfully. Type the number of student you want to find" << endl;
				cin >> index;
				auto _studentToRemove = getStudentByIndex(_class, index);
				cout << "Student gathered successfully." << endl;
				_class.students.erase(_class.students.begin() + (index - 1));
				cout << "Successfully removed " << _studentToRemove.name << " from class and school" << endl;
			}
			catch (const std::exception&)
			{
				cout << "Unable to find the class or student you typed" << endl;
				deleteStudent();
			}
		}
		else {
			cout << "Please type a integer value" << endl;
			deleteStudent();
		}
	}
};

void helpDoc() {
	cout << "Type \"0\" to retrieve a student" << endl;
	cout << "Type \"1\" to remove a student" << endl;
	cout << "Type \"2\" to list all students" << endl;
	cout << "Type \"3\" to get help whenever you need" << endl;
	cout << "Type \"4\" to exit console" << endl;
}

void exitApp() {
	exit(0);
}

void WaitForInput() {
	//waiting to processing input
	cin >> index;
	switch (index) {
	case GET:
		myMethods::retrieveStudent();
		break;
	case REMOVE:
		myMethods::deleteStudent();
		break;
	case SHOWALL:
		myMethods::showAll();
		break;
	case HELP:
		helpDoc();
		break;
	case EXIT:
		exitApp();
		break;
	}
	WaitForInput();
}

int main() {
	myMethods::generateDemoData();
	cout << "Welcome to Mini School Management System" << endl;
	cout << "Please answer the questions below and then press \"enter\" to proceed to next step" << endl << endl;
	cout << "Waiting for a command, type 3 to get help/started" << endl << endl;
	WaitForInput();
};
