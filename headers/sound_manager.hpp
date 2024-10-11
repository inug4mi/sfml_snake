#pragma once
#include <SFML/Audio.hpp>
#include <map>
#include <string>

namespace GEngine {

    class SoundManager {
    public:
        // Cargar un sonido
        bool loadSound(const std::string &name, const std::string &filePath);
        // Reproducir un sonido
        void playSound(const std::string &name);
        // Cargar música
        bool loadMusic(const std::string &filePath);
        // Reproducir música
        void playMusic();
        // Pausar música
        void pauseMusic();
        // Detener música
        void stopMusic();
        // Ajustar volumen de música
        void setMusicVolume(float volume);
        
    private:
        std::map<std::string, sf::SoundBuffer> soundBuffers; // Para almacenar múltiples efectos de sonido
        std::map<std::string, sf::Sound> sounds;             // Para reproducir los sonidos
        sf::Music music;                                     // Para manejar la música de fondo
    };

}
