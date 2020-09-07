#include "Node.h"

Node::Node() {};

Node::Node(int key, int data) {
	Key = key;
	Data = data;
}

Node::Node(int key, int data, Node* next) {
	Key = key;
	Data = data;
	Next = next;
}

Node::~Node() {
	Next = nullptr;
	delete Next;
}

int Node::getData() {
	return Data;
}

void Node::setData(int data) {
	Data = data;
}

int Node::getKey() {
	return Key;
}

Node* Node::getNext() {
	return Next;
}

void Node::setNext(Node* next) {
	Next = next;
}

bool Node::operator<(const Node& a) {
	return Key < a.Key;
}

bool Node::operator>(const Node& a) {
	return Key > a.Key;
}

bool Node::operator<(const Node& a) {
	return Key == a.Key;
}