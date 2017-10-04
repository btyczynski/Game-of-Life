#include "StanNastepny.h"




void StanNastepny::oblicz(bool (&mapa)[60][80], sf::RenderWindow &window)
{
	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			int sasiad = 0;
			if (mapa[i][j] == 0)
			{
				if (mapa[i][j - 1] == 1) sasiad++;

				if (mapa[i - 1][j] == 1) sasiad++;

				if (mapa[i - 1][j - 1] == 1) sasiad++;

				if (mapa[i + 1][j - 1] == 1) sasiad++;

				if (mapa[i + 1][j] == 1) sasiad++;

				if (mapa[i - 1][j + 1] == 1) sasiad++;

				if (mapa[i][j + 1] == 1) sasiad++;

				if (mapa[i + 1][j + 1] == 1) sasiad++;
				
				if (sasiad == 3)
					mapanew[i][j] = 1;
				else
					mapanew[i][j] = 0;
			}
			else
			{
				if (mapa[i][j - 1] == 1) sasiad++;

				if (mapa[i - 1][j] == 1) sasiad++;

				if (mapa[i - 1][j - 1] == 1) sasiad++;

				if (mapa[i + 1][j - 1] == 1) sasiad++;

				if (mapa[i + 1][j] == 1) sasiad++;

				if (mapa[i - 1][j + 1] == 1) sasiad++;

				if (mapa[i][j + 1] == 1) sasiad++;

				if (mapa[i + 1][j + 1] == 1) sasiad++;

				if (sasiad == 2 || sasiad == 3)
					mapanew[i][j] = 1;
				else
					mapanew[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 80; j++)
			mapa[i][j] = mapanew[i][j];
		
	}

}



StanNastepny::StanNastepny()
{
}


StanNastepny::~StanNastepny()
{
}
