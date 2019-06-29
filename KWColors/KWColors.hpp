#ifndef KWCOLORS_HPP
#define KWCOLORS_HPP

/**
 * \file KWColors.hpp
 *
 * Kolorowanie teksty w std::ostream.
 *
 * \author Wojciech Kogut
 * \startdate 2016.07.20
 * \version v0.04
 * \date 2016.07.22
 *
 * \par Wykorzystanie klasy
 * Klas z biblioteki można używać w strumieniach std::ofstream. Bazową kalsą jest KWDye, jego działanie zależy od wywołanego konstruktora, KWDye(std::string s, KWColor c) pokoloruje tylko tekst 
 * przekazany w łańcuchu s, konstruktor KWDye(KWColor c) zmienia kolor całego strumienia znajdującego się za obiektem.
 * 
 * Kolory ustawiane są za pomocą zmiennej enum KWDye::KWColor.
 * 
 * Alternatywą dla KWDye są klasy Red, Green itp. będące pochodnymi KWDye ze sztywno ustalonym kolorem, rówież posiadają po dwa konstruktory (bez parametru KWColor c).
 * 
 * Przykładowe wykorzystanie:
 * \code{.cpp}
 * cout << "Zwykły tekst" << KWDye("Czerwony tekst", KWDye::kwRed) << "Zwykły tekst\n";
 * cout << "Zwykły tekst" << KWDye(KWDye::kwBlue) << "Niebieski tekst\n";
 * cout << "Wciąż niebieski tekst" << KWDye(KWDye::kwDefault) << "Ponownie zwykły tekst\n";
 * \endcode
 * 
 * To samo, z wykorzystaniem klas pochodnych:
 * \code{.cpp}
 * cout << "Zwykły tekst" << Red("Czerwony tekst") << "Zwykły tekst\n";
 * cout << "Zwykły tekst" << Blue() << "Niebieski tekst\n";
 * cout << "Wciąż niebieski tekst" << ResetColor() << "Ponownie zwykły tekst\n";
 * \endcode
 * \endpar
 * 
 * \par Konfiguracja
 * Wyłączenie kolorów polega na zdefiniowaniu stałej NOCOLORS przed dołączeniem pliku.
 * \n \n
 * Standardowo biblioteka wykorzystuje mechanizmy dostępne na system Linux, aby włączyć tryb na Windows należy zdefiniować stałą WINOS, bez tego wyświetlane będą śmieci.
 * \note
 * UWAGA! W aktualnej wersji nie ma gotowego trybu dla Windowsów.
 * \endpar
 */

#include <ostream>
#include <string>

/**
 * \class KWDye
 * @brief Główna klasa biblioteki KWColors.
 *
 * Klasa ustawiająca kolory, wykorzystywana poprzez wstawianie do std::ostream. W zależności od wybranego konstruktora ustawia kolor na stałe lub koloruje tylko wskazany tekst.
 */
class KWDye
{
public:
	KWDye(std::string inString, int color = kwDefault);											//Konstruktor do wskazanego tekstu
	KWDye(int color = kwDefault);																//Konstruktor do permanentnego koloru
	
	/**
	 * Wylicznienie opisujące kolory.
	 */
	enum KWColor
	{
		kwDefault = 0,																			/**<Domyślny kolor.*/
		kwGreen,																				/**<Zielony.*/
		kwRed,																					/**<Czerwony.*/
		kwBlue,																					/**<Niebieski.*/
		kwBlack,																				/**<Czarny.*/
		kwBrown,																				/**<Brązowy.*/
		kwMagenta,																				/**<Purpurowy.*/
		kwCyan,																					/**<Błękitny.*/
		kwLightGray																				/**<Szary.*/
	};
	
	friend std::ostream& operator<< (std::ostream& stream, const KWDye& kwd);					/**<Operator wstawiania KWDye do std::ostream.*/

private:
	std::string initStr;																		/**Tekst ustawiający kolor (tylko w Linuxie).*/
	
	std::string getTextColor(int color);														//Tworzy string z kolorem
};

/**
 * \class Red
 * @brief Specjalizowana pochodna KWDye.
 *
 * Klasa dziedzicząca po KWDye ze sztywno ustawionym kolorem KWDye::kwRed. Używana identycznie jak KWDye, z pominięciem podawanych zmiennych KWDye::KWColor.
 */
class Red : public KWDye
{
public:
	Red(std::string str):KWDye(str, KWDye::kwRed){}												/**<Kosntruktor analogiczny do KWDye(std::string, int) z ustawionym kolorem KWDye::kwRed.*/
	Red():KWDye(KWDye::kwRed){}																	/**<Kosntruktor analogiczny do KWDye(int) z ustawionym kolorem KWDye::kwRed.*/
};

/**
 * \class Green
 * @brief Specjalizowana pochodna KWDye.
 *
 * Klasa dziedzicząca po KWDye ze sztywno ustawionym kolorem KWDye::kwGreen. Używana identycznie jak KWDye, z pominięciem podawanych zmiennych KWDye::KWColor.
 */
