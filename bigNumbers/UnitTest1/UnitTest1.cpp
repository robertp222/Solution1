#include "pch.h"
#include "CppUnitTest.h"
#include "../BigInteger.h"
#include "../BigInteger.cpp"
#include "../BigNumberIntRep.h"
#include "../BigNumberIntRep.cpp"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(BigIntegerTest)
	{
	public:
		TEST_METHOD(ConstructorAndGetAsString)
		{
			char* var = "12345678";
			BigInteger* num = new BigInteger(var);
			char* var2 = num->getAsString();
			Assert::AreEqual(string(var), string(var2));
		}
		TEST_METHOD(compare)
		{
			Assert::AreEqual(1, BigInteger("-12345678").compare(new BigInteger("-12345679")));
			Assert::AreEqual(0, BigInteger("12345678").compare(new BigInteger("12345678")));
			Assert::AreEqual(-1, BigInteger("12345678").compare(new BigInteger("12345679")));
			Assert::AreEqual(1, BigInteger("12345678").compare(new BigInteger("-12345678")));
			Assert::AreEqual(-1, BigInteger("-12345678").compare(new BigInteger("12345678")));
			Assert::AreEqual(1, BigInteger("12345679").compare(new BigInteger("12345678")));
			Assert::AreEqual(-1, BigInteger("-12345679").compare(new BigInteger("-12345678")));

			Assert::AreEqual(-1, BigInteger("-12345678").compare(new BigInteger("-12345679"), true));
			Assert::AreEqual(0, BigInteger("12345678").compare(new BigInteger("12345678"), true));
			Assert::AreEqual(0, BigInteger("-12345678").compare(new BigInteger("-12345678"), true));
			Assert::AreEqual(-1, BigInteger("12345678").compare(new BigInteger("12345679"), true));
			Assert::AreEqual(0, BigInteger("12345678").compare(new BigInteger("-12345678"), true));
			Assert::AreEqual(0, BigInteger("-12345678").compare(new BigInteger("12345678"), true));
			Assert::AreEqual(1, BigInteger("12345679").compare(new BigInteger("12345678"), true));
			Assert::AreEqual(1, BigInteger("-12345679").compare(new BigInteger("-12345678"), true));

		}

		TEST_METHOD(getDataAsInt)
		{
			Assert::AreEqual(0, Element('0').getDataAsInt());
			Assert::AreEqual(1, Element('1').getDataAsInt());
			Assert::AreEqual(9, Element('9').getDataAsInt());
		}

		TEST_METHOD(add)
		{
			Assert::AreEqual(string("130"), string(BigInteger("120").add(new BigInteger("10"))->getAsString()));
			Assert::AreEqual(string("110"), string(BigInteger("120").add(new BigInteger("-10"))->getAsString()));
			Assert::AreEqual(string("-2"), string(BigInteger("-12").add(new BigInteger("10"))->getAsString()));
			Assert::AreEqual(string("-22"), string(BigInteger("-12").add(new BigInteger("-10"))->getAsString()));
			Assert::AreEqual(string("22"), string(BigInteger("12").add(new BigInteger("10"))->getAsString()));
			Assert::AreEqual(string("40"), string(BigInteger("29").add(new BigInteger("11"))->getAsString()));
			Assert::AreEqual(string("44"), string(BigInteger("29").add(new BigInteger("15"))->getAsString()));
			Assert::AreEqual(string("48"), string(BigInteger("29").add(new BigInteger("19"))->getAsString()));
			Assert::AreEqual(string("28"), string(BigInteger("9").add(new BigInteger("19"))->getAsString()));
			Assert::AreEqual(string("10000000"), string(BigInteger("9999999").add(new BigInteger("1"))->getAsString()));

			Assert::AreEqual(string("2"), string(BigInteger("12").add(new BigInteger("-10"))->getAsString()));

			Assert::AreEqual(string("-130"), string(BigInteger("-120").add(new BigInteger("-10"))->getAsString()));
			Assert::AreEqual(string("-110"), string(BigInteger("-120").add(new BigInteger("10"))->getAsString()));

			Assert::AreEqual(string("110"), string(BigInteger("120").add(new BigInteger("-10"))->getAsString()));
			Assert::AreEqual(string("-110"), string(BigInteger("-120").add(new BigInteger("10"))->getAsString()));
			Assert::AreEqual(string("-130"), string(BigInteger("-120").add(new BigInteger("-10"))->getAsString()));
			Assert::AreEqual(string("130"), string(BigInteger("10").add(new BigInteger("120"))->getAsString()));
			Assert::AreEqual(string("-110"), string(BigInteger("10").add(new BigInteger("-120"))->getAsString()));
			Assert::AreEqual(string("110"), string(BigInteger("-10").add(new BigInteger("120"))->getAsString()));
			Assert::AreEqual(string("-130"), string(BigInteger("-10").add(new BigInteger("-120"))->getAsString()));
		}


		TEST_METHOD(substract)
		{
			Assert::AreEqual(string("-220"), string(BigInteger("2").substract(new BigInteger("222"))->getAsString()));
			Assert::AreEqual(string("2"), string(BigInteger("12").substract(new BigInteger("10"))->getAsString()));
			Assert::AreEqual(string("22"), string(BigInteger("12").substract(new BigInteger("-10"))->getAsString()));
			Assert::AreEqual(string("-2"), string(BigInteger("-12").substract(new BigInteger("-10"))->getAsString()));
			Assert::AreEqual(string("-22"), string(BigInteger("-12").substract(new BigInteger("10"))->getAsString()));

			Assert::AreEqual(string("130"), string(BigInteger("120").substract(new BigInteger("-10"))->getAsString()));
			Assert::AreEqual(string("-110"), string(BigInteger("-120").substract(new BigInteger("-10"))->getAsString()));
			Assert::AreEqual(string("-130"), string(BigInteger("-120").substract(new BigInteger("10"))->getAsString()));

			Assert::AreEqual(string("110"), string(BigInteger("120").substract(new BigInteger("10"))->getAsString()));
			Assert::AreEqual(string("130"), string(BigInteger("120").substract(new BigInteger("-10"))->getAsString()));
			Assert::AreEqual(string("-130"), string(BigInteger("-120").substract(new BigInteger("10"))->getAsString()));
			Assert::AreEqual(string("-110"), string(BigInteger("-120").substract(new BigInteger("-10"))->getAsString()));

			Assert::AreEqual(string("-110"), string(BigInteger("10").substract(new BigInteger("120"))->getAsString()));
			Assert::AreEqual(string("130"), string(BigInteger("10").substract(new BigInteger("-120"))->getAsString()));
			Assert::AreEqual(string("-130"), string(BigInteger("-10").substract(new BigInteger("120"))->getAsString()));
			Assert::AreEqual(string("110"), string(BigInteger("-10").substract(new BigInteger("-120"))->getAsString()));

		}
	};
}
