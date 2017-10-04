#pragma once
/*!
* \file
* \brief Deklaracja klasy Engine
*
* Plik zawiera deklaracje klasy Engine, która
* jest klas¹ bazow¹ i zarz¹dza wszystkimi metodami 
* 
*/
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Stan.h"
#include "StanNastepny.h"
#include "Zpliku.h"
#include "Engine.h"
#include <Windows.h>
#include <string>
#include <tchar.h>
#include <sstream>
using namespace sf;

class Engine 
{
protected:
	Music music;
	enum GameState {START, MENU, STATE, GAME, END };
	GameState state; /*!< Zmienna przechowujaca obecny stan gry */
	bool mapa[60][80]; /*!< Zmienna przechowujaca aktualne stany komorek */
	Font font; /*!< Zmienna przechowujaca czcionke */
	Text name; /*!< Zmienna przechowujaca nazme uzytownika */
	int nr = 0; /*!< Zmienna przechowujaca nr pliku*/
	bool pauza = false; /*!< Zmienna przechowujaca obecny stan pauzy */
	HWND hWnd = GetConsoleWindow();
	

public:
	/*!
	* \brief Uruchomienie okna z wyborem stanu gry
	*
	* \param[in] window - okno w ktorym wyswietlany jest program
	*/
	void runState(RenderWindow&);
	/*!
	* \brief Uruchomienie okna z  gra
	* \param[in] window - okno w ktorym wyswietlany jest program
	* \param[in] nr - numer pliku do wczytania
	*/
	void runGame(int, RenderWindow&);
	/*!
	* \brief Uruchomienie okna z menu
	*
	* \param[in] window - okno w ktorym wyswietlany jest program
	*/
	void runMenu(RenderWindow&);
	/*!
	* \brief Uruchomienie okna z ekranem powitalnym
	*
	* \param[in] window - okno w ktorym wyswietlany jest program
	*/
	void runStart(RenderWindow&);
	/*!
	* \brief Metoda zwracaj¹ca wybrany numer pliku
	*
	* \return nr - zwraca nr pliku do wczytania
	*/
	int getnr() const;
	/*!
	* \brief Konstruktor Klasy Engine
	*/
	Engine();
	/*!
	* \brief Destruktor Klasy Engine
	*/
	~Engine();
};

