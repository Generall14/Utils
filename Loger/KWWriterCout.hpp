#ifndef KWWRITERCOUT_HPP
#define KWWRITERCOUT_HPP

#include <string>
#include "KWFormater.hpp"
#include <queue>
#include "KWWriter.hpp"

/**
 * \class KWWriterCout
 * @brief Klasa kierująca logi na std::cout.
 *
 * Klasa jest pochodną po KWWriter, zapewnia wyświetlanie logów na wyjściu std::cout. Klasa wyłącza buforowanie klasy bazowej.
 */

class KWWriterCout : public KWWriter
{
public:
	KWWriterCout(KWFormater* textFormater);
	virtual ~KWWriterCout();

protected:
	virtual bool sendText(std::string str);
};

#endif
