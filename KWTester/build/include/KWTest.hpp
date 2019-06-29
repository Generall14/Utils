/**
 * \class KWTest
 * @brief Klasa abstrakcyjna obudowująca testy.
 *
 * Klasy generuje opisy wykonywanych czynności oraz wysyła je na wyjście std::cout i std::ofstream. Przeprowadza testy w funkcji Tests(), zlicza wyniki i przedstawia porównanie.
 *
 * \par Wykorzystanie klasy
 * Należy utworzyć klasę pochodną, przysłaniającą funkcję chronioną virtual void Tests(). Umieszcza się w niej testy jednostkowe wykonywane za pomocą makr _KWTEST(COND). Obiekt klasy można
 * wykorzystać bezpośrednio wywołując na niej funkcję Run(), lub przekazać do klasy KWTester która przejmie obowiązek zarządzania wszystkimi testami.
 * \endpar
 *
 * \author Wojciech Kogut
 */

#ifndef KWTEST_HPP
#define KWTEST_HPP

#include <string>
#include <iostream>
#include <fstream>

/**Makro testowe, uznaje test za poprawny, jeżeli wartość COND jest prawdą*/
#define _KWTEST(COND) if(COND){PrintTest(#COND, true, ++tests);} else{++errors; PrintTest(#COND, false, ++tests);}
/**Makro wykonuje komendę oraz wyświetla jej tekst w wynikach (tylko dla opcji KWTester::All)..*/
#define _CODE(COND) COND PrintCode(#COND);

class KWTest
{
public:
	KWTest(std::string nazwa = "KWTest", std::ofstream* fOut = NULL);							//Konstruktor
	virtual ~KWTest(){}																			/**<Destruktor.*/
	
	void Run();																					//Główna funkcja
	
	int getTestCount();																			//Zwraca liczbę testów
	int getErrorCount();																		//Zwraca liczbę błędów
	void setVerbose(int ver);																	//Ustawia tryb wyświetlania informacji w std::cout
	void setFileVerbose(int ver);																//Ustawia tryb wyświetlania informacji w std::ofstream
	void setOutputFile(std::ofstream* of);														//Ustawia wyjście do pliku
	
protected:
	virtual void Tests() = 0;																	/**<Funkcja w której należy wykonywac testy z wykorzystaniem makr _KWTEST(COND) itp.*/
	
	void PrintTest(std::string name, bool result, int count);									//Wyświetlanie informacji o teście.
	void PrintCode(std::string code);															//Wyświetla komentarz z kodem
	
	int tests;																					/**<Liczba wykonanych testów.*/
	int errors;																					/**<Liczba błędnych wyników testów.*/
	
private:
	std::string nazwaTestu;																		/**<Krótki opis testów.*/
	int coutVerbose;																			/**<Steruje wyświetlaniem wyników na standardowym std::cout.*/
	int fileVerbose;																			/**<Steruje wyświetlaniem wyników do pliku.*/
	
	std::ofstream* fileOut;																		/**<Wskaźnik na wyjściowy strem do pliku.*/
};

#endif
