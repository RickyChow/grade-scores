#include "CppUnitTest.h"

#include "../scoresorter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


const static ScoreEntry testSet1[] = 
{
	{ "TERESSA", "BUNDY", 88 },
	{ "ALLAN", "SMITH", 70 },
	{ "MADISON", "KING", 88 },
	{ "FRANCIS", "SMITH", 85 }
};

const static ScoreEntry expected1[] =
{
	{ "TERESSA", "BUNDY", 88 },
	{ "MADISON", "KING", 88 },
	{ "FRANCIS", "SMITH", 85 },
	{ "ALLAN", "SMITH", 70 }
};

const static ScoreEntry testSet2[] =
{
	{ "TERESSA", "BUNDY", -2 },
	{ "TERESSA", "BUNDY", 50 },
};

const static ScoreEntry expected2[] =
{
	{ "TERESSA", "BUNDY", 50 },
	{ "TERESSA", "BUNDY", -2 },
};

const static ScoreEntry testSet3[] =
{
	{ "TERESSA", "BUNDY", 0 },
	{ "TERESSA", "SMITH", 0 },
	{ "TERESSA", "KING", 0 },
	{ "TERESSA", "SMITH", 0 }
};

const static ScoreEntry expected3[] =
{
	{ "TERESSA", "BUNDY", 0 },
	{ "TERESSA", "KING", 0 },
	{ "TERESSA", "SMITH", 0 },
	{ "TERESSA", "SMITH", 0 }
};

class ScoreSorterMock : public ScoreSorter
{
public:
	ScoreSorterMock(int testNum)
		:testCase(testNum) {}

	bool loadEntries() override
	{
		const ScoreEntry* testData = NULL;
		int testDataSize = 0;

		switch (testCase)
		{
		case 1:
			testData = testSet1;
			testDataSize = sizeof(testSet1) / sizeof(ScoreEntry);
			break;
		case 2:
			testData = testSet2;
			testDataSize = sizeof(testSet2) / sizeof(ScoreEntry);
			break;
		case 3:
			testData = testSet3;
			testDataSize = sizeof(testSet3) / sizeof(ScoreEntry);
			break;
		default:
			return false;
		}

		for (int i = 0; i < testDataSize; ++i)
		{
			_entries.push_back(testData[i]);
		}
		return true;
	}
private:
	int testCase;
};

namespace gradescorestest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(OriginalTest)
		{
			ScoreSorterMock testSorter(1);
			testSorter.loadEntries();
			testSorter.sort();

			Assert::IsTrue(testSorter.entries().size() == 4);

			for (int i = 0; i < testSorter.entries().size(); ++i)
			{
				Assert::IsTrue(testSorter.entries()[i] == expected1[i]);
			}
		}

		TEST_METHOD(NegativeScores)
		{
			ScoreSorterMock testSorter(2);
			testSorter.loadEntries();
			testSorter.sort();

			Assert::IsTrue(testSorter.entries().size() == 2);

			for (int i = 0; i < testSorter.entries().size(); ++i)
			{
				Assert::IsTrue(testSorter.entries()[i] == expected2[i]);
			}
		}

		TEST_METHOD(LastNameSorting)
		{
			ScoreSorterMock testSorter(3);
			testSorter.loadEntries();
			testSorter.sort();

			Assert::IsTrue(testSorter.entries().size() == 4);

			for (int i = 0; i < testSorter.entries().size(); ++i)
			{
				Assert::IsTrue(testSorter.entries()[i] == expected3[i]);
			}
		}
	};
}