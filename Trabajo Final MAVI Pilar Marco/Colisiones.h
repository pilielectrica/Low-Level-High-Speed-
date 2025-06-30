#pragma once
#include "Enemigo.h"
#include "Player.h"
#include "Proyectil.h"
#include "Inocente.h"
#include "Audio.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System.hpp>
#include <iostream>

using namespace sf;
using namespace std;
class Colisiones
{
private:
	friend class Player;
	Texture autoRotoTex;
	bool autoRoto;
	Texture texturasHumo [14];
	Sprite spriteHumo;
	int frameAnim = 1;
	float tiempo = 0;
	bool volver = false;
	Audio audio;
	
	bool lanzarHumo = false;
	bool colision = false;
	Proyectil bomba;
	Inocente poyito;
	float tiempoInvulnerable = 0.f;
	bool estaInvulnerable = false;

	

public:
	bool colisionDetectCarPlayer(Sprite* enemy, Player& player, int& vidas, float deltaTime);
	Colisiones();
	void animHumo();
	void updateAnimHumo(float deltaTime, Vector2f playerPos);
	Sprite& getHumoSprite();
	bool& getlanzarHumo();
	void detectBombColision(Sprite* enemy, Proyectil& _bomba);
	bool desaparecerBomba;
	void detectPollitoColision(Afichmation& pollito, Player& player, int vidas);
	int contadorColisiones = 0;
};

