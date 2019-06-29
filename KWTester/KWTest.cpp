#include <stdlib.h>
#include <iomanip>
#include "KWTest.hpp"
#include "KWTester.hpp"
#include <KWColors.hpp>

/**
 * Konstruktor.
 * @param nazwa - Opis testów w klasie.
 */
KWTest::KWTest(std::string nazwa, std::ofstream* fOut):										//Konstruktor
	nazwaTestu(nazwa),
	tests(0),
	errors(0),
	coutVerbose(KWTester::All),
	fileVerbose(KWTester::All),
	fileOut(fOut)
{
}

/**
 * Funkcja zwraca liczbę wykonanych testów.
 */
int KWTest::getTestCount()																	//Zwraca liczbę testów
{
	return tests;
}

/**
 * Funkcja zwraca liczbę błędnych wyników testów.
 */
int KWTest::getErrorCount()																	//Zwraca liczbę błędów
{
	return errors;
}

/**
 * Funkcja wyświetla w konsoli wynik danego testu (tylko gdy sztandar verbose jest ustawiony).
 * @param name - Opis testu.
 * @param result - Wynik testu (udany/nieudany).
 * @param count - Licznik testu.
 */
void KWTest::PrintTest(std::string name, bool result, int count)							//Wyświetlanie informacji o teście.
{
	if((coutVerbose==KWTester::All) || (((coutVerbose==KWTester::DescAndFailed)||(coutVerbose==KWTester::FailedTests))&&!result) || (coutVerbose==KWTester::Tests))
	{

		std::cout << std::setw(4) << count << " [";
		if(result)
			std::cout << Cyan(" Ok  ");
		else
			std::cout << Red("Error");
		std::cout << "] " << name << std::endl;
	}

	if(fileOut!=NULL)
	{
		if((fileVerbose==KWTester::All) || (((fileVerbose==KWTester::DescAndFailed)||(fileVerbose==KWTester::FailedTests))&&!result) || (fileVerbose==KWTester::Tests))
		{
			*fileOut << std::setw(4) << count << " [";
			if(result)
				*fileOut << " Ok  ";
			else
				*fileOut << "Error";
			*fileOut << "] " << name << std::endl;
		}
	}
}

/**
 * Wyświetla w wynikach (tylko dla trybu KWTester::All) komentarz z kodem.
 * @param code - Treść kodu.
 */
void KWTest::PrintCode(std::string code)													//Wyświetla komentarz z kodem
{
	if(coutVerbose==KWTester::All)
		std::cout << std::setw(13) << " " << Brown("# "+code) << std::endl;
	if(fileVerbose==KWTester::All)
		*fileOut << std::setw(4) << "# "+code << std::endl;
}

/**
 * Funkcja wywoływana z zewnątrz, zarządza wykonaniem testów.
 */
void KWTest::Run()																			//Główna funkcja
{
	if((coutVerbose==KWTester::All) || (coutVerbose==KWTester::DescAndFailed))
		std::cout << "\nRozpoczynanie serii testów: " << Magenta(nazwaTestu) << std::endl;

	if(fileOut!=NULL)
	{
		if((fileVerbose==KWTester::All) || (fileVerbose==KWTester::DescAndFailed))
		*fileOut << "\nRozpoczynanie serii testów: " << nazwaTestu << std::endl;
	}

	Tests();

	if((coutVerbose==KWTester::All) || (coutVerbose==KWTester::DescAndFailed))
	{
		std::cout << "Wykonano " << tests << " testów, wynik " << errors << " prób okazał się nieprawidłowy\nOstateczny wynik: ";
		if(errors)
			std::cout << Red("TRAGEDIA!") << std::endl;
		else
			std::cout << Cyan("Wszystko w porządku.") << std::endl;
	}
	if(fileOut!=NULL)
	{
		if((fileVerbose==KWTester::All) || (fileVerbose==KWTester::DescAndFailed))
		{
			*fileOut << "Wykonano " << tests << " testów, wynik " << errors << " prób okazał się nieprawidłowy\nOstateczny wynik: ";
			if(errors)
				*fileOut << "TRAGEDIA!" << std::endl;
			else
				*fileOut << "Wszystko w porządku." << std::endl;
		}
	}
}

/**
 * Ustawia tryb wyświetlania informacji w std::cout.
 * @param ver - Opis zgodny z KWTester::verboseMode.
 */
void KWTest::setVerbose(int ver)															//Ustawia sztandar wyświetlania wiadomości
{
	coutVerbose = ver;
}

/**
 * Ustawia tryb wyświetlania informacji w std::ofstream.
 * @param ver - Opis zgodny z KWTester::verboseMode.
 */
void KWTest::setFileVerbose(int ver)
{
	fileVerbose = ver;
}
/**
 * Ustawia wyjście do pliku.
 * @param of - Wskaźnik na wyjściowy strem do pliku.
 */
void KWTest::setOutputFile(std::ofstream* of)
{
	fileOut = of;
}
