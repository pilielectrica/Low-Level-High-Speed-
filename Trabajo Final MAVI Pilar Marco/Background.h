
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
#pragma once
class Background
{
private:
	Sprite background1;
	Sprite background2;
	Texture texture_background;
	float scroll_speed;
public:
	void set_Background();
	Sprite& get_Background1_Sprite();
	Sprite& get_Background2_Sprite();
	void updateBackground(float playerspeed);
};

