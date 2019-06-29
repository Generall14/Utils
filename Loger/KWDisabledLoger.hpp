#ifndef KWDISABLEDLOGER_HPP
#define KWDISABLEDLOGER_HPP

#include <string>
#include "KWLoger.hpp"

/**
 * \class KWDisabledLoger
 * @brief Klasa pochodna po KWLoger, wyłącza wszystkie jej funkcjonalności. Może służyć do wyłączenia logowania przy tworzeniu obiektów.
 */
class KWDisabledLoger : public KWLoger
{
public:
	KWDisabledLoger();

	virtual void logInfo(std::string){}/**<Nic nie robiąca metoda zasłaniająca logowanie*/
	virtual void logTrace(std::string){}/**<Nic nie robiąca metoda zasłaniająca logowanie*/
	virtual void logDebug(std::string){}/**<Nic nie robiąca metoda zasłaniająca logowanie*/
	virtual void logWarning(std::string){}/**<Nic nie robiąca metoda zasłaniająca logowanie*/
	virtual void logError(std::string){}/**<Nic nie robiąca metoda zasłaniająca logowanie*/
};

#endif
