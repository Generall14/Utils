#ifndef KWFORMATER_HPP
#define KWFORMATER_HPP

#include <string>
#include "KWLoger.hpp"

/**
 * \class KWFormater
 * @brief Bazowa klasa formatująca logi.
 *
 * Klasa stanowi bazę dla innych formaterów, sama jest transparentna dla przepływającego tekstu (nie zmienia jego struktury).
 *
 * Każdy tekst wysłany do KWWriter przed przekazaniem do wyjścia jest modyfikowany przez metodę KWFormater::format() obiektu KWFormater.
 */

class KWFormater
{
public:
	KWFormater();
	virtual ~KWFormater(){}

	virtual std::string format(std::string str, KWLoger::mode);
	std::string description() const;														/**<Zwraca opis klasy*/

protected:
	std::string desc;																		/**<Opis klasy*/
};

#endif
