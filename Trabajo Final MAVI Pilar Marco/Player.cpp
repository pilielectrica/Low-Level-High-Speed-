#include "Player.h"
#include <SFML/Window/Keyboard.hpp>

void Player::set_Player()
{

	texture_player.loadFromFile("Red_Car.png");
	player.setTexture(texture_player);
    player.setPosition(430, 470);
    
}

Sprite& Player::get_Player_Sprite()
{
	return player;
}
void Player::acelerar_Player(float deltaTime)
{
	// Acelerar
	if (Keyboard::isKeyPressed(Keyboard::Right)) {
        velocity.x = 100;
        if (velocity.x > maxvelocity.x)
        {
            velocity.x = maxvelocity.x;
        }
	}
	else if (Keyboard::isKeyPressed(Keyboard::Left)) {
       
            velocity.x = -100;
     
        if (velocity.x < -maxvelocity.x)
        {
            velocity.x = -maxvelocity.x;
        }
	}
	else if (Keyboard::isKeyPressed(Keyboard::Up)) {
		velocity.y -= acceleration_y * deltaTime;
        if (velocity.y < maxvelocity.y)
        {
            velocity.y = maxvelocity.y;
        }
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down)) {
		velocity.y += acceleration_y * deltaTime;
        if (velocity.y > minvelocity.y)
        {
            velocity.y = minvelocity.y;
        }
	}
    else
        // Desaceleración suave en Y
        if (!Keyboard::isKeyPressed(Keyboard::Up) && !Keyboard::isKeyPressed(Keyboard::Down)) {
            if (velocity.y > 0) {
                velocity.y -= desacceleration_y * deltaTime;
                if (velocity.y < 0) velocity.y = 0;
            }
            else if (velocity.y < 0) {
                velocity.y += desacceleration_y * deltaTime;
                if (velocity.y > 0) velocity.y = 0;
            }
        }
    // Desaceleración suave en X
    if (!Keyboard::isKeyPressed(Keyboard::Left) && !Keyboard::isKeyPressed(Keyboard::Right)) {
        if (velocity.x > 0) {
            velocity.x -= desacceleration_x * deltaTime;
            if (velocity.x < 0) velocity.x = 0;
        }
        else if (velocity.x < 0) {
            velocity.x += desacceleration_x * deltaTime;
            if (velocity.x > 0) velocity.x = 0;
        }
    }



	//cout << "Velocidad = " << velocity.y << endl;

	// Mover
	position.x += velocity.x * deltaTime;
	position.y += velocity.y * deltaTime;
	player.setPosition(position);
    //cout << "vel: " << velocity.y << " " << velocity.x << endl;
 
}
void Player::limitarMovimiento(const sf::RenderWindow& window) {
    sf::Vector2f pos = player.getPosition();
    sf::FloatRect bounds = player.getGlobalBounds();

    // Rebote en el borde izquierdo
    if (pos.x < 120) {
        pos.x = 120;
        if (velocity.x < 0) // Solo rebota si va hacia la izquierda
            velocity.x *= -0.5f;
    }

    // Rebote en el borde derecho
    if (pos.x > 612) {
        pos.x = 612;
        if (velocity.x > 0) // Solo rebota si va hacia la drecha
            velocity.x *= -0.5f;
    }

    // Rebote en el borde superior
    if (pos.y < 300) {
        pos.y = 300;

    }

    // Rebote en el borde inferior
    if (pos.y + bounds.height > window.getSize().y) {
        pos.y = window.getSize().y - bounds.height;
        velocity.y *= -0.1f;
    }

    player.setPosition(pos);
}
Vector2f Player::get_Player_Velocity()
{
    return velocity;
}
void Player::lanzarBomba(float deltaTime, bool _desaparecerBomba)
{
    bomba.lanzarBomb(deltaTime, _desaparecerBomba);
}
Player::Player()
{

}
void Player::morir(int& vidas, bool& derrota)
{
    if (vidas == 0)
    {
        derrota = true;
        vidas = 0;
    }
}