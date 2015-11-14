#include<iostream>
#include<string> // used for string type and getline() method
#include<vector> // used for being able to return array of objects
#include<cstdlib> // used for exit()
using namespace std;

// Mini Library Management System v2
// by Garen Yöndem

enum Commands { GET = 0, REMOVE = 1, ADDNEWBOOK = 2, SHOWALL = 3, HELP = 4, EXIT = 5 };
enum Sections { SciFi = 0, Adventure = 1, Comedy = 2, Horror = 3, Fantasy = 4, Novel = 5, Religious = 6 };

inline const char* ToString(Sections sec)
{
	switch (sec)
	{
	case SciFi:
		return "Sci-Fi";
	case Adventure:
		return "Adventure";
	case Comedy:
		return "Comedy";
	case Horror:
		return "Horror";
	case Fantasy:
		return "Fantasy";
	case Novel:
		return "Novel";
	case Religious:
		return "Religious";
	}
}

class Book
{
private:
	static const Sections _section = SciFi; // Sci-Fi, Adventure, Comedy ...
	static const int _shelfNumber = 12;
	static const int _rowNumber = 100;

public:
	string name;
	string writer;
	int pages;
	long bookPosition[_section][_shelfNumber][_rowNumber];

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
		demoBook.bookPosition[Novel][12][4];
		allBooks.push_back(demoBook);

		demoBook.name = "Pilgrim's Progress";
		demoBook.pages = 230;
		demoBook.writer = "John Bunyan";
		demoBook.bookPosition[Religious][2][54];
		allBooks.push_back(demoBook);

		demoBook.name = "Robinson Crusoe";
		demoBook.pages = 140;
		demoBook.writer = "Daniel Defoe";
		demoBook.bookPosition[Adventure][5][78];
		allBooks.push_back(demoBook);

		demoBook.name = "Gulliver's Travels";
		demoBook.pages = 250;
		demoBook.writer = "Jonathan Swift";
		demoBook.bookPosition[Fantasy][7][61];
		allBooks.push_back(demoBook);

		demoBook.name = "Clarissa";
		demoBook.pages = 290;
		demoBook.writer = "Samuel Richardson";
		demoBook.bookPosition[Novel][1][1];
		allBooks.push_back(demoBook);

		demoBook.name = "Frankenstein";
		demoBook.pages = 350;
		demoBook.writer = "Mary Shelley";
		demoBook.bookPosition[Horror][8][32];
		allBooks.push_back(demoBook);
	}

	static void getAllBooksToDisplay() {
		for each(Book i in getAllBooks()) {
			cout << "Name: " << i.name << endl;
			cout << "Writer: " << i.writer << endl;
			cout << "Pages: " << i.pages << endl;
			cout << "This book is at: " << i.bookPosition << endl << endl;
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

	static Book getBookByIndex(int index) {
		return allBooks.at(index - 1);
	}

	static void getBook() {
		cin.clear();
		cin.ignore();
		cout << "Type the row number of the book you want to find" << endl;
		cin >> index;
		if (!cin.fail()) {
			try
			{
				auto book = getBookByIndex(index);
				cout << "Name: " << book.name << endl << "Pages: " << book.pages << endl << "Writer: " << book.writer << endl;
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
				auto bookToRemove = getBookByIndex(index);
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
	cout << "Type \"2\" to add new book" << endl;
	cout << "Type \"3\" to list all books" << endl;
	cout << "Type \"4\" to get help whenever you need" << endl;
	cout << "Type \"5\" to exit console" << endl;
}

void exitApp() {
	exit(0);
}

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

	cout << "Waiting for a command, type 4 to get help/started" << endl << endl;
	WaitForInput();
};
