#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System.hpp>
#include <iostream>
using namespace sf;
using namespace std;
class UI
{
private:
	Texture t1, t2, t3, tgo;
	Sprite s1, s2, s3, sgo;
	Sprite sprites[4];
	Texture background;
	Sprite backgroundSprite;
	Texture textureBomb;
	Sprite bombsCount;
	Texture loserTex;
	Sprite loserSprite;
	Texture winnerTex;
	Sprite winnerSprite;
public:
	void setCuentaRegresiva();
	void showCuentaRegresiva(RenderWindow& window, Sprite bg);
	Sprite& getBackgroundSprite();
	Sprite& getBombCountSprite();
	Sprite& setBombCountNumbers(int cantidadBombas, bool _cambiotransparencia);
	void aplicarTransparencia(bool cambioTransparencia);
	void setLoserSprite();
	Sprite getLoserSprite();
	void setWinnerScreen();
	Sprite getWinnerScreen();
	UI();
};

