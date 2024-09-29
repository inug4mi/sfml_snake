#include "sound_manager.hpp"
#include <iostream>

namespace GEngine {

    // Cargar un archivo de sonido en el SoundBuffer
    bool SoundManager::loadSound(const std::string &name, const std::string &filePath) {
        sf::SoundBuffer buffer;
        if (!buffer.loadFromFile(filePath)) {
            std::cerr << "Error: No se pudo cargar el sonido desde " << filePath << std::endl;
            return false;
        }
        soundBuffers[name] = buffer;
        sounds[name].setBuffer(soundBuffers[name]);
        return true;
    }

    // Reproducir un sonido
    void SoundManager::playSound(const std::string &name) {
        if (sounds.find(name) != sounds.end()) {
            sounds[name].play();
        } else {
            std::cerr << "Error: Sonido no encontrado: " << name << std::endl;
        }
    }

    // Cargar música
    bool SoundManager::loadMusic(const std::string &filePath) {
        if (!music.openFromFile(filePath)) {
            std::cerr << "Error: No se pudo cargar la música desde " << filePath << std::endl;
            return false;
        }
        return true;
    }

    // Reproducir música
    void SoundManager::playMusic() {
        music.play();
    }

    // Pausar música
    void SoundManager::pauseMusic() {
        music.pause();
    }

    // Detener música
    void SoundManager::stopMusic() {
        music.stop();
    }

    // Ajustar el volumen de la música
    void SoundManager::setMusicVolume(float volume) {
        music.setVolume(volume);
    }

}
