#ifndef BIGNUMBERS_CPP
#define BIGNUMBERS_CPP
#include <iostream>
#include "BigNumberIntRep.h"
#include "BigInteger.h"

using namespace std;

void showAllLists(BigInteger** tab, int n)
{
	for (int i = 0; i < n; i++)
	{
		tab[i]->print();
	}
}
int power(int number, int index)
{
	if (index == 0)
		return 1;
	else
	{
		for (int i = 2; i <= index; i++)
			number *= number;
		return number;
	}

}

BigInteger * findMinMax(BigInteger** tab, int n, bool max)
{
	int index = 0;
	for (int i = 1; i < n; i++) {
		int res = tab[index]->compare(tab[i]);
		if ((max && res < 0 ) || (!max && res > 0)) {
			index = i;
		}
	}
	return tab[index];
}

void substitute(BigInteger** tab, char* function, int len)
{
	int first = 0, second = 0, third = 0, counter = 0, iterator = len - 1;
	char operation;
	while (function[iterator] != ' ')
	{
		third += (int(function[iterator]) - 48) * power(10, counter);
		iterator--;
		counter++;
	}
	counter = 0;
	iterator--;
	operation = function[iterator];
	iterator -= 2;
	while (function[iterator] != ' ')
	{
		second += (int(function[iterator]) - 48) * power(10, counter);
		iterator--;
		counter++;
	}
	counter = 0;
	iterator -= 3;
	while (iterator >= 0)
	{
		first += (int(function[iterator]) - 48) * power(10, counter);
		iterator--;
		counter++;
	}
	if (operation == '+')
		tab[first] = tab[second]->add(tab[third]);
	else
		tab[first] = tab[second]->substract(tab[third]);
}

int main()
{
	int n;
	cin >> n;

	BigInteger** tab = new BigInteger* [n];

	for (int i = 0; i < n; i++)
	{
		tab[i] = new BigInteger();
	}

	char x;
	for (int i = -1; i < n; i++)
	{
		while ((x = char(getchar())) != '\n' && x != EOF)
		{
			tab[i]->getIntRep()->addElement(x, tab[i]->getIntRep()->size + 1);
		}
	}
	char* function = new char[30];
	for (int i = 0; i < 30; i++)
	{
		function[i] = NULL;
	}
	int i = 0;
	while (function[0] != 'q')
	{
		do
		{
			function[i] = char(getchar());
			i++;
		} while (function[i - 1] != '\n');


		if (function[0] == '?')
		{
			showAllLists(tab, n);
		}
		else if (function[0] == 'm' && function[1] == 'i' && function[2] == 'n')
		{
			findMinMax(tab, n, false)->print();
		}
		else if (function[0] == 'm' && function[1] == 'a' && function[2] == 'x')
		{
			findMinMax(tab, n, true)->print();
		}
		else if (function[0] == 'q')
		{
			break;
		}
		else
		{
			substitute(tab, function, i - 1);
		}

		i = 0;
	}
	delete* tab;
	delete[](function);

	return 0;
}

#endif