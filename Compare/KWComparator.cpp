#include "KWComparator.hpp"
#include <cmath>
#include <limits>

#include <iostream>

/**
 * Zwraca wartość a==b dla wartości float.
 * Jako domyslny dopuszczalny błąd wykorzystano epsilon maszynowy.
 * @param delta - dopuszczalny błąd reprezentacji liczb.
 */
bool kwa::ie(float a, float b, float delta)
{
	return std::fabs(a-b)<delta;
}

/**
 * Zwraca wartość a<=b dla wartości float.
 * Jako domyslny dopuszczalny błąd wykorzystano epsilon maszynowy.
 * @param delta - dopuszczalny błąd reprezentacji liczb.
 */
bool kwa::ile(float a, float b, float delta)
{
	return (a-b)<delta;
}

/**
 * Zwraca wartość a< b dla wartości float.
 * Jako domyslny dopuszczalny błąd wykorzystano epsilon maszynowy.
 * @param delta - dopuszczalny błąd reprezentacji liczb.
 */
bool kwa::il(float a, float b, float delta)
{
	return (a-b)<-delta;
}

/**
 * Zwraca wartość a>=b dla wartości float.
 * Jako domyslny dopuszczalny błąd wykorzystano epsilon maszynowy.
 * @param delta - dopuszczalny błąd reprezentacji liczb.
 */
bool kwa::ige(float a, float b, float delta)
{
	return (b-a)<delta;
}

/**
 * Zwraca wartość a>b dla wartości float.
 * Jako domyslny dopuszczalny błąd wykorzystano epsilon maszynowy.
 * @param delta - dopuszczalny błąd reprezentacji liczb.
 */
bool kwa::ig(float a, float b, float delta)
{
	return (b-a)<-delta;
}

/**Z
 * wraca wartość a==b dla wartości double.
 * Jako domyslny dopuszczalny błąd wykorzystano epsilon maszynowy.
 * @param delta - dopuszczalny błąd reprezentacji liczb.
 */
bool kwa::ie(double a, double b, double delta)
{
	return std::fabs(a-b)<delta;
}

/**
 * Zwraca wartość a<=b dla wartości double.
 * Jako domyslny dopuszczalny błąd wykorzystano epsilon maszynowy.
 * @param delta - dopuszczalny błąd reprezentacji liczb.
 */
bool kwa::ile(double a, double b, double delta)
{
	return (a-b)<delta;
}

/**
 * Zwraca wartość a< b dla wartości double.
 * Jako domyslny dopuszczalny błąd wykorzystano epsilon maszynowy.
 * @param delta - dopuszczalny błąd reprezentacji liczb.
 */
bool kwa::il(double a, double b, double delta)
{
	return (a-b)<-delta;
}

/**
 * Zwraca wartość a>=b dla wartości double.
 * Jako domyslny dopuszczalny błąd wykorzystano epsilon maszynowy.
 * @param delta - dopuszczalny błąd reprezentacji liczb.
 */
bool kwa::ige(double a, double b, double delta)
{
	return (b-a)<delta;
}

/**
 * Zwraca wartość a>b dla wartości double.
 * Jako domyslny dopuszczalny błąd wykorzystano epsilon maszynowy.
 * @param delta - dopuszczalny błąd reprezentacji liczb.
 */
bool kwa::ig(double a, double b, double delta)
{
	return (b-a)<-delta;
}