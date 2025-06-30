#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Proyectil.h"
#include "Colisiones.h"
#include "Audio.h"

using namespace sf;
using namespace std;
class Player
{
private:
	friend class Colisiones;
	Sprite player;
	
	float deltaTime = 1.0f / 60.0f;
	const float acceleration_x = 100.0f;
	const float acceleration_y = 10.0f;
	const float desacceleration_y = 50.0f;
	const float desacceleration_x = 200;
	Vector2f position{430.0f, 470.0f };
	Vector2f velocity{0.f, 0 };
	Vector2f maxvelocity{ 100,-10 };
	Vector2f minvelocity{ -100, 10 };
	Proyectil bomba;
	Audio audio;
public:
	void set_Player();
	Sprite& get_Player_Sprite();
	void acelerar_Player(float deltaTime);
	void limitarMovimiento(const sf::RenderWindow& window);
	Vector2f get_Player_Velocity();
	void lanzarBomba(float deltaTime, bool _desaparecerBomba);
	void morir(int& vidas, bool& derrota);
	Player();
	Texture texture_player;
};

