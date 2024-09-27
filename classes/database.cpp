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

    void Database::addPlayerScore(const std::string& playerName, int& score) {
        std::vector<std::pair<std::string, int>> playerScores = readDatabase();
        bool playerFound = false;

        // Busca si el jugador ya existe en la base de datos
        for (auto& entry : playerScores) {
            if (entry.first == playerName) {
                playerFound = true;
                // Si el puntaje actual es mayor que el anterior, lo actualizamos
                if (entry.second < score) {
                    entry.second = score;
                }
                break;
            }
        }

        // Si el jugador no fue encontrado, lo agregamos con su puntaje
        if (!playerFound) {
            playerScores.push_back(std::make_pair(playerName, score));
        }

        // Sobreescribimos el archivo con los datos actualizados
        std::ofstream file(filename); // Modo por defecto: truncar el archivo

        if (!file) {
            std::cerr << "Error al abrir el archivo: " << filename << std::endl;
            return;
        }

        // Escribimos todos los jugadores y sus puntajes en el archivo
        for (const auto& entry : playerScores) {
            file << entry.first << " " << entry.second << std::endl;
        }

        file.close();
    }


    void Database::showDatabaseInfo(){
        std::cout << "Puntajes de los jugadores:" << std::endl;
        std::vector<std::pair<std::string, int>> playerScores = readDatabase();
        for (const auto& entry : playerScores) {
            std::cout << "Nombre: " << entry.first << ", Puntaje: " << entry.second << std::endl;
        }
    }
}