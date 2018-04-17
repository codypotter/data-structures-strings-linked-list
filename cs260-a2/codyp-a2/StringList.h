/*
Program:	CS-260 A2
Author:		Cody Potter
Date:		2018-04-16
Purpose:	Ordered List class for a doubly linked list
*/
#pragma once
#include<string>

using namespace std;

class StringList {
public:
	struct Node {
		Node* previousNode;
		Node* nextNode;
		string data;
	};
	Node * head;
	StringList();
	~StringList();
	void removeAll();
	void insert(string stringToInsert);
	int remove(string stringToRemove);
	int totalItems();
	void printForward();
	void printReverse();
	int find(string stringToFind, Node* theHead);
	int findLetter(char charToFind, Node* theHead);
	
};

