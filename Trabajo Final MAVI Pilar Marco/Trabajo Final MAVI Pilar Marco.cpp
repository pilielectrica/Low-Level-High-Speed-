#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Background.h"
#include "Player.h"
#include "Colas.h"
#include "Enemigo.h"
#include "Inocente.h"
#include "Ui.h"
#include "Proyectil.h"
#include "Colisiones.h"
#include "Audio.h"
using namespace sf;
using namespace std;



int main()
{

	srand(time(NULL));
	sf::RenderWindow App(sf::VideoMode(800, 600, 32),
		"TP FINAL PILAR MARCO");
	App.setFramerateLimit(60); // Limita a 60 FPS
	Background background;
	Player player;
	Colas cola;
	player.set_Player();
	background.set_Background();
	Clock clock;
	float velocity1 = 100;
	float velocity2 = 200;
	float velocity3 = 300;
	cola.LoadColas();
	
	Inocente pollito;
	pollito.setInocente();
	bool dibujarpollito = false;
	bool segundaColaCargada = false;
	Vector2f posicionpoliito{ 0,0 };
	UI cuentaRegresiva;
	cuentaRegresiva.setCuentaRegresiva();
	cuentaRegresiva.showCuentaRegresiva(App, cuentaRegresiva.getBackgroundSprite());
	cuentaRegresiva.setLoserSprite();
	Proyectil bomba(player.get_Player_Sprite().getPosition());
	bomba.setBomb();
	
	bool bombalanzada = false;
	Vector2f posicionInicialProyectil;
	Colisiones colision;
	int contadorBombas = 0;
	bool bombaTransparente = false;
	cuentaRegresiva.setBombCountNumbers(contadorBombas, bombaTransparente);
	int vidas = 3;
	bool derrota = false;
	bool victoria = false;
	cuentaRegresiva.setWinnerScreen();
	Audio audio;
	audio.playBackgroundMusic();
	auto reiniciarJuego = [&]() {
		// Reiniciar estado del juego
		player.set_Player();
		player.get_Player_Sprite().setTexture(player.texture_player);
		player.get_Player_Sprite().setTextureRect(IntRect(0, 0, player.texture_player.getSize().x, player.texture_player.getSize().y));
		player.get_Player_Sprite().setScale(1.f, 1.f);
		player.get_Player_Sprite().setPosition(430, 470);
		colision.getlanzarHumo() = false;
		background.set_Background();
		cola.resetColas(); 
		cola.LoadColas();
		pollito.setInocente();
		dibujarpollito = false;
		segundaColaCargada = false;
		posicionpoliito = Vector2f{ 0, 0 };
		bomba = Proyectil(player.get_Player_Sprite().getPosition());
		bomba.setBomb();
		
		bombalanzada = false;
		contadorBombas = 0;
		bombaTransparente = false;
		vidas = 3;
		derrota = false;
		cuentaRegresiva.setBombCountNumbers(contadorBombas, bombaTransparente);
		colision.contadorColisiones = 0;
		victoria = false;
		cuentaRegresiva.setWinnerScreen();

		
		};
	//reiniciarJuego();
	// Loop principal
	while (App.isOpen()) {
		float deltaTime = clock.restart().asSeconds();
		sf::Event event;
		
		while (App.pollEvent(event)) {
			
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
			{
					player.get_Player_Sprite().setTexture(player.texture_player);
					//player.get_Player_Sprite().setScale(1, 1);
					segundaColaCargada = false;
					derrota = false;
					colision.contadorColisiones = 0;
					reiniciarJuego();

							}
			if (event.type == sf::Event::Closed)
				App.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space)
			{
				bomba.llamarBomb(player.get_Player_Sprite().getPosition());
				posicionInicialProyectil = player.get_Player_Sprite().getPosition();
				
				cout << contadorBombas << endl;
				if (contadorBombas < 2)
				{   
					bombalanzada = true;
				}
				if (contadorBombas == 2)
				{
					bombaTransparente = true;
				}
				
			}

		}
		
		player.acelerar_Player(deltaTime);
		player.limitarMovimiento(App);
		background.updateBackground(player.get_Player_Velocity().y);
		cuentaRegresiva.aplicarTransparencia(bombaTransparente);
		player.morir(vidas, derrota);

		cola.UpdateCola(cola.primerEnemigoPlat1, cola.enemigoRemovidoPlat1, cola.ultimoEnemigoPlat1, cola.EnemigoEnEsperaPlat1, 180, deltaTime, velocity1, player.get_Player_Velocity().y, -1);
		cola.UpdateCola(cola.primerEnemigoPlat3, cola.enemigoRemovidoPlat3, cola.ultimoEnemigoPlat3, cola.EnemigoEnEsperaPlat3, 430, deltaTime, velocity2, player.get_Player_Velocity().y, 1);
		cola.UpdateCola(cola.primerEnemigoPlat5, cola.enemigoRemovidoPlat5, cola.ultimoEnemigoPlat5, cola.EnemigoEnEsperaPlat5, 555, deltaTime, velocity3, player.get_Player_Velocity().y, 1);
		cola.UpdateCola(cola.primerEnemigoPlat6, cola.enemigoRemovidoPlat6, cola.ultimoEnemigoPlat6, cola.EnemigoEnEsperaPlat6, 300, deltaTime, velocity3, player.get_Player_Velocity().y, -1);
		if (!segundaColaCargada &&
			cola.primerEnemigoPlat1 == nullptr && cola.enemigoRemovidoPlat1 == nullptr &&
			cola.primerEnemigoPlat3 == nullptr && cola.enemigoRemovidoPlat3 == nullptr &&
			cola.primerEnemigoPlat5 == nullptr && cola.enemigoRemovidoPlat5 == nullptr)
		{

			dibujarpollito = true;
			if (pollito.get_Inocente_Sprite().getPosition().x > 800)
			{
				cola.LoadColas2();
				segundaColaCargada = true;
			}
		}
		if (segundaColaCargada &&
			cola.primerEnemigoPlat1 == nullptr && cola.enemigoRemovidoPlat1 == nullptr &&
			cola.primerEnemigoPlat3 == nullptr && cola.enemigoRemovidoPlat3 == nullptr &&
			cola.primerEnemigoPlat5 == nullptr && cola.enemigoRemovidoPlat5 == nullptr &&
			cola.primerEnemigoPlat6 == nullptr && cola.enemigoRemovidoPlat6 == nullptr)
		{
			cout << "victoria" << endl;
			victoria = true;
		}
		if (cola.enemigoRemovidoPlat1 != NULL) {
			colision.colisionDetectCarPlayer(cola.enemigoRemovidoPlat1, player, vidas, deltaTime);
			colision.detectBombColision(cola.enemigoRemovidoPlat1, bomba);
		
		}
		if (cola.enemigoRemovidoPlat3 != NULL) { colision.colisionDetectCarPlayer(cola.enemigoRemovidoPlat3, player, vidas, deltaTime);
		colision.detectBombColision(cola.enemigoRemovidoPlat3, bomba);
		
		}
		if (cola.enemigoRemovidoPlat5 != NULL) { colision.colisionDetectCarPlayer(cola.enemigoRemovidoPlat5, player, vidas, deltaTime);
		colision.detectBombColision(cola.enemigoRemovidoPlat5, bomba);
		
		}
		if (cola.enemigoRemovidoPlat6 != NULL) { colision.colisionDetectCarPlayer(cola.enemigoRemovidoPlat6, player, vidas, deltaTime);
		colision.detectBombColision(cola.enemigoRemovidoPlat6, bomba);
		
		}
		if (bombalanzada) { bomba.llamarBomb(posicionInicialProyectil); bomba.lanzarBomb(deltaTime, colision.desaparecerBomba);
		
		cout << "MRU ES: " << bomba.mruProyectil<< endl;
		if (bomba.mruProyectil <= 0) {
			contadorBombas++;colision.desaparecerBomba = false;
		bombalanzada = false;
		bomba.mruProyectil = 400;
		}		
		}
		colision.updateAnimHumo(deltaTime, player.get_Player_Sprite().getPosition());
		colision.detectPollitoColision(pollito.get_Inocente_Sprite(),player, vidas);

		//Limpiamos la ventana
		App.clear();
		// Dibujamos la escena
		
		
		App.draw(background.get_Background1_Sprite());
		App.draw(background.get_Background2_Sprite());
		App.draw(player.get_Player_Sprite());
		if (colision.getlanzarHumo() == true) {App.draw(colision.getHumoSprite());}
		if (bombalanzada == true) { App.draw(bomba.getBombSprite()); }
		if (dibujarpollito == true)
		{
		pollito.setMovement(deltaTime, player.get_Player_Velocity().y);
		pollito.get_Inocente_Sprite().Update();
		App.draw(pollito.get_Inocente_Sprite());


		}
		

		if (cola.enemigoRemovidoPlat1 != NULL)
		{
			App.draw(*cola.enemigoRemovidoPlat1);
		}
		if (cola.enemigoRemovidoPlat3 != NULL)
		{
			App.draw(*cola.enemigoRemovidoPlat3);
		}
		if (cola.enemigoRemovidoPlat5 != NULL)
		{
			App.draw(*cola.enemigoRemovidoPlat5);

		}
		if (cola.enemigoRemovidoPlat6 != NULL)
		{
			App.draw(*cola.enemigoRemovidoPlat6);

		}
		App.draw(cuentaRegresiva.getBombCountSprite());
		App.draw(cuentaRegresiva.setBombCountNumbers(contadorBombas, bombaTransparente));
		if (derrota == true)
		{
			App.draw(cuentaRegresiva.getLoserSprite());
	        
		}
		if (victoria == true)
		{
			App.draw(cuentaRegresiva.getWinnerScreen());
		}
		/*for (int i = 0; i < 4; i++)
		{
			if (cola.EnemigoEnEsperaPlat1 && cola.EnemigoEnEsperaPlat1->enemigoEnEspera[i])
				App.draw(*(cola.EnemigoEnEsperaPlat1->enemigoEnEspera[i]));
			if (cola.EnemigoEnEsperaPlat3 && cola.EnemigoEnEsperaPlat3->enemigoEnEspera[i])
				App.draw(*(cola.EnemigoEnEsperaPlat3->enemigoEnEspera[i]));
			if (cola.EnemigoEnEsperaPlat5 && cola.EnemigoEnEsperaPlat5->enemigoEnEspera[i])
				App.draw(*(cola.EnemigoEnEsperaPlat5->enemigoEnEspera[i]));
			if (cola.EnemigoEnEsperaPlat6 && cola.EnemigoEnEsperaPlat6->enemigoEnEspera[i])
				App.draw(*(cola.EnemigoEnEsperaPlat6->enemigoEnEspera[i]));

		}*/
		

		// Mostramos la ventana
		App.display();
	}
	return 0;
}

