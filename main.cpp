#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "shape.hpp"
#include "constants.hpp"
#include <vector>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT), "SFML Snake", sf::Style::Close);
    window.setFramerateLimit(12);
    // import my shape's class
    MyShape::Shape shape;

    // grid
    std::vector<sf::VertexArray> grid = shape.grid();

    // snake head
    sf::RectangleShape snakeHead = shape.square(
        Constants::SNAKE_SIZE * Constants::SNAKE_Xi,
        Constants::SNAKE_SIZE * Constants::SNAKE_Yi,
        Constants::SNAKE_SIZE,
        sf::Color::Green,
        0,
        sf::Color::Green
    );

    std::vector<sf::RectangleShape> snakeBody;
    snakeBody.push_back(snakeHead);

    // apple 
    sf::RectangleShape apple = shape.square(
        Constants::APPLE_SIZE * Constants::APPLE_Xi,
        Constants::APPLE_SIZE * Constants::APPLE_Yi,
        Constants::APPLE_SIZE,
        sf::Color::Red,
        0
    );

    // manejar direccion de movimiento
    sf::Vector2f direction(Constants::MOVE_STEP, 0.0f);

    // main loop
    while (window.isOpen())
    {
        sf::Vector2f snakeHeadPosition = snakeBody[0].getPosition(); 

        // events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                    case sf::Keyboard::W:
                        direction.x = 0.0f;
                        if (direction.y == 0){
                            
                            direction.y = -Constants::MOVE_STEP;
                        }
                        break;
                    
                    case sf::Keyboard::S:
                        direction.x = 0.0f;
                        if (direction.y == 0){
                            
                            direction.y = Constants::MOVE_STEP;
                        }
                        break;
                    
                    case sf::Keyboard::A:
                        direction.y = 0.0f;
                        if (direction.x == 0){
                            
                            direction.x = -Constants::MOVE_STEP;
                        }
                        break;

                    case sf::Keyboard::D:
                        direction.y = 0.0f;
                        if (direction.x == 0){
                            
                            direction.x = Constants::MOVE_STEP;
                        }
                        break;

                    default:
                        break;
                }
            }
        }

        // Guardar las posiciones anteriores de todas las partes de la serpiente
        std::vector<sf::Vector2f> previousPositions;
        for (auto& part : snakeBody)
            previousPositions.push_back(part.getPosition());

        // Mover la cabeza
        snakeBody[0].move(direction);

        // Hacer que cada parte siga a la anterior
        for (size_t i = 1; i < snakeBody.size(); i++) {
            snakeBody[i].setPosition(previousPositions[i - 1]);
        }

        // background color
        window.clear(Constants::BG_COLOR);

        // drawing grid
        for (const sf::VertexArray line : grid) window.draw(line);

        // draw snake body
        for (int i = 0; i < snakeBody.size(); i++) {
            window.draw(snakeBody[i]);
        }

        // Colision entre serpiente y la manzana
        if (shape.collisionBetween(snakeBody[0], apple)) {
            sf::Vector2f lastPosition = previousPositions.back();
            snakeBody.push_back(shape.square(
                lastPosition.x,
                lastPosition.y,
                Constants::SNAKE_SIZE,
                sf::Color::Green,
                0,
                sf::Color::Green
            ));
            std::cout << "Score: " << snakeBody.size() << std::endl;
        }

        window.draw(apple);

        // show content
        window.display();
    }

    return 0;
}
