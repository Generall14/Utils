#ifndef KWCOMPARATOR_HPP
#define KWCOMPARATOR_HPP

/**
 * \file KWComparator.hpp
 *
 * Plik zawiera funkcje porównujące wartości zmiennoprzecinkowe float oraz double.
 * ile - is less equal (a <= b)
 * il - is less (a < b)
 * ie - is equal (a == b)
 * ige - is greater equal (a >= b)
 * ig - is greater (a > b)
 * Funkcję przyjmują dodatkowy argument delta reprezentujący dopuszczalny błąd zapisu wartości.
 */

#include <limits>

namespace kwa
{
	bool ie(float a, float b, float delta=std::numeric_limits<float>::epsilon());//a==b
	bool ile(float a, float b, float delta=std::numeric_limits<float>::epsilon());//a<=b
	bool il(float a, float b, float delta=std::numeric_limits<float>::epsilon());//a<b
	bool ige(float a, float b, float delta=std::numeric_limits<float>::epsilon());//a>=b
	bool ig(float a, float b, float delta=std::numeric_limits<float>::epsilon());//a>b

	bool ie(double a, double b, double delta=std::numeric_limits<double>::epsilon());//a==b
	bool ile(double a, double b, double delta=std::numeric_limits<double>::epsilon());//a<=b
	bool il(double a, double b, double delta=std::numeric_limits<double>::epsilon());//a<b
	bool ige(double a, double b, double delta=std::numeric_limits<double>::epsilon());//a>=b
	bool ig(double a, double b, double delta=std::numeric_limits<double>::epsilon());//a>b
}

#endif
