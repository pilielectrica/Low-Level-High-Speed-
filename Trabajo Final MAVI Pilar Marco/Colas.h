#pragma once
#include <SFML/Graphics.hpp>
#include "Enemigo.h"
class Colas
{
private:
	float deltaTime = 1.0f / 60.0f;
	//Vector2f velocity{ 0.f, 0.0f };
	const float acceleration = 100.0f;
	float velocidadRemovidaPlat1;
	float velocidadRemovidaPlat3;
	float velocidadRemovidaPlat5;
	float velocidadRemovidaPlat6;
	bool segundaTanda_setActive = false;


public:
	Colas();
	Enemigo* EnemigoEnEsperaPlat1;
	Enemigo* EnemigoEnEsperaPlat3;
	Enemigo* EnemigoEnEsperaPlat5;
	Enemigo* EnemigoEnEsperaPlat6;
	Enemigo* NewEnemigoPlat1;
	Enemigo* NewEnemigoPlat3;
	Enemigo* NewEnemigoPlat5;
	Enemigo* NewEnemigoPlat6;
	Enemigo* primerEnemigoPlat1;
	Enemigo* primerEnemigoPlat3;
	Enemigo* primerEnemigoPlat5;
	Enemigo* primerEnemigoPlat6;
	Enemigo* ultimoEnemigoPlat1;
	Enemigo* ultimoEnemigoPlat3;
	Enemigo* ultimoEnemigoPlat5;
	Enemigo* ultimoEnemigoPlat6;
	Sprite* enemigoRemovidoPlat1;
	Sprite* enemigoRemovidoPlat3;
	Sprite* enemigoRemovidoPlat5;
	Sprite* enemigoRemovidoPlat6;

	void InsertEnemigo(int x, int y, int indice, Enemigo*& newEnemigo, Enemigo*& primerEnemigo, Enemigo*& ultimoEnemigo, float velocityenemy, int direccionY);
	void LoadColas2();
	void LoadColas();
	void resetColas();
	void LoadCola();
	void LoadCola2();
	void LoadCola3();
	void LoadCola4();
	void LoadCola5();
	void LoadCola6();
	void LoadCola7();
	void LoadCola8();
	void UpdateCola(Enemigo*& primerEnemigo, Sprite*& enemigoRemovido, Enemigo*& ultimoEnemigo, Enemigo*& enemigoEnEspera, int y, float deltaTime, float velocity, float veloplayer, int direccionY);
	void RemoveEnemigo(Enemigo*& primerEnemigo, Enemigo*& ultimoEnemigo, Sprite*& enemigoRemovido);
	void OrdenarEnemigosEnEspera(int y, Enemigo* EnemigoEnEspera, Enemigo* primerEnemigo);//de parametro la posicion en y
	void vaciarCola(Enemigo*& primer) {
		while (primer != nullptr) {
			Enemigo* temp = primer;
			primer = primer->nextEnemigo;
			delete temp;
		}
	}
};

