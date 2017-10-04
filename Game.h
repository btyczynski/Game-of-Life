#pragma once
/*!
* \file
* \brief Deklaracja klasy Game
*
* Plik zawiera deklaracje klasy Game, która
* odpowiada za uruchomienie calej gry
*
*/
#include "Engine.h"
#include <Windows.h>
#include <string>
#include <tchar.h>
class Game : public Engine
{	
public:
	/*!
	* \brief Uruchomienie calej gry
	*/
	void runAll();
	/*!
	* \brief Konstruktor Klasy Game
	*/
	Game();
	/*!
	* \brief Destruktor Klasy Game
	*/
	~Game();
};

