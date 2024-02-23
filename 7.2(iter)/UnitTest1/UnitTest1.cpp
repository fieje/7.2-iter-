#include "pch.h"
#include "CppUnitTest.h"
#include "../7.2(iter)/Source.cpp"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestSwapMinEvenWithMaxOdd)
        {
            const int n = 3;
            const int m = 3;
            int** matrix = new int* [n];
            for (int i = 0; i < n; ++i)
                matrix[i] = new int[m];

            matrix[0][0] = 6; 
            matrix[0][1] = 5;
            matrix[0][2] = 3;
            matrix[1][0] = 4;
            matrix[1][1] = 6;
            matrix[1][2] = 9;
            matrix[2][0] = 8;
            matrix[2][1] = 7;
            matrix[2][2] = 1;

            SwapMinEvenWithMaxOdd(matrix, n, m);
            Assert::AreEqual(6, matrix[0][0]);
            Assert::AreEqual(5, matrix[0][1]);
            Assert::AreEqual(3, matrix[0][2]);
            Assert::AreEqual(4, matrix[1][0]);
            Assert::AreEqual(6, matrix[1][1]); 
            Assert::AreEqual(9, matrix[1][2]);
            Assert::AreEqual(8, matrix[2][0]);
            Assert::AreEqual(7, matrix[2][1]);
            Assert::AreEqual(1, matrix[2][2]);

 
            for (int i = 0; i < n; ++i)
                delete[] matrix[i];
            delete[] matrix;
        }
    };
}