#include "Background.h"

void Background::set_Background()
{
	texture_background.loadFromFile("Street.png");
	background1.setTexture(texture_background);
	background2.setTexture(texture_background);
    
    int texture_size_y = texture_background.getSize().y;

	background1.setPosition(-20, 0);
	background2.setPosition(-20, -texture_size_y);

}
Sprite& Background::get_Background1_Sprite()
{
	return background1;
}
Sprite& Background::get_Background2_Sprite()
{
    return background2;
}
void Background::updateBackground(float playerSpeedY) {
    // Usamos la velocidad del jugador como scroll
    scroll_speed = -playerSpeedY;

    background1.move(0, scroll_speed);
    background2.move(0, scroll_speed);

    float height = texture_background.getSize().y;

    if (background1.getPosition().y >= height)
        background1.setPosition(-20, background2.getPosition().y - height);
    else if (background1.getPosition().y <= -height)
        background1.setPosition(-20, background2.getPosition().y + height);

    if (background2.getPosition().y >= height)
        background2.setPosition(-20, background1.getPosition().y - height);
    else if (background2.getPosition().y <= -height)
        background2.setPosition(-20, background1.getPosition().y + height);

}