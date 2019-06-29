#include "KWFormater.hpp"

KWFormater::KWFormater():
	desc("transparent formater")
{

}

/**
 * Przetwarza tekst kierowany do logów. W danej klasie nie robi nic, przepycha tekst bez modyfikacji.
 * @param str - Wejściowy string.
 * @return - Wyjściowy string.
 */
std::string KWFormater::format(std::string str, KWLoger::mode)
{
	return str;
}

std::string KWFormater::description() const
{
	return desc;
}
