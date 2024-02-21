#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07_2/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestCreate)
		{
			int n = 3;
			int k = 3;
			int Low = 7, High = 65;
			int** a = new int* [n];
			for (int i = 0; i < n; i++)
				a[i] = new int[n];

			Create(a, k, n, Low, High);

			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					Assert::IsTrue(a[i][j] >= Low && a[i][j] <= High);

			for (int i = 0; i < n; i++)
				delete[] a[i];
			delete[] a;
		}

		TEST_METHOD(TesttheMinimumElementOfTheMainDiagonal)
		{
			const int k = 3;
			const int n = 3;

			int** a = new int* [k];
			for (int i = 0; i < k; i++)
				a[i] = new int[n];

			a[0][0] = 42;
			a[1][1] = 56;
			a[2][2] = 78;

			theMinimumElementOfTheMainDiagonal(a, k, n);

			Assert::AreEqual(42, a[0][0]);

			DeleteMatrix(a, k);
		}
	};
}