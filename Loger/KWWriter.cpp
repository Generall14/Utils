#include "KWWriter.hpp"
#include <iostream>

/**
 * Konstruktor, przyjmuje obiekt formatujący oraz określa długość bufora danych.
 * @param textFormater - Obiekt formatujący bazujący na KWFormater.
 * @param bufferDepth - Długość bufora (liczba znaków), warość 0 wyłącza buforowanie.
 */
KWWriter::KWWriter(KWFormater *textFormater, int bufferDepth):
	formater(textFormater),
	desc("virtual base writer"),
	bufDepth(bufferDepth)
{

}

KWWriter::~KWWriter()
{
}

/**
 * Zwraca opis obiektu.
 */
std::string KWWriter::description() const
{
	return desc + " with " + formater->description();
}

/**
 * Funkcja pobiera tekst do logowania. Przepuszcza log przez formater i wysyła na wyjściu lub do bufora.
 * @param str - Wejściowa wiadomość.
 * @param mod - Poziom logowania.
 */
void KWWriter::write(std::string str, KWLoger::mode mod)
{
	if(!bufDepth)
		this->sendText(formater->format(str, mod));
	else
	{
		buf += formater->format(str, mod);
		if(buf.size()>bufDepth)
			this->flush();
	}
}

/**
 * Funkcja wymusza opróżnienie bufora.
 */
void KWWriter::flush()
{
	if(!sendText(buf))
		buf.clear();
}

/**
 * Funkcja zwraca obiekt formatera.
 */
KWFormater KWWriter::gerFormater()
{
	return *formater;
}
