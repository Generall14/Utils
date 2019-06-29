#include <cstdlib>
#include <iostream>
#include <fstream>

//#define NOCOLORS
#include "KWColors.hpp"

using namespace std;


int main()
{
	cout << "Test KWColors - KWDye\n";
	cout << KWDye("d", 0) << KWDye("rr", 1) << Red() << "asd \n\n";
	cout << KWDye(2) << "asdddd\n";
	cout << "ss " << KWDye(0) << "aaa\n\n";
	cout << Red("aa\n");
	cout << Green("aa\n");
	cout << Blue("aa\n");
	cout << Black("aa\n");
	cout << Brown("aa\n");
	cout << Magenta("aa\n");
	cout << Cyan("aa\n");
	cout << LightGray("aa\n");
	cout << Red() << "aaaaa" << ResetColor() << "a asdad\n\n";

	return 0;
}
