#pragma once
/*!
* \file
* \brief Deklaracja klasy Stan
*
* Plik zawiera deklaracje klasy Stan, która
* jest klas¹ bazow¹ i odpowida za rysowanie mapy
*
*/
#include <SFML/Graphics.hpp>
#include <iostream>


class Stan
{
private:
	bool mapaw[60][80]; /*!< Zmienna przechowujaca obecny stan komorek*/
public:
	/*!
	* \brief wyswietalenie obecnej mapy komorek
	*
	* \param[in] window - okno w ktorym wyswietlany jest program
	*/
	void drawmap(sf::RenderWindow &);
	/*!
	* \brief Wpisanie danych o komorkach do pola mapaw
	*
	* \param[in] mapa - zmienna z ktorej ma zostac przepisana wartosc
	*/
	void przepisz(bool mapa[60][80]);
	/*!
	* \brief Konstruktor Klasy Stan
	*/
	Stan();
	/*!
	* \brief Destruktor Klasy Stan
	*/
	~Stan();
};

