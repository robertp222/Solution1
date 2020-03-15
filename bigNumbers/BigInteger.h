#ifndef BIGINTEGER_H
#define BIGINTEGER_H
#include "BigNumberIntRep.h"


using namespace std;

class BigInteger {
	// internal representation of BigInteger
private:
	BigNumberIntRep* intNumbRep = NULL;


	BigInteger* operation(BigInteger* numb, bool add);

public:
	BigInteger();

	/*
		number should be initiated by list
		TODO: change it to initiate from different sources, but not List instance
	*/
	BigInteger(BigNumberIntRep* _intNumbRep);

	/*
		init for unit tests
	*/
	BigInteger(char* numberAsStr);

	BigNumberIntRep* getIntRep();

	/*
	destructor, release also internal representation
	*/
	~BigInteger();

	/*
		return char* representation
		WARNING: may not work if number is too big
	*/
	char* getAsString();

	/*
		return -1: when numb1 < numb2
		return 0: when numb1 = numb2
		return 1: when numb1 > numb2
		ignoreSign: compare numbers (false) by default or modulo numbers (true)
	*/
	int compare(BigInteger* numb, bool ignoreSign = false);

	/*
		adds two bigNumbers and return result as third
	*/
	BigInteger* add(BigInteger* numb);

	/*
	substract second from first and return result as third
	*/
	BigInteger* substract(BigInteger* numb);

	void print();

};
#endif