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
    
    DrawShape draw_shape;

    sf::VertexArray lines[Constants::GRID_SIZE];
    for (int i = 0; i < Constants::GRID_SIZE; i++){
        lines[i] = draw_shape.myLine(Constants::SNAKE_SIZE*i,0,Constants::SNAKE_SIZE*i,Constants::SCREEN_HEIGHT,sf::Color::Red);
    }

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
        for (int i = 0; i < Constants::GRID_SIZE; i++){
            window.draw(lines[i]);
        }

        // show content
        window.display();
    }

    return 0;
}