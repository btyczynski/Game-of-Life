#pragma once
/*!
* \file
* \brief Deklaracja klasy StanNastepny
*
* Plik zawiera deklaracje klasy Stan, która
* jest klas¹ pochodna i odpowida oblicznie kolejnego stanu gry
*
*/
#include "Stan.h"
#include <iostream>
using namespace std;
class StanNastepny: public Stan
{
private:
	bool mapanew[60][80]; /*!< Zmienna przechowujaca obecny nowy stan komorek*/
public:
	/*!
	*\ brief Obliczanie kolejnego stanu gry
		*
		* \param[in] window - okno w ktorym wyswietlany jest program
		* \param[in] mapa - na ktorej beda prowadzone obliczenia
	*/
	void oblicz(bool(&mapa)[60][80], sf::RenderWindow &window);
	
	/*!
	* \brief Konstruktor Klasy Engine
	*/
	StanNastepny();
	/*!
	* \brief Destruktor Klasy StanNastepny
	*/
	~StanNastepny();
};

