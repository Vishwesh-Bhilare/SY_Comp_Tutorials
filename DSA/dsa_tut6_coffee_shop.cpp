

#include<iostream>
using namespace std;
#include<string>

class ListNode {
public:
	string val;
	ListNode* next;

	ListNode() {
    	val = "";
    	next = nullptr;
	}

	ListNode(string v) {
    	val = v;
    	next = nullptr;
	}
};

void push(ListNode*& front, ListNode*& rear) {
	string customer;
	cout << "Enter customer name: ";
	cin >> customer;
	cout << customer << " joined the line!\n" << endl;

	ListNode* temp = new ListNode(customer);

	if (front == nullptr && rear == nullptr) {
    	front = temp;
    	rear = temp;
	} else {
    	rear->next = temp;
    	rear = temp;
	}
}

void pop(ListNode*& front, ListNode*& rear) {
	if (front == nullptr) {
    	cout << "Nothing in the queue!" << endl;
    	return;
	} else {
    	ListNode* temp = front;
   	 
    	cout << "\n" << front->val << "'s order is ready. They leave the line" << endl;
   	 
    	front = front->next;
    	if (front == nullptr) {
        	rear = nullptr;
    	}
    	delete temp;
	}
}

void display(ListNode* front) {
	ListNode* temp = front;

	if (temp == nullptr) {
    	cout << "Queue is empty!" << endl;
    	return;
	}

	while (temp != nullptr) {
    	cout << temp->val;
    	if (temp->next != nullptr) cout << " -> ";
    	temp = temp->next;
	}
	cout << endl;
}

int main() {
	int n;
	ListNode* front = nullptr;
	ListNode* rear = nullptr;

	do {
    	cout << "--- Coffee Shop Queue Menu ---\n1. New Customer Arrival (Enqueue)\n2. Serve Customer (Dequeue)\n3. Show Queue\n4. Exit\nChoose an option: ";
    	cin >> n;

    	switch (n) {
        	case 1:
            	push(front, rear);
            	break;

        	case 2:
            	pop(front, rear);
            	break;

        	case 3:
            	display(front);
            	break;

        	case 4:
            	cout << "Exiting coffee shop." << endl;
            	break;

        	default:
            	cout << "Invalid option, try again!" << endl;
            	break;
    	}

	} while (n != 4);

	return 0;
}
