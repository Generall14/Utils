#ifndef KWWRITERFILE_HPP
#define KWWRITERFILE_HPP

#include <string>
#include "KWFormater.hpp"
#include <queue>
#include "KWWriter.hpp"

/**
 * \class KWWriterFile
 * @brief Klasa kierująca logi do plików.
 *
 * Klasa jest pochodną po KWWriter, zapewnia zapisywanie logów do pliku.
 *
 * Dane zapisywane są do pliku okreslonego w konstruktorze (fileAdres), flaga clearOnStart określa czy plik mabyć wyczyszczony przed pierwszym użyciem.
 */

class KWWriterFile : public KWWriter
{
public:
	KWWriterFile(KWFormater* textFormater, std::string fileAdres, int buffLength=200, bool clearOnStart=true);
	virtual ~KWWriterFile();

protected:
	virtual bool sendText(std::string str);

private:
	std::string adres;																						/**<Adres pliku wyjściowego*/
};

#endif
