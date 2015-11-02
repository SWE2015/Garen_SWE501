#include<iostream>
#include<Windows.h> // used for Sleep()
#include<string> // used for string type and getline() method
#include<vector> // used for being able to return array of objects
#include<cstdlib> // used for exit()
using namespace std;

// Mini Library Management System
// by Garen Yöndem

class Book
{
public:
	string name;
	string writer;
	int pages;

};

int index;
static vector<Book> allBooks;

class myMethods {
public:
	static void generateDemoData() {
		Book demoBook;
		demoBook.name = "Don Quixote";
		demoBook.pages = 490;
		demoBook.writer = "Miguel De Cervantes";
		allBooks.push_back(demoBook);

		demoBook.name = "Pilgrim's Progress";
		demoBook.pages = 230;
		demoBook.writer = "John Bunyan";
		allBooks.push_back(demoBook);

		demoBook.name = "Robinson Crusoe";
		demoBook.pages = 140;
		demoBook.writer = "Daniel Defoe";
		allBooks.push_back(demoBook);

		demoBook.name = "Gulliver's Travels";
		demoBook.pages = 250;
		demoBook.writer = "Jonathan Swift";
		allBooks.push_back(demoBook);

		demoBook.name = "Clarissa";
		demoBook.pages = 290;
		demoBook.writer = "Samuel Richardson";
		allBooks.push_back(demoBook);

		demoBook.name = "Frankenstein";
		demoBook.pages = 350;
		demoBook.writer = "Mary Shelley";
		allBooks.push_back(demoBook);
	}

	static void getAllBooksToDisplay() {
		for each(Book i in getAllBooks()) {
			cout << "Name: " << i.name << endl;
			cout << "Writer: " << i.writer << endl;
			cout << "Pages: " << i.pages << endl << endl;
		}
		cout << "Number of total books: " << countAllBooks() << endl;
	}

	static vector<Book> getAllBooks()
	{
		vector<Book> books;
		for each(auto i in allBooks) {
			books.push_back(i);
		}
		return books;
	}

	static int countAllBooks() {
		return  allBooks.size();
	}

	static void getBook() {
		cin.clear();
		cin.ignore();
		cout << "Type the row number of the book you want to find" << endl;
		cin >> index;
		if (!cin.fail()) {
			try
			{
				cout << "Name: " << allBooks.at(index - 1).name << endl << "Pages: " << allBooks.at(index - 1).pages << endl << "Writer: " << allBooks.at(index - 1).writer << endl;
			}
			catch (const std::exception&)
			{
				cout << "Unable to find a book at that row" << endl;
				getBook();
			}
		}
		else {
			cout << "Please type a integer value" << endl;
			getBook();
		}
	}

	static void removeBook() {
		cin.clear();
		cin.ignore();
		cout << "Type the row number of the book you want to remove" << endl;
		cin >> index;
		if (!cin.fail()) {
			try
			{
				auto bookToRemove = allBooks.at(index - 1);
				allBooks.erase(allBooks.begin() + (index - 1));
				cout << "Successfully removed " << bookToRemove.name << endl;
			}
			catch (const std::exception&)
			{
				cout << "Unable to find a book at that row" << endl;
				removeBook();
			}
		}
		else {
			cout << "Please type a integer value" << endl;
			removeBook();
		}
	}

	static void addNewBook() {
		Book newBook;
		cout << "What is the name of the Book?" << endl;
		cin.ignore(); // used for ignoring the whitespace and waiting for input while using getline()
		getline(cin, newBook.name); // used for getting more then one word
		cout << "Who is the writer of " << newBook.name << " ?" << endl;
		cin.ignore();
		getline(cin, newBook.writer);
	reEnterPages:
		cout << "How many pages are in the book " << newBook.name << " ?" << endl;
		cin.ignore();
		cin >> newBook.pages;
		if (!cin.fail()) {
			allBooks.push_back(newBook);
			cout << "Book successfully added to library database" << endl;
		}
		else {
			cout << "Please type a integer value for pages" << endl;
			cin.clear();
			cin.ignore();
			goto reEnterPages;
		}
	}
};

void helpDoc() {
	cout << "Type \"0\" to get a book at specific index" << endl;
	cout << "Type \"1\" to remove a book at specific index" << endl;
	cout << "Type \"2\" to update a book at specific index" << endl;
	cout << "Type \"3\" to add new book" << endl;
	cout << "Type \"4\" to list all books" << endl;
	cout << "Type \"5\" to get help whenever you need" << endl;
	cout << "Type \"6\" to exit console" << endl;
}

void exitApp() {
	exit(0);
}

enum Commands { GET = 0, REMOVE = 1, UPDATE = 2, ADDNEWBOOK = 3, SHOWALL = 4, HELP = 5, EXIT = 6 };

void WaitForInput() {
	//waiting to processing input
	cin >> index;

	switch (index) {
	case GET:
		myMethods::getBook();
		break;
	case REMOVE:
		myMethods::removeBook();
		break;
	case UPDATE:
		cout << "UPDATE hit" << endl;
		break;
	case ADDNEWBOOK:
		myMethods::addNewBook();
		break;
	case SHOWALL:
		myMethods::getAllBooksToDisplay();
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

	cout << "Welcome to Mini Library Management System" << endl;
	cout << "Please answer the questions below and then press \"enter\" to proceed to next step" << endl << endl;

	cout << "Waiting for a command, type 5 to get started" << endl << endl;
	WaitForInput();

	//Sleep(100000); // added for being able to see results, otherwise console closes once the execution is complete.
};
