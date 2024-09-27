#pragma once
#include <string>
#include <vector>

namespace GEngine{
// Clase para manejar la base de datos del juego (lectura/escritura de archivos)
class Database {
public:
    // Constructor que toma el nombre del archivo como parámetro
    Database(const std::string& filename);

    // Método para leer el archivo y obtener una lista de jugadores y puntajes
    std::vector<std::pair<std::string, int>> readDatabase();

    // Método para agregar una nueva entrada (jugador y puntaje)
    void addNonExistingPlayerScore(const std::string& playerName, int score);

    void addExistingPlayerScore(const std::string& playerName, int score);

    // Método para crear un archivo de base de datos nuevo (si no existe)
    void createDatabase();

    void showDatabaseInfo();

private:
    // Nombre del archivo donde se guardarán los datos
    std::string filename;

    // Método privado para verificar si el archivo existe
    bool fileExists(const std::string& filename);
};
}