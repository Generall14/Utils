#include "KWWriterCout.hpp"
#include <iostream>

/**
 * Konstruktor przyjmujący obiekt formatujący tekst.
 */
KWWriterCout::KWWriterCout(KWFormater *textFormater):
	KWWriter(textFormater, 0)
{
	desc = "std::cout writer";
}

KWWriterCout::~KWWriterCout()
{
	this->flush();
}

/**
 * Funkcja wysyła tekst na std::cout.
 * @param str - Wiadomość.
 */
bool KWWriterCout::sendText(std::string str)
{
	std::cout << str << std::flush;
	return 0;
}
