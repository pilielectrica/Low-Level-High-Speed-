#pragma once
#include <SFML/Audio.hpp>
#include <iostream>

class Audio {
private:
    sf::Music backgroundMusic;
    sf::SoundBuffer motorBuffer;
    sf::SoundBuffer ambienteBuffer;
    sf::SoundBuffer choqueBuffer;
    sf::SoundBuffer bombaBuffer;

    sf::Sound motorSound;
    sf::Sound ambienteSound;
    sf::Sound choqueSound;
    sf::Sound bombaSound;

public:
    Audio();

    void playBackgroundMusic();
    void stopBackgroundMusic();

    void playMotorSound();
    void stopMotorSound();

    void playAmbienteSound();
    void stopAmbienteSound();

    void playChoqueSound();
    void playBombSound();
};

