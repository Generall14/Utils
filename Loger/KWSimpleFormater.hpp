#ifndef KWSIMPLEFORMATER_HPP
#define KWSIMPLEFORMATER_HPP

#include <string>
#include "KWLoger.hpp"
#include "KWFormater.hpp"

/**
 * \class KWSimpleFormater
 * @brief Prosta klasa formatująca logi.
 *
 * Klasa dziedziczy po KWFormater, do każdego logu dodaje opis poziomu.
 */

class KWSimpleFormater : public KWFormater
{
public:
	KWSimpleFormater(std::string separator="\t\t", std::string ending="");
	virtual ~KWSimpleFormater(){}

	virtual std::string format(std::string str, KWLoger::mode level);

private:
	std::string _separator;																	/**<Znak dzielący opis poziomu od tekstu wiadomości.*/
	std::string _ending;																	/**<Znak dodawany na końcu każdego logu.*/
};

#endif
