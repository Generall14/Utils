/**
 * \file KWLoger.hpp
 *
 * Tworzenie logów w programie.
 *
 * \author Wojciech Kogut
 * \startdate 2017.01.17
 * \version v1.00
 * \date 2017.02.22
 */

#ifndef KWLOGER_HPP
#define KWLOGER_HPP

#include <vector>
#include <string>

/**
 * \class KWLoger
 * @brief Główna klasa mechanizmu tworzenia logów.
 *
 * Konfiguracja odbywa się za pomocą konstruktora i/lub funkcji KWLoger::addWriter(...) w której należy podać obiekt z interfejsem KWWriter oraz wyspecyfikować dla jakiego typu
 * logów ma sie odnosić.
 *
 * Dodawanie logów odbywa się za pomocą funkcji logInfo(...) itp., log trafi do każdego obiektu KWWriter który został dodany z odpowiednim poziomem logowania.
 *
 * Włączanie / wyłączanie odbywa się za pomocą metody KWLoger::setEnable(bool).
 */
class KWWriter;
class KWLoger
{
public:
	KWLoger();
	KWLoger(KWWriter* writer, int levels);
	virtual ~KWLoger();

	/** Opis poziomów logowania */
	enum mode
	{
		INFO = 0x01,
		TRACE = 0x02,
		DEBUG = 0x04,
		WARNING = 0x10,
		ERROR = 0x20
	};

	void addWriter(KWWriter* writer, int levels);

	virtual void logInfo(std::string logs);
	virtual void logTrace(std::string logs);
	virtual void logDebug(std::string logs);
	virtual void logWarning(std::string logs);
	virtual void logError(std::string logs);

	void setEnable(bool enable);																					/**<Funkcja włączająca/wyłączająca logowanie*/

private:
	std::vector<KWWriter*> writerList;																				/**<Zbiór wykorzystywanych writerów*/

	std::vector<KWWriter*> infoList;																				/**<Lista writerów przypisanych do logowania na poziomie Info*/
	std::vector<KWWriter*> traceList;																				/**<Lista writerów przypisanych do logowania na poziomie Trace*/
	std::vector<KWWriter*> debugList;																				/**<Lista writerów przypisanych do logowania na poziomie Debug*/
	std::vector<KWWriter*> warningList;																				/**<Lista writerów przypisanych do logowania na poziomie Warning*/
	std::vector<KWWriter*> errorList;																				/**<Lista writerów przypisanych do logowania na poziomie Error*/

	bool globalEnable;																								/**<Flaga włączająca/wyłączająca logowanie*/

	void log(std::string log, std::vector<KWWriter*>* lista, mode mod);
};

#endif
