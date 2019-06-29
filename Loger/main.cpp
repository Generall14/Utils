#include <iostream>
#include "KWWriterCout.hpp"
#include "KWWriterFile.hpp"
#include "KWFormater.hpp"
#include "KWLoger.hpp"
#include "KWSimpleFormater.hpp"

using namespace std;

int main()
{
	cout << "KWLoger test" << endl;

	KWWriter* writer = new KWWriterCout(new KWSimpleFormater("\tdupa\t"));
	KWWriter* filewriter = new KWWriterFile(new KWFormater(), "fileout.txt");

	writer->write(writer->description()+"\n", KWLoger::DEBUG);

	int mod = KWLoger::DEBUG | KWLoger::ERROR | KWLoger::INFO | KWLoger::TRACE | KWLoger::WARNING;
	KWLoger* log = new KWLoger();
	log->addWriter(writer, mod);
	log->addWriter(filewriter, mod);

	log->logDebug("debug\n");
	log->logError("erroe\n");
	log->logInfo("info\n");
	log->logTrace("trace\n");
	log->logWarning("warning\n");

	char z;
	while(z!='x')
	{
		cin >> z;
		log->logWarning("12345678901234567890123456789012345678901234567890\n");
	}

	delete log;

	return 0;
}
