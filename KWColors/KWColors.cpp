#include "KWColors.hpp"

/**
 * Po wywołaniu tego monstruktora obiekt wyświetli wskazany tekst w wybranym kolorze.
 * @param inString - Tekst do wyświetlenia.
 * @param color - Kolor według KWDye::KWColor.
 */
KWDye::KWDye(std::string inString, int color)
{
#ifdef WINOS
	initStr = "";
#else
	#ifndef NOCOLORS
	initStr = this->getTextColor(color) + inString + "\033[0m";
	#else
	initStr = this->getTextColor(color) + inString;
	#endif
#endif
}

/**
 * Po wywołaniu tego monstruktora obiekt ustawi koloru na stałe.
 * @param color - Kolor według KWDye::KWColor.
 */
KWDye::KWDye(int color)
{
#ifdef WINOS
	initStr = "";
#else
	initStr = this->getTextColor(color);
#endif
}

/**
 * Funkcja tworzy ciąg tekstowy ustawiający kolory tekstu w terminalu (tylko dla systemów Linux).
 * @param color - Kolor według KWDye::KWColor.
 * @return - Tekst ustawiający kolor.
 */
std::string KWDye::getTextColor(int color)													//Tworzy string z kolorem
{
#ifdef WINOS
	return "";
#else
	#ifndef NOCOLORS
	switch(color)
	{
		case kwDefault:
			return "\033[1;39m";
			break;
		case kwGreen:
			return "\033[1;32m";
			break;
		case kwRed:
			return "\033[1;31m";
			break;
		case kwBlue:
			return "\033[1;34m";
			break;
		case kwBlack:
			return "\033[1;30m";
			break;
		case kwBrown:
			return "\033[1;33m";
			break;
		case kwMagenta:
			return "\033[1;35m";
			break;
		case kwCyan:
			return "\033[1;36m";
			break;
		case kwLightGray:
			return "\033[1;37m";
			break;
	}
	#else
	return "";
	#endif
#endif
}

/**
 * Operator "<<" dla wstawianie obiektów KWDye do strumieni std::ostream.
 */
std::ostream& operator<< (std::ostream& stream, const KWDye& kwd)
{
	stream << kwd.initStr;
	return stream;
}
