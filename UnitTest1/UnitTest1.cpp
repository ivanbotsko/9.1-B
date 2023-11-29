#include "pch.h"
#include "CppUnitTest.h"
#include "../9.1 B/9.1 B.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestRandomSpecialty)
		{
			// Перевірка, що getRandomSpecialty() повертає коректні значення спеціальностей
			Specialty specialty = getRandomSpecialty();

			Assert::IsTrue(specialty == ComputerScience || specialty == Informatics || specialty == MathematicsAndEconomics || specialty == PhysicsAndInformatics || specialty == LaborEducation, L"Invalid specialty returned!");
		}
	};
}
