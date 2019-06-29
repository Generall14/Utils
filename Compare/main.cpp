#include <iostream>
#include <fstream>

#include <KWTester.hpp>
#include <KWTest.hpp>
#include <cmath>
#include <limits>
#include "KWComparator.hpp"

using namespace std;

class floatComparatorTest : public KWTest
{
public:
    floatComparatorTest():KWTest("floatComparatorTest"){}
protected:
    void Tests()
    {
		_KWTEST(!kwa::ie((float).666, (float).667))
		_KWTEST(kwa::ie((float).666, (float).666))
		_KWTEST(!kwa::ie((float).666, (float).665))

		_KWTEST(kwa::ile((float).666, (float).667))
		_KWTEST(kwa::ile((float).666, (float).666))
		_KWTEST(!kwa::ile((float).666, (float).665))

		_KWTEST(kwa::il((float).666, (float).667))
		_KWTEST(!kwa::il((float).666, (float).666))
		_KWTEST(!kwa::il((float).666, (float).665))

		_KWTEST(!kwa::ige((float).666, (float).667))
		_KWTEST(kwa::ige((float).666, (float).666))
		_KWTEST(kwa::ige((float).666, (float).665))

		_KWTEST(!kwa::ig((float).666, (float).667))
		_KWTEST(!kwa::ig((float).666, (float).666))
		_KWTEST(kwa::ig((float).666, (float).665))
    }
};

class doubleComparatorTest : public KWTest
{
public:
    doubleComparatorTest():KWTest("doubleComparatorTest"){}
protected:
    void Tests()
    {
		_KWTEST(!kwa::ie((double).666, (double).667))
		_KWTEST(kwa::ie((double).666, (double).666))
		_KWTEST(!kwa::ie((double).666, (double).665))

		_KWTEST(kwa::ile((double).666, (double).667))
		_KWTEST(kwa::ile((double).666, (double).666))
		_KWTEST(!kwa::ile((double).666, (double).665))

		_KWTEST(kwa::il((double).666, (double).667))
		_KWTEST(!kwa::il((double).666, (double).666))
		_KWTEST(!kwa::il((double).666, (double).665))

		_KWTEST(!kwa::ige((double).666, (double).667))
		_KWTEST(kwa::ige((double).666, (double).666))
		_KWTEST(kwa::ige((double).666, (double).665))

		_KWTEST(!kwa::ig((double).666, (double).667))
		_KWTEST(!kwa::ig((double).666, (double).666))
		_KWTEST(kwa::ig((double).666, (double).665))
    }
};

int main()
{
	cout << "KWAlgs: main.cpp" << endl;
	KWTester tester;
	tester.AddTest(new floatComparatorTest());
	tester.AddTest(new doubleComparatorTest());
	tester.Run();

	std::cout << std::numeric_limits<double>::epsilon() << endl;

	return 0;
}
