/*
Program:	CS-260 A2
Author:		Cody Potter
Date:		2018-04-16
Purpose:	Ordered List class for a doubly linked list 
*/
#include"StringList.h"
#include<iostream>

using namespace std;

int main(void) {
	cout << "Author: Cody Potter" << endl;
	StringList stringList;
	stringList.insert("Bob");
	stringList.insert("David");
	stringList.insert("Alice");
	stringList.insert("Edward");
	stringList.insert("Claire");
	stringList.printForward();
	stringList.printReverse();
	stringList.insert("Bob");
	stringList.insert("Edward");
	stringList.insert("Claire");
	stringList.insert("Claire");
	cout << stringList.find("Alice", stringList.head);
	cout << stringList.find("Bob", stringList.head);
	cout << stringList.find("Claire", stringList.head);
	cout << stringList.find("Edward", stringList.head);
	cout << stringList.findLetter('e', stringList.head);
	stringList.remove("David");
	stringList.remove("Alice");
	stringList.remove("Edward");
	stringList.printForward();
	stringList.printReverse();
	stringList.removeAll();
	stringList.printForward();
	stringList.printReverse();

	return 0;
}