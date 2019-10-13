/****************************************************************/
/*                Producer Consumer Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "ProducerConsumer.hpp"
#include <iostream>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Producer (Produce items into the queue)" << endl;
	cout << "2. Consumer (Consume items from the queue)" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}

int main(int argc, char const *argv[])
{
	ProducerConsumer pc;
	string choiceStr, numStr, toProd;
	int choice, deleted = 0;
	bool flag = false, run = true;


	while (run){
		menu();

		getline(cin, choiceStr);
		choice = stoi(choiceStr);

		switch (choice){
			case 1:
				cout << "Enter the number of items to be produced:" << endl;
				getline(cin, numStr);
				for (int i = 0; i < stoi(numStr); i++){
					cout << "Item" << i+1 << ":" << endl;
					getline(cin, toProd);
					pc.enqueue(toProd);
				}
				break;
			case 2:
				cout << "Enter the number of items to be consumed:" << endl;
				getline(cin, numStr);
				if (stoi(numStr) > pc.queueSize()){
					flag = true;
				}
				while (!pc.isEmpty() && deleted < stoi(numStr)){
					cout << "Consumed: " << pc.peek() << endl;
					pc.dequeue();
					deleted++;
				}
				if (flag){
					cout << "No more items to consume from queue" << endl;
				}
				break;
			case 3:

				cout << "Number of items in the queue:" << pc.queueSize() << endl;
				run = false;
				break;


			default:
				cout << "Please enter a valid input." << endl;
				break;
		}
	}
	return 0;
}
