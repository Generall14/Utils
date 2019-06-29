#include "KWSimpleFormater.hpp"

/**
 * @param separator - Znak dzielący opis poziomu od tekstu wiadomości.
 * @param ending - Znak dodawany na końcu każdego logu.
 */
KWSimpleFormater::KWSimpleFormater(std::string separator, std::string ending):
	_separator(separator),
	_ending(ending)
{
	desc = "simple formater";
}

std::string KWSimpleFormater::format(std::string str, KWLoger::mode level)
{
	std::string temp;
	switch (level)
	{
	case KWLoger::INFO:
		temp = "Info   ";
		break;
	case KWLoger::TRACE:
		temp = "Trace  ";
		break;
	case KWLoger::DEBUG:
		temp = "Debug  ";
		break;
	case KWLoger::WARNING:
		temp = "Warning";
		break;
	case KWLoger::ERROR:
		temp = "ERROR  ";
		break;
	default:
		temp = "       ";
		break;
	}

	return temp + _separator + str + _ending;
}
