
#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

int MinAbs(const int a[], int n);
int SumAfterZero(const int a[], int n);
void Rearrange(int a[], int n);

namespace UnitTest64
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMinAbs)
        {
            int a[5] = { -8, 4, -2, 7, 9 };

            Assert::AreEqual(-2, MinAbs(a, 5));
        }

        TEST_METHOD(TestSumAfterZero)
        {
            int a[6] = { 3, 0, -5, 2, -4, 6 };

            Assert::AreEqual(17, SumAfterZero(a, 6));
        }

        TEST_METHOD(TestRearrange)
        {
            int a[6] = { 1, 2, 3, 4, 5, 6 };

            Rearrange(a, 6);

            int expected[6] = { 2, 4, 6, 1, 3, 5 };

            for (int i = 0; i < 6; i++)
                Assert::AreEqual(expected[i], a[i]);
        }
    };
}
