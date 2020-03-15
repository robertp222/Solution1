#include "pch.h"
#include "CppUnitTest.h"
#include "../../bigNumbers/BigInteger.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(BigIntegerTest)
	{
	public:
		TEST_METHOD(Test1)
		{
			char* var = "12345678";
			BigInteger* num = new BigInteger();
			char* var2 = num->getAsString();
			Assert::AreEqual(1, 1);
			Assert::AreEqual(var, var2);
		}
	};
}
