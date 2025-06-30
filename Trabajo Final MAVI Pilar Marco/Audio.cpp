#include "Audio.h"

Audio::Audio() {
    // Cargar música
    if (!backgroundMusic.openFromFile("audio//musica.ogg")) {
        std::cerr << "? Error al cargar la música de fondo\n";
    }

    // Cargar buffers de sonido
    if (!motorBuffer.loadFromFile("audio//motor.wav")) {
        std::cerr << "Error al cargar el sonido de motor\n";
    }
    if (!bombaBuffer.loadFromFile("audio//bomb.wav")) {
        std::cerr << "Error al cargar el sonido de bomba\n";
    }

    if (!ambienteBuffer.loadFromFile("audio//ambiente.wav")) {
        std::cerr << "Error al cargar el sonido de ambiente\n";
    }

    if (!choqueBuffer.loadFromFile("audio//choque.wav")) {
        std::cerr << "Error al cargar el sonido de choque\n";
    }

    // Asociar buffers a los sonidos
    motorSound.setBuffer(motorBuffer);
    motorSound.setLoop(true); // opcional

    ambienteSound.setBuffer(ambienteBuffer);
    ambienteSound.setLoop(true); // opcional

    choqueSound.setBuffer(choqueBuffer);
    bombaSound.setBuffer(bombaBuffer);
}

void Audio::playBackgroundMusic() {
    backgroundMusic.setLoop(true);
    backgroundMusic.play();
}

void Audio::stopBackgroundMusic() {
    backgroundMusic.stop();
}

void Audio::playMotorSound() {
    motorSound.play();
}

void Audio::stopMotorSound() {
    motorSound.stop();
}

void Audio::playAmbienteSound() {
    ambienteSound.play();
}

void Audio::stopAmbienteSound() {
    ambienteSound.stop();
}

void Audio::playChoqueSound() {
    choqueSound.play();
}
void Audio::playBombSound()
{
    bombaSound.play();
}
