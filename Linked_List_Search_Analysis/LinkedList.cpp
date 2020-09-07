#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() {
	Head = nullptr;
}

LinkedList::~LinkedList() {};

void LinkedList::insert(Node newNode) {
	if (Head == nullptr) {
		Head = &newNode;
	}
	else if (*(Head) > newNode) {
		newNode.setNext(Head);
		Head = &newNode;
	}
	else if (Head->getNext() == nullptr) {
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
		next->setNext(&newNode);
	}
}

void LinkedList::newNode(int key, int data) {
	Node newNode = Node(key, data);
	insert(newNode);
}

void LinkedList::print() {
	if (Head != nullptr) {
		Node* toRead = Head;
		while (toRead != nullptr) {
			std::cout << "Item ID: " << toRead->getKey() << " Data: " << toRead->getData() << std::endl;
			toRead = toRead->getNext();
		}
	}
	else {
		std::cout << "List is empty." << std::endl;
	}
}