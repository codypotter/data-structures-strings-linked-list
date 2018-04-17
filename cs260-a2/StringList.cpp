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
	Node* current = head;
	if (current) {
		if (current->data == stringToFind) {
			return 1 + find(stringToFind, current);
		} else {
			return find(stringToFind, current);
		}
	}
}

int StringList::findLetter(char charToFind) {
	return 0;
}


/*
template <class dataType>
void UnOrderedList<dataType>::prepend(const dataType userValue) {
if (this->isInList(userValue)) { return; }
Node* newNode = new Node;
newNode->value = userValue;
newNode->next = head;

head = newNode;
}

template <class dataType>
void UnOrderedList<dataType>::append(const dataType userValue) {
if (this->isInList(userValue)) { return; }
Node* current = head;
Node* newNode = new Node;
newNode->value = userValue;
newNode->next = NULL;

if (!head) {
head = newNode;
} else {
while (current->next) { current = current->next; }
current->next = newNode;
}

}

template <class dataType>
bool UnOrderedList<dataType>::remove(const dataType valueToRemove) {
Node* current = head;
Node* previous = NULL;

while (current) {
if (current->value == valueToRemove && !previous) {			// first case
head = head->next;
delete current;
current = NULL;
return true;
} else if (current->value == valueToRemove && previous) {	// middle and last case
previous->next = current->next;
delete current;
current = NULL;
return true;
}
previous = current;
current = current->next;
}

if (!current && !previous) { return false; }
return false;
}

template <class dataType>
void UnOrderedList<dataType>::print() {
cout << "The list contains the following " << this->count() << " elements: " << endl;
Node* current = head;

if (!current) { return; }

while (current->next) {
cout << current->value << ", ";
current = current->next;
}
cout << current->value << endl;
return;
}

template <class dataType>
int UnOrderedList<dataType>::count() {
int count = 1;
Node* current = head;
if (!current) {
return 0;
}
while (current) {
count++;
current = current->next;
}
return count;
}

template <class dataType>
int UnOrderedList<dataType>::find(const dataType checkValue) {
Node* current = head;
int positionTracker = 1;
while (current->next) {
current = current->next;
positionTracker++;
if (current->value == checkValue) {
return positionTracker;
}
}
return 0;
}

template <class dataType>
void UnOrderedList<dataType>::removeAll() {
while (head) {
Node* temp = head->next;
delete head;
head = temp;
}
head = NULL;
}

template <class dataType>
bool UnOrderedList<dataType>::isInList(const dataType checkValue) {
Node* current = head;

while (current) {
if (current->value == checkValue) { return true; }
current = current->next;
}
return false;
}
*/


