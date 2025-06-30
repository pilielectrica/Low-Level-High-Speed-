#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System.hpp>
#include <iostream>
using namespace sf;
using namespace std;
class Proyectil
{private:
	Texture textureBomb;
	Sprite spriteBomb;
	float speed = -200;
	
public:
	void setBomb();
	void lanzarBomb(float deltaTime, bool desaparecerBomba);
	void llamarBomb(Vector2f posicionJugador);
	Sprite& getBombSprite();
	Proyectil(Vector2f posicionJugador);
	Proyectil();
	float mruProyectil = 0;
	void aplicarTransparencia(bool cambioTransparencia);
};

