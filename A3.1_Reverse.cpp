#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std
struct Node {
	int key;
	struct Node *next;
};
Node* buildList() {
	Node *head, *current, *previous;

	head = new Node();
	head->key = 1;
	head->next=NULL;
	current = head;

	for (int i = 2; i < 5; i++) {
		previous = current;
		current = new Node();
		current->key = i;
		previous->next = current;
		previous = current;

	}
	previous->next = NULL;
	return head;

}
Node* reverselist(Node* list) {

	Node *currentnode, *previousnode, *nextnode;

	previousnode = list;

	//previous -> current -> next

	currentnode = previousnode->next;
	previousnode->next = NULL; //new tail

	while (currentnode) {
		nextnode = currentnode->next;
		currentnode->next = previousnode;
		previousnode = currentnode;
		currentnode=nextnode;
	}
	return previousnode;

}
void printList(Node* list){
	while (list) {
			cout << list->key << endl;
			list = list->next;
		}

}

int main(void) {

	Node* head = buildList(); //Build singly linked list ***  head -> |1|->|2|->|3|->|4|->|5|->NULL
	cout << "print original list " << endl;
	printList(head);

	////////////////////// REVERSE ===============

	Node* reversehead = reverselist(head);  //Reverse the list *** reversehead ->  |5|->|4|->|3|->|2|->|1|->NULL
	cout << " Print Reversed list " << endl;
	printList(reversehead);


	return EXIT_SUCCESS;
}
