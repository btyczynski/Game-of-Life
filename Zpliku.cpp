#include "Zpliku.h"
#include <iostream>


void Zpliku::loadFromFile(int nr)
{
	ifstream file;
	switch (nr)
	{
	case 1:
		file.open("Dane//map1.txt");
		break;
	case 2:
		file.open("Dane//map2.txt");
		break;
	case 3:
		file.open("Dane//map3.txt");
		break;
	case 4:
		file.open("Dane//map4.txt");
		break;
	default:
		break;
	}
	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			file >> mapazpliku[i][j];
		}
	}

	file.close();

}

void Zpliku::przepisz(bool(&mapa)[60][80])
{
	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 80; j++)
			mapa[i][j] = mapazpliku[i][j];
	
	}
}



Zpliku::Zpliku()
{

}


Zpliku::~Zpliku()
{
}
