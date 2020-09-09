#include "LinkedList.h"
#include <iostream>
#include <exception>
#include <string>

LinkedList::LinkedList() {
	Head = nullptr;
}

LinkedList::~LinkedList() {
	while (Head != nullptr) {
		Node* toDelete = Head;
		Head = Head->getNext();
		delete toDelete;
	}
};

void LinkedList::insert(Node* newNode) {
	if (Head == nullptr) {
		Head = newNode;
	}
	else if (*(Head) > *(newNode)) {
		newNode->setNext(Head);
		Head = newNode;
	}
	else if (Head->getNext() == nullptr) {
		Head->setNext(newNode);
	}
	else {
		Node* next = Head;
		while (*(next->getNext()) < *(newNode)) {
			next = next->getNext();
			if (next->getNext() == nullptr) {
				next->setNext(newNode);
				return;
			}

		}
		newNode->setNext(next->getNext());
		next->setNext(newNode);
	}
}

void LinkedList::newNode(int key, int data) {
	Node* newNode = new Node(key, data);
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
		throw std::invalid_argument("List is empty.");
	}
}

Node* LinkedList::find(int key) {
	Node* currentNode = Head;
	while (currentNode != nullptr) {
		if (currentNode->getKey() == key) {
			return currentNode;
		}
		else {
			currentNode = currentNode->getNext();
		}
	}
	throw std::invalid_argument("No item found with key " + std::to_string(key));
}

Node* LinkedList::findPreceding(int key) {
	Node* currentNode = Head;
	if (currentNode->getKey() == key) {
		throw std::runtime_error("Head match.  Readjust list.");
	}
	while (currentNode->getNext() != nullptr) {
		if (currentNode->getNext()->getKey() == key) {
			return currentNode;
		}
		else {
			currentNode = currentNode->getNext();
		}
	}
	throw std::invalid_argument("No item found with key " + std::to_string(key));
}

void LinkedList::remove(int key) {
	Node* toDelete;
	try {
		toDelete = this->findPreceding(key);
	}
	catch (std::runtime_error e) {
		toDelete = Head;
		Head = Head->getNext();
		delete toDelete;
	}
	toDelete->setNext(toDelete->getNext());
}