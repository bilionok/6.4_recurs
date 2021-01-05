#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab-6.4(2).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest642
{
	TEST_CLASS(UnitTest642)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t[8] = { -5, -2, 2 , 1, 3, 10, 1, 8 };

			int P = P1(t,5,1,1);

			Assert::AreEqual(P, -12);
		}
	};
}
