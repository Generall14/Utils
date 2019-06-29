#include "KWTester.hpp"

#include <iomanip>
#include "KWColors.hpp"

/**
 * Konstruktor.
 * @param file - Nazwa pliku wyjściowego.
 * @param outV - Tryb wyświetlania informacji na std::cout według KWTester::verboseMode.
 * @param filV - Tryb wyświetlania informacji na std::ofstream według KWTester::verboseMode.
 */
KWTester::KWTester(const char* file, int outV, int filV):										//Konstruktor
	fileOut(file),
	coutVerbose(outV),
	fileVerbose(filV)
{
}

/**
 * Konstruktor.
 * @param vec - Wektor wskaźników na obiekty testowe, pochodne po KWTest.
 * @param file - Nazwa pliku wyjściowego.
 * @param outV - Tryb wyświetlania informacji na std::cout według KWTester::verboseMode.
 * @param filV - Tryb wyświetlania informacji na std::ofstream według KWTester::verboseMode.
 */
KWTester::KWTester(std::vector<KWTest*> vec, const char* file, int outV, int filV):				//Konstruktor
	fileOut(file),
	coutVerbose(outV),
	fileVerbose(filV)
{
	for(int i=0;i<vec.size();++i)
		testy.push_back(vec.at(i));
	vec.clear();
}

/**
 * Konstruktor.
 * @param vec - Wskaźnik na obiekt testowy, pochodny po KWTest.
 * @param file - Nazwa pliku wyjściowego.
 * @param outV - Tryb wyświetlania informacji na std::cout według KWTester::verboseMode.
 * @param filV - Tryb wyświetlania informacji na std::ofstream według KWTester::verboseMode.
 */
KWTester::KWTester(KWTest* vec, const char* file, int outV, int filV):							//Konstruktor
	fileOut(file),
	coutVerbose(outV),
	fileVerbose(filV)
{
	testy.push_back(vec);
	vec = NULL;
}

/**
 * Destruktor
 */
KWTester::~KWTester()																			//Destruktor
{
	fileOut << std::flush;
	fileOut.close();
	for(int i=0;i<testy.size();++i)
		delete testy[i];
	testy.clear();
}

/**
 * Dodaje obiekt testowy pochodny po KWTest.
 * @param vec - Wskaźnik na test.
 */
void KWTester::AddTest(KWTest* nt)																//Dodawanie testu
{
	testy.push_back(nt);
	nt = NULL;
}

/**
 * Dodaje wektor klas testowych pochodnych po KWTest.
 * @param vec - Wektor testów.
 */
void KWTester::AddTests(std::vector<KWTest*> vec)												//Dodawanie testów
{
	for(int i=0;i<vec.size();++i)
		testy.push_back(vec.at(i));
	vec.clear();
}

/**
 * Główna funkcja wykonawcza klasy, wykonuje testy na wszystkich obiektach testowych KWTest, podlicza wyniki oraz wyświetla podsumowanie.
 */
void KWTester::Run()																			//Przeprowadzanie testów
{
	if((coutVerbose==DescAndFailed) || (coutVerbose==All))
		std::cout << Black("\n>>>>           Rozpoczynanie testów           <<<<\n\n");
	if((fileVerbose==DescAndFailed) || (fileVerbose==All))
		fileOut << "\n>>>>           Rozpoczynanie testów           <<<<\n\n";
	
	int tests = 0, errors = 0;
	for(int i=0;i<testy.size();++i)
	{
		RunTest(testy.at(i));
		tests += testy.at(i)->getTestCount();
		errors += testy.at(i)->getErrorCount();
	}

	if((coutVerbose==DescAndFailed) || (coutVerbose==All))
	{
		std::cout << Black("\n\n>>>>           Koniec testów                  <<<<\n\n");
		std::cout << "Łącznie wykonano " << tests << " testów, " << errors << " z nich zakończyło się błędem.\n";
		if(errors)
			std::cout << Red("\n>>>>           ŹLE!!!                         <<<<\n\n");
		else
			std::cout << Cyan("\n>>>>           Ujdzie.                        <<<<\n\n");
	}
	if((fileVerbose==DescAndFailed) || (fileVerbose==All))
	{
		fileOut << "\n>>>>           Koniec testów                  <<<<\n\n";
		fileOut << "Łącznie wykonano " << tests << " testów, " << errors << " z nich zakończyły się błędem.\n";
		if(errors)
			fileOut << "\n>>>>           ŹLE!!!                         <<<<\n\n";
		else
			fileOut << "\n>>>>           Ujdzie.                        <<<<\n\n";
	}
}

/**
 * Funkcja ustawia parametry i wykonuje test na pojedynczym obiekcie KWTest.
 * @param t - Wskaźnik na obiekt testowy.
 */
void KWTester::RunTest(KWTest* t)																//Uruchamianie pojedynczego testu
{
	t->setVerbose(coutVerbose);
	t->setFileVerbose(fileVerbose);
	t->setOutputFile(&fileOut);
	t->Run();
}

/**
 * Zwraca liczbę obiektów testowych.
 */
int KWTester::getTestOCount()																	//Zwraca liczbę obiektów testowych
{
	return testy.size();
}

/**
 * Zwraca liczbę testów we wszystkich obiektach testowych.
 */
int KWTester::getTestCount()																	//Zwraca liczbę testów we wszystkich obiektach testowych
{
	int temp = 0;
	for(std::vector<KWTest*>::iterator it = testy.begin();it!=testy.end();++it)
		temp += (*it)->getTestCount();
	return temp;
}

/**
 * Zwraca liczbę błędów we wszystkich obiektach testowych.
 */
int KWTester::getErrorCount()																	//Zwraca liczbę błędów we wszystkich obiektach testowych
{
	int temp = 0;
	for(std::vector<KWTest*>::iterator it = testy.begin();it!=testy.end();++it)
		temp += (*it)->getErrorCount();
	return temp;
}

/**
 * Ustawia tryb wyświetlania informacji w std::cout.
 */
void KWTester::setVerbose(int ver)																//Ustawia tryb wyświetlania informacji w std::cout
{
	coutVerbose = ver;
}

/**
 * Ustawia tryb wyświetlania informacji w std::ofstream.
 */
void KWTester::setFileVerbose(int ver)															//Ustawia tryb wyświetlania informacji w std::ofstream
{
	fileVerbose = ver;
}

/**
 * Ustawia plik wyjściowy.
 */
void KWTester::setOutputFile(const char* file)													//Ustawia wyjście do pliku
{
	fileOut.open(file);
}
