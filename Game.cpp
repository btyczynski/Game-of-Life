#include "Game.h"



void Game::runAll()
{
	sf::RenderWindow window(sf::VideoMode(800,600), "GAME OF LIFE", sf::Style::Close);
	 
	while (state != END)
	{
		
		switch (state)
		{
		case GameState::START:
			runStart(window);
			break;
		case GameState::MENU:
			runMenu(window);
			break;
		case GameState::STATE:
			runState(window);
			break;
		case GameState::GAME:
			runGame(getnr(),window);
			break;
		}
	}
}


Game::Game()
{
	state = END;

	if (!font.loadFromFile("Dane/z1.ttf"))
	{
		MessageBox(NULL, _T("Font not found!"), _T("ERROR"), NULL);	
		return;
	}

	state = START;
}


Game::~Game()
{
}
