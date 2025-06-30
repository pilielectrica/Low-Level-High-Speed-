#include "UI.h"
void UI::setCuentaRegresiva()
{
	t1.loadFromFile("1.png");
	t2.loadFromFile("2.png");
	t3.loadFromFile("3.png");
	tgo.loadFromFile("go.png");
	

	s1.setTexture(t1);
	s2.setTexture(t2);
	s3.setTexture(t3);
	sgo.setTexture(tgo);

	s1.setPosition(300, 200);
	s2.setPosition(300, 200);
	s3.setPosition(300, 200);
	sgo.setPosition(300, 200);

	sprites[0] = s3;
	sprites[1] = s2;
	sprites[2] = s1;
	sprites[3] = sgo;

	

}
void UI::showCuentaRegresiva(RenderWindow& window, Sprite bg)
{
	
	

	for (int i = 0; i < 4; ++i)
	{
		window.clear();
		window.draw(bg);
		window.draw(sprites[i]);
		window.display();
		sleep(seconds(1));

	}
	
}
UI::UI() 
{

	background.loadFromFile("lowlevelhighspeed.png");
	backgroundSprite.setTexture(background);
	backgroundSprite.setScale(0.8, 0.7);
	textureBomb.loadFromFile("bomb.png");

	bombsCount.setTexture(textureBomb);
	bombsCount.setPosition(700, 20);
}
Sprite& UI::getBackgroundSprite()
{
	return backgroundSprite;
}
Sprite& UI::getBombCountSprite()
{
	return bombsCount;
}
Sprite& UI:: setBombCountNumbers(int cantidadBombas, bool _cambiotransparencia)
{
	s2.setScale(0.3,0.3);
	s2.setPosition(650, 0);
	if (cantidadBombas == 1)
	{
		s2.setTexture(t1);
	}
	else if (cantidadBombas == 0)
	{
		s2.setTexture(t2);
	}
	else 
	{
		s2.setPosition(-100, -100);
	}
	return s2;
}
void UI::aplicarTransparencia(bool cambioTransparencia)
{
	if (cambioTransparencia == true)
	{
		bombsCount.setColor(Color(225, 225, 225, 125));
	}
}
void UI::setLoserSprite()
{
	loserTex.loadFromFile("gameover.png");
	loserSprite.setTexture(loserTex);
	loserSprite.setScale(0.5, 0.5);
}
Sprite UI::getLoserSprite()
{
	return loserSprite;
}
void UI::setWinnerScreen()
{
	winnerTex.loadFromFile("winnerscreen.png");
	winnerSprite.setTexture(winnerTex);
	winnerSprite.setScale(0.5, 0.5);
}
Sprite UI::getWinnerScreen()
{
	return winnerSprite;
}