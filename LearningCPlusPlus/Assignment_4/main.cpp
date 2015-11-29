#include<iostream>
using namespace std;

const int capacity = 15;

class Queue
{
	int dynamicArr[capacity];
	int front;
	int back;
public:
	Queue()
	{
		back = -1;
		front = -1;
	}
	void insert(int x)
	{
		if (back > 14)
		{
			cout << "Queue over flow" << endl;
			front = back = -1;
			return;
		}
		dynamicArr[++back] = x;
		cout << "Added " << x << " to queue" << endl;
	}
	void remove()
	{
		if (front == back)
		{
			cout << "Nothing left to remove in queue" << endl;
			return;
		}
		cout << "Removed " << dynamicArr[++front] << " from queue" << endl;
	}
	void display()
	{
		if (back == front)
		{
			cout << "Queue is empty" << endl;
			return;
		}
		for (int i = front + 1; i <= back; i++) {
			cout << dynamicArr[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	int choice;
	Queue queue;
	while (1)
	{
		cout << "Type '1' to Insert - '2' to Remove - '3' to Show - '4' to Exit" << endl << "Enter your choice" << endl << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter the number ";
			cin >> choice;
			queue.insert(choice);
			break;
		case 2:
			queue.remove();
			break;
		case 3:
			queue.display();
			break;
		case 4:
			exit(0);
		}
	}
	return (0);
}