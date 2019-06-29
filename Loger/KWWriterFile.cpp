#include "KWWriterFile.hpp"
#include <iostream>
#include <fstream>

/**
 * Konstruktor obiektu.
 * @param textFormater - Obiekt formatujący tekst.
 * @param fileAdres - adres pliku wyjściowego.
 * @param buffLength - długość bufora (liczba znaków), wartość 0 wyłącza buforowanie.
 * @param clearOnStart - zmienna określająca czy plik ma być wyczyszczony przy utworzeniu obiektu.
 */
KWWriterFile::KWWriterFile(KWFormater *textFormater, std::string fileAdres, int buffLength, bool clearOnStart):
	KWWriter(textFormater, buffLength),
	adres(fileAdres)
{
	desc = "file writer";
	if(clearOnStart)
	{
		std::fstream file;
		file.open(adres, std::fstream::trunc | std::fstream::out);
		file.close();
	}
}

KWWriterFile::~KWWriterFile()
{
	this->flush();
}

/**
 * Funkcja wysyła tekst do pliku.
 * @param str - Wiadomość.
 * @return 0 - ok, 1 - błąd (nie można otworzyć pliku).
 */
bool KWWriterFile::sendText(std::string str)
{
	std::fstream file;
	file.open(adres, std::fstream::app | std::fstream::out);
	if(!file.good())
		return 666;
	file << str;
	file.close();
	return 0;
}
