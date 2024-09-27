#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "renderer.hpp"
#include "shape2D.hpp"
#include "constants.hpp"
#include "text.hpp"
#include "collision.hpp"
#include "variables.hpp"
#include "database.hpp"
#include <vector>
#include <iostream>

int main()
{
    // these are changes
    /// Instantiating game engine ///

    // engine window
    GEngine::Renderer renderer(Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT, "SFML Snake");
    renderer.wsetFramerateLimit(12);

    // Base de datos
    GEngine::Database db("snakedb1.txt");
    //.addNonExistingPlayerScore("Inug4mi",0);

    // variables
    GEngine::Variables variables;

    // engine shape
    GEngine::Shape2D shape;

    // engine text
    GEngine::Text text;

    // engine collision
    GEngine::Collision collision;

    /// ******************* ///

    /// INGAME VARIABLES   ///

    // grid
    std::vector<sf::VertexArray> grid = shape.grid();

    // variables
    int text_w_offset = 85; // offset en texto del puntaje

    // snake head
    sf::RectangleShape snakeHead = shape.square(
        Constants::SNAKE_SIZE * Constants::SNAKE_Xi,
        Constants::SNAKE_SIZE * Constants::SNAKE_Yi,
        Constants::SNAKE_SIZE,
        sf::Color::Green
    );

    // snake head+body vector
    std::vector<sf::RectangleShape> snakeBody;
    snakeBody.push_back(snakeHead);

    // apple 
    sf::RectangleShape apple = shape.square(
        Constants::APPLE_SIZE * Constants::APPLE_Xi,
        Constants::APPLE_SIZE * Constants::APPLE_Yi,
        Constants::APPLE_SIZE,
        sf::Color::Red
    );

    // manejar direccion de movimiento
    sf::Vector2f direction(0.0f, 0.0f);

    // texto y fuente
    if (text.good() == -1) return -1;
    sf::Text scoreText = text.write(std::to_string(variables.score), 300, Constants::TEXT_COLOR);
    


    /// END INGAME VARIABLES ///

    // main loop
    while (renderer.wisOpen())
    {
        // update score text position
        if (variables.score > 9) text_w_offset = 170;
        scoreText.setPosition(Constants::SCREEN_WIDTH/2 - text_w_offset, 10);

        // track head position
        sf::Vector2f snakeHeadPosition = snakeBody[0].getPosition(); 

        // events
        renderer.wpollEvents(variables, direction);
        
        // background color
        renderer.wclear(Constants::BG_COLOR);

        // dibujar texto
        renderer.wdraw(scoreText);

        // drawing grid
        for (const sf::VertexArray line : grid) renderer.wdraw(line);
        

        // Guardar las posiciones anteriores de todas las partes de la serpiente
        std::vector<sf::Vector2f> previousPositions;
        for (auto& part : snakeBody)
            previousPositions.push_back(part.getPosition());

        if (!variables.pause){
            // mover cabeza en direccion
            snakeBody[0].move(direction);

            //std::cout << "xpos head: " <<snakeHeadPosition.x << std::endl;
            // si la cabeza sobrepasa un muro, aparece del otro lado
            if (snakeHeadPosition.x < 0) {
                snakeBody[0].setPosition(Constants::SCREEN_WIDTH - Constants::SNAKE_SIZE, snakeHeadPosition.y);
            } else if (snakeHeadPosition.x >= Constants::SCREEN_WIDTH) {
                snakeBody[0].setPosition(0, snakeHeadPosition.y);
            }

            // Si la cabeza sobrepasa un muro en el eje Y, aparece del otro lado
            if (snakeHeadPosition.y < 0) {
                snakeBody[0].setPosition(snakeHeadPosition.x, Constants::SCREEN_HEIGHT - Constants::SNAKE_SIZE);
            } else if (snakeHeadPosition.y >= Constants::SCREEN_HEIGHT) {
                snakeBody[0].setPosition(snakeHeadPosition.x, 0);
            }
            
            // Hacer que cada parte siga a la anterior
            for (size_t i = 1; i < snakeBody.size(); i++) {
                snakeBody[i].setPosition(previousPositions[i - 1]);
            }

        }

        renderer.wdraw(apple);
        // draw snake body
        for (int i = 0; i < snakeBody.size(); i++) {
            renderer.wdraw(snakeBody[i]);
        }

        // colision entre cabeza y cualquier otra parte del cuerpo de la serpiente
        if (!variables.pause){
            for (int i = 1; i < snakeBody.size(); i++){
                if (collision.between(snakeBody[0], snakeBody[i])){
                    snakeBody[i].setFillColor(sf::Color::Yellow);
                    snakeBody[i].setOutlineColor(sf::Color::White);
                    variables.pause = true;
                    variables.gameLost;
                    db.addPlayerScore("didib",variables.score);
                    //db.showDatabaseInfo();
                    //std::cout << "Final score: " << variables.score << std::endl;
                }
            }
        
            // Colision entre serpiente y la manzana
            if (collision.between(snakeBody[0], apple)) {
                sf::Vector2f lastPosition = previousPositions.back();
                snakeBody.push_back(shape.square(
                    lastPosition.x,
                    lastPosition.y,
                    Constants::SNAKE_SIZE,
                    sf::Color(-109*snakeBody.size(),233-snakeBody.size()*2,109-snakeBody.size())
                ));
                // score added
                variables.score++;
                // actualizar texto score
                scoreText.setString("" + std::to_string(variables.score));

                // la manzana cambia de posicion
                // la posicion NO PUEDE estar en una posicion del cuerpo de la serpiente
                bool newApple = false;
                while (!newApple){
                    newApple = true;
                    int newApplePosX = (int)variables.generateRandomInt(0,(int)((Constants::SCREEN_WIDTH/Constants::SNAKE_SIZE) - 1))*Constants::APPLE_SIZE;
                    int newApplePosY = (int)variables.generateRandomInt(0,(int)((Constants::SCREEN_WIDTH/Constants::SNAKE_SIZE) - 1))*Constants::APPLE_SIZE;
                    for (size_t i = 0; i < snakeBody.size(); i++) {
                        sf::Vector2f posi = snakeBody[i].getPosition();
                        //std::cout << "newApplePosX: " << newApplePosX << ", newApplePosY: " << newApplePosY << std::endl;
                        //std::cout << "BodyPartX: " << posi.x << ", BodyPartY: " << posi.y << std::endl;
                        if (newApplePosX == posi.x && newApplePosY == posi.y){
                            newApple = false;
                            break;
                        }
                    }
                    if (newApple) {
                        sf::Vector2f randomApplePosition(newApplePosX,newApplePosY);
                        apple.setPosition(randomApplePosition);
                    }
                }
            }
        }

        // show content
        renderer.wdisplay();
    }

    return 0;
}
