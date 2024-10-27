#include "pch.h"
#include "CppUnitTest.h"
#include "../LB8.1rek/main.cpp"
#define _CRT_SECURE_NO_WARNINGS

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestChange)
        {
            char str[] = "Test aa bb cc string";
            char dest[151];
            dest[0] = '\0';

            char* result = Change(dest, str, 0, 0);

            Assert::AreEqual("Test aa bb cc string", str);

            Assert::AreEqual("Test *** *** *** string", result);
        }


        TEST_METHOD(TestFindStrFunction)
        {
            char str1[101] = "This is a aa bb cc test string.";
            char str2[101] = "This is a test string.";

            Assert::IsTrue(findStr(str1, 0));
            Assert::IsFalse(findStr(str2, 0));
        }

    };
}
