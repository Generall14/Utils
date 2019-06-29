/**
 * \file KWTester.hpp
 *
 * Klasy i makra ułatwiające przeprowadzanie testów jednostkowych.
 *
 * Definicja NOCOLORS przed dodaniem pliku wyłącza kolorowe teksty.
 *
 * \author Wojciech Kogut
 * \startdate 2016.07.12
 * \version v1.01
 * \date 2016.07.21
 *
 * \class KWTester
 * @brief Klasa zarządzająca obiektami testowymi KWTest.
 *
 * Klasa ustawia parametry (wyświetlanie wyników, plik wyjściowy, itp.) dla wszystkich obiektów KWTest, następnie wywołuje dla nich funkcje KWTest::Run(), sprawdza rezultaty oraz wyświetla
 * wyniki.
 *
 * \par Wykorzystanie klasy
 * Do obiektu KWTester należy dodać rozszerzone klasy KWTest poprzez konstruktor lub za pomocą funkcji AddTest() / AddTests(), ustawić parametry (coutVerbose, fileVerbose, fileOut). W celu
 * wykonania testów konieczne jest wywołanie funkcji Run().
 * \endpar
 */

#ifndef KWTESTER_HPP
#define KWTESTER_HPP

#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include "KWTest.hpp"

class KWTester
{
public:
	KWTester(const char* file="", int outV = All, int filV = Quiet);							//Konstruktor
	KWTester(std::vector<KWTest*> vec, const char* file="", int outV = All, int filV = Quiet);	//Konstruktor
	KWTester(KWTest* vec, const char* file="", int outV = All, int filV = Quiet);				//Konstruktor
	~KWTester();																				//Destruktor
	
	void AddTest(KWTest* nt);																	//Dodawanie testu
	void AddTests(std::vector<KWTest*> vec);													//Dodawanie testów
	
	void Run();																					//Przeprowadzanie testów
	
	int getTestOCount();																		//Zwraca liczbę obiektów testowych
	int getTestCount();																			//Zwraca liczbę testów we wszystkich obiektach
	int getErrorCount();																		//Zwraca liczbę błędów we wszystkich obiektach
	void setVerbose(int ver);																	//Ustawia tryb wyświetlania informacji w std::cout
	void setFileVerbose(int ver);																//Ustawia tryb wyświetlania informacji w std::ofstream
	void setOutputFile(const char* file);														//Ustawia wyjście do pliku
	
	enum verboseMode																			/**Określa stopień wyświetlania informacji.*/
	{
		All,																					/**<Wszystkie informacje.*/
		Tests,																					/**<Tylko informacje o testach.*/
		FailedTests,																			/**<Tylko informacje o błędnych testach.*/
		DescAndFailed,																			/**<Informacje o błędnych testach oraz podsumowania.*/
		Quiet																					/**<Żadnych informacji.*/
	};
	
private:
	std::ofstream fileOut;																		/**<Plik wyjściowy.*/
	int coutVerbose;																			/**<Tryb wyświetlania wiadomości w std::cout.*/
	int fileVerbose;																			/**<Tryb wysyłania wiadomości do pliku.*/
	std::vector<KWTest*> testy;																	/**<Wektor testów.*/
	
	void RunTest(KWTest* t);																	//Uruchamianie pojedynczego testu
};

#endif
