#include "Stan.h"



void Stan::drawmap(sf::RenderWindow &window)
{
	sf::Vector2f mouse(sf::Mouse::getPosition(window));
	sf::Event event;
	for (int i = 0; i < 600; i = i + 10)
	{
		for (int j = 0; j < 800; j = j + 10)
		{
			sf::RectangleShape square(sf::Vector2f(10, 10));
			square.setPosition(j, i);
		    if (mapaw[(i / 10)][(j / 10)] == true)
				square.setFillColor(sf::Color::Red);
				else
				square.setFillColor(sf::Color(189, 189, 189));
			square.setOutlineThickness(-1);
			square.setOutlineColor(sf::Color(255, 255, 255));
			window.draw(square);
		}
	}

}

void Stan::przepisz(bool mapa[60][80])
{
	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 80; j++)
			mapaw[i][j] = mapa[i][j];
		
	}
}


Stan::Stan()
{
}


Stan::~Stan()
{
}
