#pragma once
/*!
* \file
* \brief Deklaracja klasy Zpliku
*
* Plik zawiera deklaracje klasy Zpliku, która
* jest klas¹ bazow¹ i odpowida za pobranie mapy z pliku
*
*/
#include <fstream>
using namespace std;
class Zpliku
{
private:
	bool mapazpliku[60][80]; /*!< Zmienna przechowujaca stan komorek z pliku*/
public:
	/*!
	* \brief Wpisanie danych o komorkach do pola mapazpliku
	*
	* \param[in] nr - numer pliku z ktorego maja byc wczytane dane
	*/
	void loadFromFile(int);
	/*!
	* \brief Wpisanie danych o komorkach do glownej pamieci programu
	*
	* \param[in] mapa - mapa zmienna do ktorej ma zostac przepisana wartosc
	*/
	void przepisz(bool(&mapa)[60][80]);
	/*!
	* \brief Konstruktor Klasy Zpliku
	*/
	Zpliku();
	/*!
	* \brief Destruktor Klasy Zpliku
	*/
	~Zpliku();
};

