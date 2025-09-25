#include<iostream>

#include<string>

using namespace std;


class Printer {

public:

	string name;

	Printer* next;

};


void push(Printer*& head, Printer*& rear) {

	string n;

	cout << "Enter job name: "; cin >> n;

	cout << "'" << n << "' successfully added to the queue!" << endl;


	Printer* temp = new Printer;

	temp->name = n;

	temp->next = nullptr;


	if (head == nullptr) {

    	head = temp;

    	rear = temp;

	}

	else {

    	rear->next = temp;

    	rear = temp;

	}

}


void pop(Printer*& head, Printer*& rear) {

	if (head == nullptr) {

    	cout << "Queue is empty!!" << endl;

	}

	else {

    	Printer* temp = head;

    	head = head->next;


    	cout << "'" << temp->name << "' job is done! Removing it from queue" << endl;

    	delete temp;


    	if (head == nullptr) {

        	rear = nullptr;

    	}

	}

}


void display(Printer* head) {

	if (head == nullptr) {

    	cout << "Queue is empty!" << endl;

    	return;

	}


	Printer* temp = head;

	do {

    	cout << temp->name;

    	if (temp->next != head) cout << " -> ";

    	temp = temp->next;

	} while (temp != head);

	cout << endl;

}


int main() {

	Printer* head = nullptr;

	Printer* rear = nullptr;

	int choice;


	do {

    	cout << "\nPrinter Spooler Menu:\n";

    	cout << "1. Add a print job (enqueue)\n";

    	cout << "2. Process a print job (dequeue)\n";

    	cout << "3. Display all print jobs\n";

    	cout << "4. Exit\n";

    	cout << "Enter your choice: "; cin >> choice;


    	switch (choice) {

        	case 1:

            	push(head, rear);

            	break;


        	case 2:

            	pop(head, rear);

            	break;


        	case 3:

            	display(head);

            	break;


        	case 4:

            	cout << "Exiting the Printer Spooler system..." << endl;

            	break;


        	default:

            	cout << "Invalid choice! Please try again." << endl;

    	}

	} while (choice != 4);


	return 0;

}