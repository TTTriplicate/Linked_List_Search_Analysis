#pragma once

#include "Node.h"

class LinkedList {
private:
	Node* Head;
	void insert(Node newNode);
	Node* search(int key);
public:
	LinkedList();
	~LinkedList();
	void newNode(int key, int data);
	int find(int key);
	void remove(int key);
	void print();
};