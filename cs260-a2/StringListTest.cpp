#include"StringList.h"
#include<iostream>

using namespace std;

int main(void) {
	StringList stringList;
	stringList.insert("Richard");
	stringList.insert("Gary");
	stringList.printForward();
	stringList.printReverse();
	stringList.remove("Richard");
	stringList.printForward();
	stringList.removeAll();
	return 1;
}