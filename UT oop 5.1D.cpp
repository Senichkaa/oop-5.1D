#include "pch.h"
#include "CppUnitTest.h"
#include "../oop 5.1D/Exception.cpp"
#include "../oop 5.1D/Triad.cpp"
#include "../oop 5.1D/InheritedException.cpp"
#include "../oop 5.1D/FuzzyNumber.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UToop51D
{
	TEST_CLASS(UToop51D)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			FuzzyNumber V(4, 1, 7), L(6, 3, 9);
			FuzzyNumber C = V + L;
			Assert::AreEqual(C.get_x(), 10.0);
		}
	};
}
