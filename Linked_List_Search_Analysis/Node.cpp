#include "Node.h"

Node::Node() {};

Node::Node(int key, int data) {
	Key = key;
	Data = data;
}

Node::~Node() {
	if (Next == nullptr) {
		Prev->setNext(nullptr);
		Prev = nullptr;
		delete Next;
		delete Prev;
	}

}