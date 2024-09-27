#include "Database.hpp"
#include <fstream>
#include <iostream>

namespace GEngine{
    // Constructor
    Database::Database(const std::string& filename) : filename(filename) {
        // Verifica si el archivo ya existe; si no, lo crea
        if (!fileExists(filename)) {
            createDatabase();
        }
    }

    // Método para verificar si el archivo existe
    bool Database::fileExists(const std::string& filename) {
        std::ifstream file(filename);
        return file.good();
    }

    // Método para crear un nuevo archivo de base de datos
    void Database::createDatabase() {
        std::ofstream file(filename);
        if (!file) {
            std::cerr << "Error: No se pudo crear la base de datos." << std::endl;
            return;
        }
        std::cout << "Base de datos creada: " << filename << std::endl;
        file.close();
    }

    // Método para leer la base de datos y devolver una lista de jugadores y puntajes
    std::vector<std::pair<std::string, int>> Database::readDatabase() {
        std::vector<std::pair<std::string, int>> playerScores;
        std::ifstream file(filename);
        
        if (!file) {
            std::cerr << "Error al abrir el archivo: " << filename << std::endl;
            return playerScores;
        }

        std::string playerName;
        int score;

        // Lee cada línea del archivo
        while (file >> playerName >> score) {
            playerScores.push_back({playerName, score});
        }

        file.close();
        return playerScores;
    }

    // Método para agregar un nuevo jugador y su puntaje al archivo
    void Database::addNonExistingPlayerScore(const std::string& playerName, int score) {
        std::ofstream file(filename, std::ios::app); // Abre el archivo en modo append

        if (!file) {
            std::cerr << "Error al abrir el archivo: " << filename << std::endl;
            return;
        }

        // Escribe el nombre del jugador y su puntaje en el archivo
        file << playerName << " " << score << std::endl;

        file.close();
    }

    void Database::addExistingPlayerScore(const std::string& playerName, int score){
        std::vector<std::pair<std::string, int>> playerScores = readDatabase(); 
        bool playerFound = false;
    
        for (auto& entry : playerScores){
            if (entry.first == playerName){
                if (entry.second < score){
                    entry.second = score;
                }
                playerFound = true;
                break;
            }
        }
        if (!playerFound) addNonExistingPlayerScore(playerName, score);
    }   

    void Database::showDatabaseInfo(){
        std::cout << "Puntajes de los jugadores:" << std::endl;
        std::vector<std::pair<std::string, int>> playerScores = readDatabase();
        for (const auto& entry : playerScores) {
            std::cout << "Nombre: " << entry.first << ", Puntaje: " << entry.second << std::endl;
        }
    }
}