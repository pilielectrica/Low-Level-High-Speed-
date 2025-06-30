#include "Inocente.h"
#include <SFML/Window/Keyboard.hpp>
#include "Afichmation.h"

void Inocente::setInocente()
{
	
	anim.Add("walk", { 0, 1, 2, 3, 4, 3, 2, 1}, 8, true);
	anim.Play("walk");
	anim.setScale(0.1, 0.1);
	anim.setPosition(position);
	//texture_inocente.loadFromFile("granny.png");
	//inocente.setTexture(texture_inocente);
	//inocente.setPosition(180, 0);
}
void Inocente::setMovement(float deltaTime, float veloplayer)
{
	position.x += velocity * deltaTime *3;
	
	position.y += velocity * (-veloplayer / 1.5) * deltaTime;
	anim.setPosition(position);
}
Afichmation& Inocente::get_Inocente_Sprite()
{
	return anim;
}
