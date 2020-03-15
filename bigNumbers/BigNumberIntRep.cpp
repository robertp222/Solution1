#include "./BigNumberIntRep.h"

#include <iostream>

BigNumberIntRep::BigNumberIntRep()
	{
		first = NULL;
		last = NULL;
		size = 0;
	}

int BigNumberIntRep::getSign() {
	if (first == NULL) {
		return 0;
	} else {
		return (first->data == '-') ? (-1) : (1);
	}
}

Element* BigNumberIntRep::getElement(int position)
	{
		Element* temp = this->first;
		for (int i = 1; i < position; i++)
		{
			temp = temp->next;
		}
		return temp;
	}

void BigNumberIntRep::addElement(char data, int position)
	{
		Element* x = new Element(data);

		if (this->size == 0)
		{
			this->first = this->last = x;
		}
		else if (position == 1)
		{
			Element* temp = this->first;
			temp->prev = x;
			x->next = temp;
			this->first = x;
		}
		else if (position > this->size)
		{
			this->last->next = x;
			x->prev = this->last;
			this->last = x;
		}
		else
		{
			Element* temp = getElement(position);
			Element* before = temp->prev;
			before->next = x;
			x->prev = before;
			temp->prev = x;
			x->next = temp;
		}

		size++;
	}

void BigNumberIntRep::addElement(int data, int position) {
	char cdata = '0' + data;
	addElement(cdata, position);
}

void BigNumberIntRep::showList()
	{
		Element* temp = this->first;
		while (temp != NULL)
		{
			cout << temp->data;
			temp = temp->next;
		}
		cout << endl;
	}

void BigNumberIntRep::removeElement(int position)
	{
		if (position == 1 && size > 1)
		{
			Element* temp = this->first;
			this->first = this->first->next;
			first->prev = NULL;
			delete temp;
		}
		else if (size == 1)
		{
			this->first = this->last = NULL;
			delete this->first;
		}
		else if (position == size)
		{
			Element* temp = this->last;
			this->last = this->last->prev;
			last->next = NULL;
			delete temp;
		}
		else
		{
			Element* temp = getElement(position);
			Element* before = temp->prev;
			Element* after = temp->next;
			before->next = after;
			after->prev = before;
			delete temp;
		}
		size--;
	}

void BigNumberIntRep::removeAll()
	{
		while (this->size > 0)
			removeElement(this->size);
	}

/*
remove additional 0 from the begining of number
*/
void BigNumberIntRep::trim() {
	bool proceed = true;
	while (proceed) {
		proceed = false;
		if (first->data == '0') {
			this->removeElement(1);
			proceed = true;
		}
		else if (first->data == '-' && first->next->data == '0') {
			this->removeElement(2);
			proceed = true;
		}
	}
}
