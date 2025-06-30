#include "Proyectil.h"
#include <SFML/Window/Keyboard.hpp>
using namespace sf;
using namespace std;
void Proyectil::setBomb()
{
	textureBomb.loadFromFile("bomb.png");
	spriteBomb.setTexture(textureBomb);
	spriteBomb.setPosition(-100, -100);
}
void Proyectil::lanzarBomb( float deltaTime, bool desaparecerBomba)
{
	float posicionInicial_x = spriteBomb.getPosition().x;
	mruProyectil += speed * deltaTime;
	spriteBomb.setPosition(posicionInicial_x, mruProyectil);
	if (desaparecerBomba == true)
	{
		spriteBomb.setPosition(-200, -200);
	}
}
void Proyectil::llamarBomb(Vector2f posicionJugador)
{
	spriteBomb.setPosition(posicionJugador);
}
Sprite& Proyectil::getBombSprite()
{
	
	return spriteBomb;
}
Proyectil::Proyectil(Vector2f posicionJugador)
{
	mruProyectil = posicionJugador.y;
}
Proyectil::Proyectil()
{

}
