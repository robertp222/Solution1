#ifndef BIGINTEGERINTREP_H
#define BIGINTEGERINTREP_H
#include <iostream>

using namespace std;

class Element
{
public:
	char data = 0;
	Element* next;
	Element* prev;

	Element(char data0) { this->next = NULL; this->prev = NULL, this->data = data0; }

	int getDataAsInt() {
		int res = data - '0';
		return (res >= 0 && res <= 9) ? (res) : (0);
	}
};

class BigNumberIntRep
{
public:
	Element* first = NULL;
	Element* last = NULL;
	int size = 0;

	int getSign();

	BigNumberIntRep();

	Element* getElement(int position);

	void addElement(char data, int position);
	
	void addElement(int data, int position);

	void showList();

	void removeElement(int position);

	void removeAll();

	void trim();

};
#endif