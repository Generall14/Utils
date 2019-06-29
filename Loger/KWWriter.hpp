#ifndef KWWRITER_HPP
#define KWWRITER_HPP

#include <string>
#include "KWFormater.hpp"
#include <queue>

/**
 * \class KWWriter
 * @brief Bazowa klasa zapisująca logi.
 *
 * Klasa stanowi bazę dla innych writerów. Pobiera obiekt KWFormater, jest składowana i wykorzystywana w KWLoger.
 *
 * Klasa implementuje mechanizm buforowania, jego długość określana jest w konstruktorze (wartość 0 wyłącza buforowanie).
 * Można wymusić wypchnięcie bufora poprzez funkcję KWWriter::flush().
 *
 * W klasach pochodnych należy zasłonić funkcję KWWriter::sendText(std::string) której zadaniem jest wysyłanie otrzymanego tekstu do wybranego celu.
 */

class KWWriter
{
public:
	KWWriter(KWFormater* textFormater, int bufferDepth=0);
	virtual ~KWWriter();

	std::string description() const;
	KWFormater gerFormater();

	void write(std::string str, KWLoger::mode mod);
	void flush();

protected:
	KWFormater* formater;																		/**<Obiekt formatujący tekst*/
	std::string desc;																			/**<Opis klasy*/
	std::string buf;																			/**<Bufor tekstu*/
	int bufDepth;																				/**<Długość bufora*/

	virtual bool sendText(std::string str) = 0;													/**<Wirtualna metoda mająca wysyłać text na żądane wyjście*/
};

#endif
