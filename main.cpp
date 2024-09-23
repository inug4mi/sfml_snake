#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "draw_shape.hpp"
#include "constants.hpp"
#include <vector>
// corrutinas c++
// namespaces
// metaprogramacion
// inline
// constexpr
int main()
{
    sf::RenderWindow window(sf::VideoMode(Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT), "SFML Snake", sf::Style::Close);
    window.setFramerateLimit(12);
    // import my shape's class
    MyShape::DrawShape drawShape;

    // grid
    std::vector<sf::VertexArray> grid = drawShape.grid();

    // snake head
    sf::RectangleShape snakeHead = drawShape.square(
        Constants::SNAKE_SIZE*Constants::SNAKE_Xi,
        Constants::SNAKE_SIZE*Constants::SNAKE_Yi,
        Constants::SNAKE_SIZE,
        sf::Color::Green,
        0, 
        sf::Color::Green
    );
    sf::Vector2f snakeHeadPosition = snakeHead.getPosition();
    float lastSnakeHeadXi = snakeHeadPosition.x;
    float lastSnakeHeadYi = snakeHeadPosition.y;
    std::vector<sf::RectangleShape> snakeBody(1601);
    snakeBody.push_back(snakeHead);

    // apple 
    sf::RectangleShape apple = drawShape.square(
        Constants::APPLE_SIZE*Constants::APPLE_Xi,
        Constants::APPLE_SIZE*Constants::APPLE_Yi,
        Constants::APPLE_SIZE,
        sf::Color::Red, 
        0
    );

    // manejar direccion de movimiento
    sf::Vector2f direction(Constants::MOVE_STEP, 0.0f);

    // main loop
    while (window.isOpen())
    {
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
                        if (direction. y == 0){                          
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

        // draw snake
        window.draw(snakeHead);
        snakeHead.move(direction);
        if (drawShape.collisionBetween(snakeHead, apple)){
            snakeHeadPosition = snakeBody[snakeBody.size()-1].getPosition();
            lastSnakeHeadXi = snakeHeadPosition.x;
            lastSnakeHeadYi = snakeHeadPosition.y;
            snakeBody.push_back(drawShape.square(
                lastSnakeHeadXi,
                lastSnakeHeadYi,
                Constants::SNAKE_SIZE,
                sf::Color::Green,
                0, 
                sf::Color::Green
                )
            );
        }
        sf::Vector2f snakeHeadPosition = snakeHead.getPosition();              
        for (int i = snakeBody.size() - 1; i > 0; i--){
            
            snakeBody[i].setPosition(snakeHeadPosition);
            sf::Vector2 snakeLastPartPosition = snakeBody[i].getPosition();
            snakeBody[i-1].setPosition(snakeLastPartPosition);
        }


        for (int i = 0; i < snakeBody.size(); i++) {
            window.draw(snakeBody[i]);
        }
        window.draw(apple);

        // show content
        window.display();
    }

    return 0;
}