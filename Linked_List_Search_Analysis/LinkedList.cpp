#include "LinkedList.h"

LinkedList::LinkedList() {
	Head = nullptr;
}

void LinkedList::insert(Node newNode) {
	if (Head == nullptr) {
		Head = &newNode;
	}
	else if (*(Head) > newNode) {
		newNode.setNext(Head->getNext());
		Head->setNext(&newNode);
	}
	else {
		Node* next = Head->getNext();
		while (*(next) < newNode) {
			if (next->getNext() == nullptr) {
				next->setNext(&newNode);
				break;
			}
			next = next->getNext();
		}
	}
}