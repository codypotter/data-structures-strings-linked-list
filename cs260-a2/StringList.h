#pragma once
#include<string>

using namespace std;

class StringList {
public:
	struct node {
		node* previousNode;
		node* nextNode;
		string data;
	};
	StringList();
	~StringList();
	void removeAll();
	void insert(string stringToInsert);
	int remove(string stringToRemove);
	int totalItems();
	void printForward();
	void printReverse();
	int find(string stringToFind, node* theHead);
	int findLetter(char charToFind);
private:
	node* head;
};

