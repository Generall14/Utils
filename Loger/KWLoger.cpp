#include "KWLoger.hpp"
#include "KWWriter.hpp"

/**
 * Podstawowy konstruktor.
 */
KWLoger::KWLoger():
	globalEnable(true)
{

}

/**
 * Konstruktor z automatycznym dodaniem writera.
 * @param writer - Wskaźnik na writer (KWLoger przejmuje odpowiedzialność za niszczenie dodanych obiektów!).
 * @param levels - Określa poziomy w których ma być stosowawny writer, wartość podawana jako suma bitowa KWWriter::mode.
 */
KWLoger::KWLoger(KWWriter* writer, int levels):
	KWLoger()
{
	this->addWriter(writer, levels);
}

KWLoger::~KWLoger()
{
	for(int i=0;i<writerList.size();++i)
		delete writerList[i];
}

void KWLoger::setEnable(bool enable)
{
	globalEnable = enable;
}

/**
 * Funkcja dodaje writer do obiektu.
 * @param writer - Wskaźnik na writer (KWLoger przejmuje odpowiedzialność za niszczenie dodanych obiektów!).
 * @param levels - Określa poziomy w których ma być stosowawny writer, wartość podawana jako suma bitowa KWWriter::mode.
 */
void KWLoger::addWriter(KWWriter* writer, int levels)
{
	writerList.push_back(writer);

	if(levels&((int)mode::INFO))
		infoList.push_back(writer);
	if(levels&((int)mode::TRACE))
		traceList.push_back(writer);
	if(levels&((int)mode::DEBUG))
		debugList.push_back(writer);
	if(levels&((int)mode::WARNING))
		warningList.push_back(writer);
	if(levels&((int)mode::ERROR))
		errorList.push_back(writer);
}

/**
 * Funkcja loguje wiadomość poziomu Info dla wszystkich writerów w których określono dany poziom logowania.
 * @param logs - Wejściowy string.
 */
void KWLoger::logInfo(std::string logs)
{
	if(globalEnable)
		this->log(logs, &infoList, INFO);
}

/**
 * Funkcja loguje wiadomość poziomu Trace dla wszystkich writerów w których określono dany poziom logowania.
 * @param logs - Wejściowy string.
 */
void KWLoger::logTrace(std::string logs)
{
	if(globalEnable)
		this->log(logs, &traceList, TRACE);
}

/**
 * Funkcja loguje wiadomość poziomu Debug dla wszystkich writerów w których określono dany poziom logowania.
 * @param logs - Wejściowy string.
 */
void KWLoger::logDebug(std::string logs)
{
	if(globalEnable)
		this->log(logs, &debugList, DEBUG);
}

/**
 * Funkcja loguje wiadomość poziomu Warning dla wszystkich writerów w których określono dany poziom logowania.
 * @param logs - Wejściowy string.
 */
void KWLoger::logWarning(std::string logs)
{
	if(globalEnable)
		this->log(logs, &warningList, WARNING);
}

/**
 * Funkcja loguje wiadomość poziomu Error dla wszystkich writerów w których określono dany poziom logowania.
 * @param logs - Wejściowy string.
 */
void KWLoger::logError(std::string logs)
{
	if(globalEnable)
		this->log(logs, &errorList, ERROR);
}

/**
 * Funkcja przekazuje wiadomości do wskazanej listy writerów.
 * @param log - Wiadomość.
 * @param lista - Lista writerów.
 * @param mod - Poziom logowania.
 */
void KWLoger::log(std::string log, std::vector<KWWriter*>* lista, mode mod)
{
	std::vector<KWWriter*>::iterator it;
	for(it=lista->begin();it!=lista->end();it++)
		(*it)->write(log, mod);
}
