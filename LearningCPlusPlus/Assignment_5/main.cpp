#include <iostream>
using namespace std;

// C++ LinkedList implementation
// by Garen Yöndem

struct node {
	int number;
	node *next;
};

bool isEmpty(node *head);
char menu();
void insertFirstItem(node *&head, node *&last, int number);
void insert(node *&head, node *&last, int number);
void remove(node *&head, node *&last);
void showList(node *current);

bool isEmpty(node *head) {
	return head == NULL ? true : false;
}

char menu() {
	char choice;
	cout << "Commands" << endl;
	cout << "1. Add an item to LinkedList" << endl;
	cout << "2. Remove an item from LinkedList" << endl;
	cout << "3. Show items in LinkedList" << endl;
	cout << "4. Exit" << endl;

	cin >> choice;
	return choice;
}

void insertFirstItem(node *&head, node *&last, int number) {
	node *temp = new node;
	temp->number = number;
	temp->next = NULL;
	head = temp;
	last = temp;
}

void insert(node *&head, node *&last, int number) {
	if (isEmpty(head)) {
		insertFirstItem(head, last, number);
	}
	else {
		node *temp = new node;
		temp->number = number;
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
}

void remove(node *&head, node *&last) {
	if (isEmpty(head)) {
		cout << "LinkedList is empty" << endl << endl;
	}
	else if (head == last) {
		delete head;
		head == NULL;
		last == NULL;
	}
	else {
		node *temp = head;
		head = head->next;
		delete temp;
	}
}

void showList(node *current) {
	if (isEmpty(current)) {
		cout << "LinkedList is empty" << endl << endl;
	}
	else {
		cout << "LinedList contains: " << endl << endl;
		while (current != NULL) {
			cout << current->number << endl;
			current = current->next;
		}
	}
}

int main() {
	node *head = NULL;
	node *last = NULL;

	// populating LinkedList
	for (size_t i = 0; i < 18; i++)
	{
		int tempNum = rand() % 100;
		insert(head, last, tempNum);
	}

	char choice;
	int number;
	do {
		choice = menu();
		switch (choice)
		{
		case '1': cout << "Enter a number: ";
			cin >> number;
			insert(head, last, number);
			break;
		case '2': remove(head, last);
			break;
		case '3': showList(head);
			break;
		default: cout << "Exit";
		}
	} while (choice != '4');
	return 0;
}