class Green : public KWDye
{
public:
	Green(std::string str):KWDye(str, KWDye::kwGreen){}											/**<Kosntruktor analogiczny do KWDye(std::string, int) z ustawionym kolorem KWDye::kwGreen.*/
	Green():KWDye(KWDye::kwGreen){}																/**<Kosntruktor analogiczny do KWDye(int) z ustawionym kolorem KWDye::kwGreen.*/
};

/**
 * \class Blue
 * @brief Specjalizowana pochodna KWDye.
 *
 * Klasa dziedzicząca po KWDye ze sztywno ustawionym kolorem KWDye::kwBlue. Używana identycznie jak KWDye, z pominięciem podawanych zmiennych KWDye::KWColor.
 */
class Blue : public KWDye
{
public:
	Blue(std::string str):KWDye(str, KWDye::kwBlue){}											/**<Kosntruktor analogiczny do KWDye(std::string, int) z ustawionym kolorem KWDye::kwBlue.*/
	Blue():KWDye(KWDye::kwBlue){}																/**<Kosntruktor analogiczny do KWDye(int) z ustawionym kolorem KWDye::kwBlue.*/
};

/**
 * \class Black
 * @brief Specjalizowana pochodna KWDye.
 *
 * Klasa dziedzicząca po KWDye ze sztywno ustawionym kolorem KWDye::kwBlack. Używana identycznie jak KWDye, z pominięciem podawanych zmiennych KWDye::KWColor.
 */
class Black : public KWDye
{
public:
	Black(std::string str):KWDye(str, KWDye::kwBlack){}											/**<Kosntruktor analogiczny do KWDye(std::string, int) z ustawionym kolorem KWDye::kwBlack.*/
	Black():KWDye(KWDye::kwBlack){}																/**<Kosntruktor analogiczny do KWDye(int) z ustawionym kolorem KWDye::kwBlack.*/
};

/**
 * \class Brown
 * @brief Specjalizowana pochodna KWDye.
 *
 * Klasa dziedzicząca po KWDye ze sztywno ustawionym kolorem KWDye::kwBrown. Używana identycznie jak KWDye, z pominięciem podawanych zmiennych KWDye::KWColor.
 */
class Brown : public KWDye
{
public:
	Brown(std::string str):KWDye(str, KWDye::kwBrown){}											/**<Kosntruktor analogiczny do KWDye(std::string, int) z ustawionym kolorem KWDye::kwBrown.*/
	Brown():KWDye(KWDye::kwBrown){}																/**<Kosntruktor analogiczny do KWDye(int) z ustawionym kolorem KWDye::kwBrown.*/
};

/**
 * \class Magenta
 * @brief Specjalizowana pochodna KWDye.
 *
 * Klasa dziedzicząca po KWDye ze sztywno ustawionym kolorem KWDye::kwMagenta. Używana identycznie jak KWDye, z pominięciem podawanych zmiennych KWDye::KWColor.
 */
class Magenta : public KWDye
{
public:
	Magenta(std::string str):KWDye(str, KWDye::kwMagenta){}										/**<Kosntruktor analogiczny do KWDye(std::string, int) z ustawionym kolorem KWDye::kwMagenta.*/
	Magenta():KWDye(KWDye::kwMagenta){}															/**<Kosntruktor analogiczny do KWDye(int) z ustawionym kolorem KWDye::kwMagenta.*/
};

/**
 * \class Cyan
 * @brief Specjalizowana pochodna KWDye.
 *
 * Klasa dziedzicząca po KWDye ze sztywno ustawionym kolorem KWDye::kwCyan. Używana identycznie jak KWDye, z pominięciem podawanych zmiennych KWDye::KWColor.
 */
class Cyan : public KWDye
{
public:
	Cyan(std::string str):KWDye(str, KWDye::kwCyan){}											/**<Kosntruktor analogiczny do KWDye(std::string, int) z ustawionym kolorem KWDye::kwCyan.*/
	Cyan():KWDye(KWDye::kwCyan){}																/**<Kosntruktor analogiczny do KWDye(int) z ustawionym kolorem KWDye::kwCyan.*/
};

/**
 * \class LightGray
 * @brief Specjalizowana pochodna KWDye.
 *
 * Klasa dziedzicząca po KWDye ze sztywno ustawionym kolorem KWDye::kwLightGray. Używana identycznie jak KWDye, z pominięciem podawanych zmiennych KWDye::KWColor.
 */
class LightGray : public KWDye
{
public:
	LightGray(std::string str):KWDye(str, KWDye::kwLightGray){}									/**<Kosntruktor analogiczny do KWDye(std::string, int) z ustawionym kolorem KWDye::kwLightGray.*/
	LightGray():KWDye(KWDye::kwLightGray){}														/**<Kosntruktor analogiczny do KWDye(int) z ustawionym kolorem KWDye::kwLightGray.*/
};

/**
 * \class ResetColor
 * @brief Reset kolorów.
 *
 * Klasa używana do przywracania domyslnych kolorów po wcześniejczym wykorzystaniu klasy KWDye ustawiającej kolor na stałe.
 */
class ResetColor : public KWDye
{
public:
	ResetColor():KWDye(KWDye::kwDefault){}														/**<Domyślny konstruktor.*/
};

#endif

