#include "pch.h"
#include "CppUnitTest.h"
#include "../8_1.cpp"
//#include "../8_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t = 0;

			const int n = 8;
			int a[n];

			t = UnitTest(a, n);
			Assert::AreEqual(t, 1717986912);
		}
	};
}
