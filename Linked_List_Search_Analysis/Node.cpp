#pragma once

class Node {
private:
	int Key;
	int Data;
	Node* Next;
	Node* Prev;

public:
	Node();
	Node(int key, int data);
	~Node();
	int getData();
	void setData(int data);
	int getKey();
	Node* getPrev();
	Node* getNext();

	bool operator> (const Node& a);
	bool operator< (const Node& a);
	bool operator== (const Node& a);
};