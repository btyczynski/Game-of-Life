#include "Engine.h"


 


void Engine::runState(RenderWindow& window)
{   
	Text title("SELECT STATE", font, 100);
	title.setStyle(Text::Bold);
	title.setPosition(800 / 2 - title.getGlobalBounds().width / 2, 10);

	const int ile = 5;

	Text tekst[ile];

	string str[] = { "Small Exploder","Tumbler", "10 Cell Row", "Gosper Glider Gun", "Empty" };
	for (int i = 0; i<ile; i++)
	{
		tekst[i].setFont(font);
		tekst[i].setCharacterSize(50);

		tekst[i].setString(str[i]);
		tekst[i].setPosition(800 / 2 - tekst[i].getGlobalBounds().width / 2, 150 + i * 90);
	}

	while (state == STATE)
	{
		Vector2f mouse(Mouse::getPosition(window));
		Event event;

		while (window.pollEvent(event))
		{
			//Wciœniêcie ESC lub przycisk X
			if (event.type == Event::Closed || event.type == Event::KeyPressed &&
				event.key.code == Keyboard::Escape)
				state = END;

			//Wybor stanu
			if (tekst[0].getGlobalBounds().contains(mouse) &&
				event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
			{
				state = GAME;
				nr = 1;
			}
			if (tekst[1].getGlobalBounds().contains(mouse) &&
				event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
			{
				state = GAME;
				nr = 2;
			}
			if (tekst[2].getGlobalBounds().contains(mouse) &&
				event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
			{
				state = GAME;
				nr = 3;
			}
			if (tekst[3].getGlobalBounds().contains(mouse) &&
				event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
			{
				state = GAME;
				nr = 4;
			}
			if (tekst[4].getGlobalBounds().contains(mouse) &&
				event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
			{
				state = GAME;
				nr = 5;
			}
		}
		for (int i = 0; i<ile; i++)
			if (tekst[i].getGlobalBounds().contains(mouse))
				tekst[i].setColor(Color::Green);
			else tekst[i].setColor(Color::White);

			window.clear();

			window.draw(title);
			for (int i = 0; i<ile; i++)
				window.draw(tekst[i]);

			window.display();
	}
}

void Engine::runGame(int nr, RenderWindow& window)
{
	if (nr == 5 )pauza = true;
	sf::RectangleShape pasek(sf::Vector2f(800, 50));
	pasek.setFillColor(Color::Blue);
	pasek.setPosition(0, 550);
	Text title("MENU", font, 35);
	title.setStyle(Text::Bold);
	title.setPosition(700 ,550);
	Text pause("STOP", font, 35);
	pause.setStyle(Text::Bold);
    pause.setPosition(600, 550);
	Text pause1("START", font, 35);
	pause1.setStyle(Text::Bold);
	pause1.setPosition(600, 550);
	Stan stan;
	RectangleShape suwak1(Vector2f(10, 10 + 5));
	StanNastepny stanNastepny;
	Zpliku o1;
	o1.loadFromFile(nr);
	o1.przepisz(mapa);
	double licznik = 0;
	Text licznikT;
	licznikT.setPosition(20, 550);
	licznikT.setFont(font);
	licznikT.setCharacterSize(35);
	while (state==GAME)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				state = END;
			}
			Vector2f mouse(Mouse::getPosition(window));
			if (title.getGlobalBounds().contains(mouse) &&
				event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
			{
				state = MENU;
			}
			if (pause.getGlobalBounds().contains(mouse) &&
				event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
			{
				if (pauza)pauza = false;
				else
					pauza = true;
			}
			if (pause.getGlobalBounds().contains(mouse))
				pause.setColor(Color::Green);
			else pause.setColor(Color::White);
			if (pause1.getGlobalBounds().contains(mouse))
				pause1.setColor(Color::Green);
			else pause1.setColor(Color::White);
			if (title.getGlobalBounds().contains(mouse))
				title.setColor(Color::Green);
			else title.setColor(Color::White);
		}
		
		
		if (pauza!=true) {
			window.clear();
			stan.drawmap(window);
			licznik++;
			stanNastepny.oblicz(mapa,window);
			window.draw(pasek);
			window.draw(pause);
			window.draw(licznikT);
			window.draw(title);
			window.display();
		}
		else
		{
			window.clear();
			stan.drawmap(window);
			window.draw(pasek);
			window.draw(pause1);
			window.draw(licznikT);
			window.draw(title);
			window.display();
		}
		///////////////////////////////////////////////////////////////////
		if (pauza == true/* && nr == 5*/)
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				cout << Mouse::getPosition(window).x/10 << " " << Mouse::getPosition(window).y/10 << endl;
				if (mapa[(sf::Mouse::getPosition(window).y) / 10][(sf::Mouse::getPosition(window).x) / 10])
					mapa[(sf::Mouse::getPosition(window).y) / 10][(sf::Mouse::getPosition(window).x) / 10] = false;
				else
					mapa[(sf::Mouse::getPosition(window).y) / 10][(sf::Mouse::getPosition(window).x) / 10] = true;
			}
		}/////////////////////////////////////////////////////////////////
		ostringstream ss;
		ss << licznik;
		string str = ss.str();
		licznikT.setString(str);
		stan.przepisz(mapa);
		
		
	}
}

void Engine::runMenu(RenderWindow& window)
{
	
	
	Text title("GAME OF LIFE", font, 100);
	title.setStyle(Text::Bold);
	title.setPosition(800 / 2 - title.getGlobalBounds().width / 2, 10);
	
	Text Hello("Hello", font, 50);
	Hello.setPosition(800 / 2 - Hello.getGlobalBounds().width - 10 , 150);
	name.setPosition(800 / 2  + 10 , 150);
	const int ile = 2;

	Text tekst[ile];

	string str[] = { "Play","Exit" };
	for (int i = 0; i<ile; i++)
	{
		tekst[i].setFont(font);
		tekst[i].setCharacterSize(70);

		tekst[i].setString(str[i]);
		tekst[i].setPosition(800 / 2 - tekst[i].getGlobalBounds().width / 2, 250 + i * 120);
	}
	

	while (state == MENU)
	{
		Vector2f mouse(Mouse::getPosition(window));
		Event event;

		while (window.pollEvent(event))
		{
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
			{
				ShowWindow(hWnd, SW_SHOW);
			}
			//Wciœniêcie ESC lub przycisk X
			if (event.type == Event::Closed || event.type == Event::KeyPressed &&
				event.key.code == Keyboard::Escape)
				state = END;

			//klikniêcie EXIT
			if (tekst[ile - 1].getGlobalBounds().contains(mouse) &&
				event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
			{
				state = END;
			}
			if (tekst[0].getGlobalBounds().contains(mouse) &&
				event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
			{
				state = STATE;
			}
		}
		for (int i = 0; i<ile; i++)
			if (tekst[i].getGlobalBounds().contains(mouse))
				tekst[i].setColor(Color::Green);
			else tekst[i].setColor(Color::White);

			window.clear();

			window.draw(title);
			window.draw(name);
			window.draw(Hello);
			for (int i = 0; i<ile; i++)
				window.draw(tekst[i]);

			window.display();
	}
}

void Engine::runStart(RenderWindow &window)
{
	ShowWindow(hWnd, SW_HIDE);
	std::size_t maxTextLength = 20;
	std::string nick;
	Text title("GAME OF LIFE", font, 100);
	Text enter_name("enter your name:", font, 50);
	title.setStyle(Text::Bold);
	title.setPosition(800 / 2 - title.getGlobalBounds().width / 2, 10);
	enter_name.setPosition(800 / 2 - enter_name.getGlobalBounds().width / 2, 200);
	name.setFont(font);
	name.setCharacterSize(50);
	name.setPosition(800 / 2 - name.getGlobalBounds().width / 2, 300);
	name.setColor(Color::Green);

	while (state == START)
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			sf::Uint32 unicode = event.text.unicode;
			if (event.type == Event::Closed)
				window.close();
		
			else if (event.type == Event::TextEntered)
			{
				

				if (Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && nick.size() > 0)
				{
					nick.erase(nick.size() - 1, 1);
					name.setString(nick);
				}

				else if (((unicode >= 48 && unicode <= 57) || (unicode >= 65 && unicode <= 90) ||
					(unicode >= 97 && unicode <= 122)) && nick.size() < maxTextLength)
				{
					nick += static_cast<char>(unicode);
					name.setString(nick);
					name.setPosition(800 / 2 - name.getGlobalBounds().width / 2, 300);
				}
				if (Keyboard::isKeyPressed(sf::Keyboard::Return))
				{
					state = MENU;
				}
						
			}
		
			
		}
		
		window.clear();
		window.draw(title);
		window.draw(enter_name);
		window.draw(name);
		window.display();
		

	}
}


int Engine::getnr() const
{
	return nr;
}

Engine::Engine()
{
}


Engine::~Engine()
{
}
