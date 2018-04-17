/*
Program:	CS-260 A2
Author:		Cody Potter
Date:		2018-04-16
Purpose:	Ordered List class for a doubly linked list
*/
#include "StringList.h"
#include<iostream>
#include<string>

using namespace std;


StringList::StringList() {
	head = NULL;
}


StringList::~StringList() {
	this->removeAll();
}

void StringList::removeAll() {
	while (head) {
		Node* temp = head->nextNode;
		delete head;
		head = temp;
	}
	head = NULL;
}

void StringList::insert(string stringToInsert) {
	Node* current = head;
	Node* newNode = new Node;
	newNode->data = stringToInsert;

	if (!head) {
		head = newNode;
		newNode->nextNode = NULL;
		newNode->previousNode = NULL;
		head->previousNode = NULL;
		return;
	}

	if (newNode->data <= head->data) {
		newNode->nextNode = head;
		head->previousNode = newNode;
		head = newNode;
		head->previousNode = NULL;
		return;
	}

	while (current->nextNode) {
		if (newNode->data <= current->data) {
			current->previousNode->nextNode = newNode;
			newNode->previousNode = current->previousNode;
			newNode->nextNode = current;
			current->previousNode = newNode;
			head->previousNode = NULL;
			return;
		}
		current = current->nextNode;
	}

	if (newNode->data <= current->data) {  
		current->previousNode->nextNode = newNode;
		newNode->previousNode = current->previousNode;
		newNode->nextNode = current;
		current->previousNode = newNode;
		head->previousNode = NULL;
		return;
	}
	current->nextNode = newNode;
	newNode->nextNode = NULL;
	newNode->previousNode = current;
	head->previousNode = NULL;
	return;
		
}

int StringList::remove(string stringToRemove) {
	Node* current = head;
	int removedCount = 0;
	while (current) {
		if (current->data == stringToRemove) {
			if (current == head) {
				head = current->nextNode;
				if (head)
					head->previousNode = NULL;
				delete current;
				current = NULL;
				removedCount++;
			} else if (current) {
				if (current->previousNode)
					current->previousNode->nextNode = current->nextNode;
				if (current->nextNode)
					current->nextNode->previousNode = current->previousNode;
				delete current;
				current = NULL;
				removedCount++;
			}
		}
		if (current)
			current = current->nextNode;
	}
	return removedCount;
}

int StringList::totalItems() {
	Node* current = head;
	int runningTotal = 0;
	while (current) {
		runningTotal++;
		current = current->nextNode;
	}
	return runningTotal;
}

void StringList::printForward() {
	Node* current = head;
	while (current) {
		cout << current->data << ", ";
		current = current->nextNode;
	}
	cout << endl;
}

void StringList::printReverse() {
	Node* current = head;
	if (!head) {
		cout << endl;
		return;
	}
	while (current->nextNode) {
		current = current->nextNode;
	}
	while (current) {
		cout << current->data << ", ";
		current = current->previousNode;
	}
	cout << endl;
}

int StringList::find(string stringToFind, Node* theHead) {
	Node* current = theHead;
	int matchCounter = 0;
	if (current) {
		if (current->data == stringToFind) {
			matchCounter++;
		} 
		return matchCounter + find(stringToFind, current->nextNode);
	}
	return matchCounter;
}

int StringList::findLetter(char charToFind, Node* theHead) {
	Node* current = theHead;
	int letterCounter = 0;
	if (current) {
		for (int i = 0; i < (current->data).length(); i++) {
			if (tolower((current->data)[i]) == tolower(charToFind)) {
				letterCounter++;
			}
		}
		return letterCounter + findLetter(charToFind, current->nextNode);
	} 
}