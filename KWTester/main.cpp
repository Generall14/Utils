#include <iostream>
#include <fstream>

#define NOCOLORS
#include "KWTester.hpp"

using namespace std;

class mtest : public KWTest
{
public:
	mtest():KWTest("Test konstr 1"){}
protected:
	void Tests()
	{
		_CODE(int i=1;)
		_KWTEST(1==i)
		_KWTEST(2==i)
	}
};
class btest : public KWTest
{
public:
	btest():KWTest("Test konst 2r"){}
protected:
	void Tests()
	{
		_KWTEST(7==7)
		_KWTEST(8==8)
	}
};

int main()
{
	cout << "Test testera" << endl;
	
	KWTester a("aa.txt", KWTester::All, KWTester::All);
	
	a.AddTest(new mtest());
	a.AddTest(new btest());
	a.Run();
	
	cout << a.getTestCount() << endl;
	
	return 0;
}