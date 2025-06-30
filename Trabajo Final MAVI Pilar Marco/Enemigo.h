#pragma once
#include <SFML/Graphics.hpp>
#include "Juego.h"

using namespace sf;

class Enemigo
{
private:
	friend class Juego;
	friend class Colas;
	friend class Enemigo;
	Texture* t[4];
	Sprite* s;
	float velocidadenemigo;
	int indice;

public:
	Sprite* enemigoEnEspera[4];
	Enemigo();
	Enemigo(int posX, int posY, int indice, float velocidadenemigo, int direccionY)
	{
		this->indice = indice;
		this->velocidadenemigo = velocidadenemigo;
		for (int i = 0; i < 4; i++)
		{
			t[i] = new Texture();

		}
		t[0]->loadFromFile("Blue_Car.png");
		t[1]->loadFromFile("Green_Car.png");
		t[2]->loadFromFile("Yellow_Car.png");
		t[3]->loadFromFile("Violet_Car.png");
		

		s = new Sprite(*t[indice]);
		s->setPosition(posX, posY);
		s->setScale(1, 1);
		if (direccionY == 1)
		{
			s->setOrigin(0.f, s->getLocalBounds().height);
			s->setScale(1, -1);

		}
		for (int i = 0; i < 4; i++)//asignamos sprites a los enemigos
		{
			enemigoEnEspera[i] = new Sprite(*t[i]);
			enemigoEnEspera[i]->setPosition(-100, -100);
		}
	}
	void reposicionar(int x, int y)
	{
		s->setPosition(x, y);
	}
	Enemigo* nextEnemigo;
};
