#include "Colisiones.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System.hpp>
#include <iostream>

using namespace sf;
using namespace std;

void Colisiones::detectBombColision(Sprite* enemy, Proyectil& _bomba)
{
    if (enemy->getGlobalBounds().intersects(_bomba.getBombSprite().getGlobalBounds()))
    {
        enemy->setPosition(-100, -100);
        cout << "colision bomba contra auto" << endl;
        _bomba.getBombSprite().setPosition(-200, -200);
        desaparecerBomba = true;
        audio.playBombSound();
  
    }
}
void Colisiones::detectPollitoColision(Afichmation& pollito, Player& player, int vidas)
{
    if (pollito.getGlobalBounds().intersects(player.get_Player_Sprite().getGlobalBounds()))
    {
        pollito.setPosition(-200, -300);
        vidas--;
        audio.playChoqueSound();
    }
}
bool Colisiones::colisionDetectCarPlayer(Sprite* enemy, Player& player, int& vidas, float deltaTime)
{
    if (estaInvulnerable)
    {
        tiempoInvulnerable -= deltaTime;
        if (tiempoInvulnerable <= 0.f)
        {
            estaInvulnerable = false;
        }
        return false;
    }

    FloatRect enemyBounds = enemy->getGlobalBounds();
    enemyBounds.left += 50;
    enemyBounds.top += 50;
    enemyBounds.width -= 60;
    enemyBounds.height -= 60;

    if (enemyBounds.intersects(player.get_Player_Sprite().getGlobalBounds()))
    {
        contadorColisiones++;
        audio.playChoqueSound();
        if (contadorColisiones == 1)
        {
            autoRoto = true;
            vidas--;
            cout << "colisionoooo" << endl;
            player.get_Player_Sprite().setTexture(autoRotoTex);
            player.get_Player_Sprite().setScale(0.075, 0.075);
            player.get_Player_Sprite().setTextureRect(IntRect(0, 0, autoRotoTex.getSize().x, autoRotoTex.getSize().y));
            player.get_Player_Sprite().setPosition(644.958, 470);
            player.position = { 644.958, 470 };
            player.get_Player_Velocity() = { 0, 0 };
        }

        if (contadorColisiones >= 2)
        {
            vidas--;
            lanzarHumo = true;
            player.get_Player_Sprite().setPosition(644.958, 470);
            player.position = { 644.958, 470 };
        }

        cout << "VIDAS RESTANTES: " << vidas << endl;

        // Activa invulnerabilidad por 2 segundos
        estaInvulnerable = true;
        tiempoInvulnerable = 2.f;
    }

    return autoRoto;
}

void Colisiones::animHumo()
{
    
    for (int i = 0; i < 14; ++i) {
        string filename = "smoke//" + to_string(i + 1) + ".png";
        if (!texturasHumo[i].loadFromFile(filename)) {
            cout << "no se cargo la textura del humo " << filename << endl;
        }
    }
}
void Colisiones::updateAnimHumo(float deltaTime, Vector2f playerPos)
{
    
    tiempo += deltaTime;
    if (tiempo >= 0.2)
    {
        tiempo = 0;
        if (volver == false)
        {
            frameAnim++;
        }
        else
        {
            frameAnim--;
        }
        
        if (frameAnim == 13) { volver = true; }
        if (frameAnim == 1) { volver = false; }
        spriteHumo.setTexture(texturasHumo[frameAnim], true); 
        
    }
    spriteHumo.setPosition(playerPos.x , playerPos.y);

}
Sprite& Colisiones::getHumoSprite()
{
    return spriteHumo;
}
bool& Colisiones::getlanzarHumo()
{
    return lanzarHumo;
}
Colisiones::Colisiones()
{
    autoRotoTex.loadFromFile("Red_Car_Broken.png");
    spriteHumo.setScale(0.2, 0.2);
    animHumo();
    spriteHumo.setTexture(texturasHumo[0]);
}