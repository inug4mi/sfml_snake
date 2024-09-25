#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "shape.hpp"
#include "constants.hpp"
#include <vector>
#include <iostream>
#include <random>

int main()
{
    sf::RenderWindow window(sf::VideoMode(Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT), "SFML Snake", sf::Style::Close);
    window.setFramerateLimit(12);
 
    // random seed
    std::random_device rd; // random seed
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0,(int)(Constants::SCREEN_WIDTH/Constants::SNAKE_SIZE) - 1);

    sf::Vector2f randomSnakePosition(distr(gen),distr(gen));
    sf::Vector2f randomApplePosition(distr(gen),distr(gen));

    // import my shape's class
    MyShape::Shape shape;

    // grid
    std::vector<sf::VertexArray> grid = shape.grid();

    // Snake head border thickness
    const int thickness = 0;
    bool paused = false; // pause button

    // snake head
    sf::RectangleShape snakeHead = shape.square(
        Constants::SNAKE_SIZE * Constants::SNAKE_Xi,
        Constants::SNAKE_SIZE * Constants::SNAKE_Yi,
        Constants::SNAKE_SIZE,
        sf::Color::Green,
        thickness,
        sf::Color::White
    );

    std::vector<sf::RectangleShape> snakeBody;
    snakeBody.push_back(snakeHead);

    // apple 
    sf::RectangleShape apple = shape.square(
        Constants::APPLE_SIZE * (int)randomApplePosition.x,
        Constants::APPLE_SIZE * (int)randomApplePosition.y,
        Constants::APPLE_SIZE,
        sf::Color::Red,
        0,
        sf::Color::Black
    );

    // manejar direccion de movimiento
    //sf::Vector2f direction(Constants::MOVE_STEP, 0.0f);
    sf::Vector2f direction(0.0f, 0.0f);

    int score = 0;

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

        // background color
        window.clear(Constants::BG_COLOR);

        // drawing grid
        for (const sf::VertexArray line : grid) window.draw(line);

        
        // Guardar las posiciones anteriores de todas las partes de la serpiente
        std::vector<sf::Vector2f> previousPositions;
        for (auto& part : snakeBody)
            previousPositions.push_back(part.getPosition());

        if (!paused){
            snakeBody[0].move(direction);
            // Hacer que cada parte siga a la anterior
            for (size_t i = 1; i < snakeBody.size(); i++) {
                snakeBody[i].setPosition(previousPositions[i - 1]);
            }
        }

        window.draw(apple);
        // draw snake body
        for (int i = 0; i < snakeBody.size(); i++) {
            window.draw(snakeBody[i]);
        }
        // colision entre cabeza y cualquier otra parte del cuerpo de la serpiente
        if (!paused){
            for (int i = 1; i < snakeBody.size(); i++){
                if (shape.collisionBetween(snakeBody[0], snakeBody[i])){
                    snakeBody[i].setFillColor(sf::Color::Yellow);
                    snakeBody[i].setOutlineColor(sf::Color::White);
                    paused = true;
                }
            }
        
            // Colision entre serpiente y la manzana
            if (shape.collisionBetween(snakeBody[0], apple)) {
                sf::Vector2f lastPosition = previousPositions.back();
                snakeBody.push_back(shape.square(
                    lastPosition.x,
                    lastPosition.y,
                    Constants::SNAKE_SIZE,
                    sf::Color::Green,
                    thickness,
                    sf::Color::Green
                ));
                score++;
                std::cout << "Score: " << score << std::endl;
                bool newApple = false;
                while (!newApple){
                    newApple = true;
                    int newApplePosX = (int)distr(gen)*Constants::APPLE_SIZE;
                    int newApplePosY = (int)distr(gen)*Constants::APPLE_SIZE;
                    for (size_t i = 0; i < snakeBody.size(); i++) {
                        sf::Vector2f posi = snakeBody[i].getPosition();
                        std::cout << "newApplePosX: " << newApplePosX << ", newApplePosY: " << newApplePosY << std::endl;
                        std::cout << "BodyPartX: " << posi.x << ", BodyPartY: " << posi.y << std::endl;
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
        window.display();
    }

    return 0;
}
