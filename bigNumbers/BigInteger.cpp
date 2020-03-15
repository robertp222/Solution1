#include <iostream>
#include "BigNumberIntRep.h"
#include "BigInteger.h"

	BigNumberIntRep* BigInteger::getIntRep() {
		return intNumbRep;
	}

	/*
		number should be initiated by list
		TODO: change it to initiate from different sources, but not List instance
	*/
	BigInteger::BigInteger(BigNumberIntRep* _intNumbRep) {
		intNumbRep = _intNumbRep;
	}
	
	/*
		init for unit tests
	*/
	BigInteger::BigInteger(char* numberAsStr) {
		intNumbRep = new BigNumberIntRep();
		size_t size = strlen(numberAsStr);
		for (int i = 0; i < size; i++) {
			intNumbRep->addElement(numberAsStr[i], i + 1);
		}
	}

	BigInteger::BigInteger() {
		intNumbRep = new BigNumberIntRep();
	};

	/*
	destructor, release also internal representation
	*/
	BigInteger::~BigInteger() {
		if (intNumbRep != NULL) {
			intNumbRep->removeAll();
			delete[](intNumbRep);
		}

	}

	/*
		return char* representation
		WARNING: may not work if number is too big
	*/
	char* BigInteger::getAsString() {
		int size = intNumbRep->size;
		char* str = new char(size + 1);

		for (int i = 0; i < size; i++) {
			str[i] = intNumbRep->getElement(i + 1)->data;
		}
		str[size] = '\0';
		return str;
	}

	/*
		return -1: when numb1 < numb2
		return 0: when numb1 = numb2
		return 1: when numb1 > numb2
		== greater then
		ignoreSign: compare numbers (false) by default or modulo numbers (true)
	*/
	int BigInteger::compare(BigInteger* numb, bool ignoreSign) {

		BigNumberIntRep* num1 = getIntRep();
		BigNumberIntRep* num2 = numb->getIntRep();
		bool isNegative1 = (num1->getSign() == -1) ? (true) : (false);
		bool isNegative2 = (num2->getSign() == -1) ? (true) : (false);

		int sizeWithoutSign1 = (isNegative1) ? (num1->size - 1) : (num1->size);
		int sizeWithoutSign2 = (isNegative2) ? (num2->size - 1) : (num2->size);

		//if not ignore sign check using only sign
		if (!ignoreSign) {
			if (isNegative1 && !isNegative2) {
				return -1;
			}
			else if (!isNegative1 && isNegative2)
			{
				return 1;
			}
		}

		// sprawdzeni po iloœci znaków
		int grater = (sizeWithoutSign1 - sizeWithoutSign2 >= 0) ? ((sizeWithoutSign1 - sizeWithoutSign2 == 0)?(0):1) : (-1);
		int signMultiplier = ((!isNegative1 && !isNegative2) || ignoreSign) ? (1) : (-1);
		if (grater != 0)
		{
			return grater * signMultiplier;
		} 
		
		// je¿eli maj¹ t¹ sam¹ liczbê znaków, porównywanie znak po znaku
		for (int i = 1; i <= sizeWithoutSign1 ; i++)
		{
			int val1 = num1->getElement(i + ((isNegative1) ? (1) : (0)) )->data;
			int val2 = num2->getElement(i + ((isNegative2) ? (1) : (0)))->data;
			grater = (val1- val2 >=0) ? ((val1 - val2 == 0)?(0):1) : (-1);
			if (grater != 0)
			{
				return grater * signMultiplier;
			}
		}
		//je¿eli tutaj doszed³, to znaczy, ¿e wszystkie znaki s¹ takie same
		return 0;
	}

	/*
		adds two bigNumbers and return result as third
	*/
	BigInteger* BigInteger::add(BigInteger* numb) {
		return operation(numb, true);
	}

	/*
	substract second from first and return result as third
	*/
	BigInteger* BigInteger::substract(BigInteger* numb) {
		return operation(numb, false);
	}

	/*
		adds or substract numbers
	*/
	BigInteger* BigInteger::operation(BigInteger* numb, bool add) {
		char* zero = new char('0');
		bool isNegative1 = (this->getIntRep()->getSign() == -1) ? (true) : (false);
		bool isNegative2 = (numb->getIntRep()->getSign() == -1) ? (true) : (false);

		BigInteger* numb1;
		BigInteger* numb2;
		
		int operSign;
		int resultSign;
		int greater = this->compare(numb, true);
		// for adding - no additional staff
		// when substract, several cases
		if (!add) {
			if ((!isNegative1) && (!isNegative2)) {
				if (greater > 0) {
					numb1 = this;
					numb2 = numb;
					resultSign = 1;
					operSign = -1;
				}
				else if (greater < 0) {
					numb1 = numb;
					numb2 = this;
					resultSign = -1;
					operSign = -1;
				}
				else {
					return new BigInteger(zero);
				}
			}
			else if (isNegative1 && isNegative2) {
				if (greater > 0) {
					numb1 = this;
					numb2 = numb;
					resultSign = -1;
					operSign = -1;
				}
				else if (greater < 0) {
					numb1 = numb;
					numb2 = this;
					resultSign = 1;
					operSign = -1;
				}
				else {
					return new BigInteger(zero);
				}
			}
			else if (!isNegative1 && isNegative2) {
				numb1 = this;
				numb2 = numb;
				operSign = 1;
				resultSign = 1;
			}
			else {
				numb1 = this;
				numb2 = numb;
				operSign = 1;
				resultSign = -1;
			}
		}  else {
			// adding
			if (!isNegative1 && !isNegative2) {
				numb1 = this;
				numb2 = numb;
				resultSign = 1;
				operSign = 1;
			}
			else if (isNegative1 && isNegative2) {
				numb1 = this;
				numb2 = numb;
				resultSign = -1;
				operSign = 1;
			} 
			else if (!isNegative1 && isNegative2) {
				if (greater > 0) {
					numb1 = this;
					numb2 = numb;
					resultSign = 1;
					operSign = -1;
				}
				else if (greater < 0) {
					numb1 = numb;
					numb2 = this;
					resultSign = -1;
					operSign = -1;
				}
				else {
					return new BigInteger(zero);
				}
			} 
			else {
				if (greater > 0) {
					numb1 = this;
					numb2 = numb;
					resultSign = -1;
					operSign = -1;
				}
				else if (greater < 0) {
					numb1 = numb;
					numb2 = this;
					resultSign = 1;
					operSign = -1;
				}
				else {
					return new BigInteger(zero);
				}
			}
		}

		isNegative1 = (numb1->getIntRep()->getSign() == -1) ? (true) : (false);
		isNegative2 = (numb2->getIntRep()->getSign() == -1) ? (true) : (false);
		int sizeWithoutSign1 = (isNegative1) ? (numb1->getIntRep()->size - 1) : (numb1->getIntRep()->size);
		int sizeWithoutSign2 = (isNegative2) ? (numb2->getIntRep()->size - 1) : (numb2->getIntRep()->size);
		Element* pointer1 = numb1->getIntRep()->last;
		Element* pointer2 = numb2->getIntRep()->last;
		int max_size = (sizeWithoutSign1 > sizeWithoutSign2) ? (sizeWithoutSign1) : (sizeWithoutSign2);

		BigInteger* result = new BigInteger();
		int mem = 0;

		for (int i = max_size; i > 0; i--) {
			int v1 = (pointer1 != NULL) ? (pointer1->getDataAsInt()) : (0);
			int v2 = (pointer2 != NULL) ? (pointer2->getDataAsInt()) : (0);
			int res = v1 + v2 * operSign;
			
			if (mem > 0) {
				res += mem;
				mem = 0;
			}
			if (res > 9) {
				res -= 10;
				mem++;
			}
			if (res < 0) {
				res += 10;
				mem--;
			}

			result->getIntRep()->addElement(res, 1);
			if (pointer1 != NULL) { pointer1 = pointer1->prev; }
			if (pointer2 != NULL) { pointer2 = pointer2->prev; }
		}
		// if sum of two numbers change digit count ...
		if (mem > 0) {
			result->getIntRep()->addElement(mem, 1);
		}
		if (resultSign == -1) {
			result->getIntRep()->addElement('-', 1);
		}
		result->getIntRep()->trim();

		return result;
	}


	void BigInteger::print() {
		intNumbRep->showList();
	}