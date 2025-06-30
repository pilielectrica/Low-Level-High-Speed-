#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Afichmation.h"

using namespace sf;
using namespace std;
class Inocente
{ private:
	Sprite inocente;
	Texture texture_inocente;
	float velocity = 100;
	Vector2f position{ 180, 0 };
	Afichmation anim = Afichmation("pollitos.png", true, 885.5, 941);
	Sprite inocente2;

public:
	void setInocente();
	void setMovement(float deltaTime, float veloplayer);
	Afichmation& get_Inocente_Sprite();
	Inocente() {};
};

