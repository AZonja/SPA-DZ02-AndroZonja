#include<iostream>
#include"game_of_life.h"
#include<ctime>

using namespace std;

bool game_of_life::slucajna_vrijednost()
{
	srand(time(nullptr));
	int z = rand()%broj++;
	if (z%4 == 0 )
		return true;
	else
		return false;
}

bool game_of_life::provjera(int i, int j)
{
	int b = 0;
	for (int m = 0; m < REDAKA; m++)
	{
		for (int n = 0; n < STUPACA; n++)
		{
			if (m == i - 1 && n == j - 1|| m == i  && n == j - 1 || m == i + 1 && n == j - 1 || m == i + 1 && n == j || m == i - 1 && n == j || m == i - 1 && n == j + 1 || m == i  && n == j + 1 || m == i + 1 && n == j + 1)
			{
				if (celija_zauzeta(m,n))
					b++;
			}
		}
	}
	if (b == 2 || b == 3)
		return true;
	else
		return false;
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	if (_generacija[i][j])
		return true;
	else 
		return false;
}

game_of_life::game_of_life()
{
	for (int  i = 0; i <REDAKA; i++)
	{
		for (int j = 0; j <STUPACA;  j++)
		{
			_generacija[i][j] = slucajna_vrijednost();
		}
	}
}

void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i <REDAKA; i++)
	{
		for (int j = 0; j <STUPACA; j++)
		{
			_generacija[i][j] = provjera(i,j);
		}
	}
}

void game_of_life::iscrtaj()
{
	char c;
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			char c;
			if (_generacija[i][j] == true)
				c = 'x';
			else
				c = ' ';
			cout << c;
		}
		cout << endl;
	}
}
