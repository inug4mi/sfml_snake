#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "draw_shape.hpp"
#include "constants.hpp"
// corrutinas c++
// namespaces
// metaprogramacion
// inline
// constexpr
int main()
{
    sf::RenderWindow window(sf::VideoMode(Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT), "SFML Snake", sf::Style::Close);
    
    // import my shape's class
    MyShape::DrawShape drawShape;

    // grid
    std::vector<sf::VertexArray> grid = drawShape.grid();

    // snake head
    sf::RectangleShape snakeHead = drawShape.square(Constants::SNAKE_SIZE*3,Constants::SNAKE_SIZE*3,Constants::SNAKE_SIZE,sf::Color::Green);

    // main loop
    while (window.isOpen())
    {
        // events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // background color
        window.clear(Constants::BG_COLOR);

        // drawing grid
        for (const sf::VertexArray line : grid) window.draw(line);

        // draw snake
        window.draw(snakeHead);

        // show content
        window.display();
    }

    return 0;
}