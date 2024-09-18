#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "draw_shape.hpp"

#define SNAKE_SIZE 20
#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600

int const GRID_SIZE = SCREEN_WIDTH/SNAKE_SIZE;

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML Snake", sf::Style::Close);
    
    DrawShape draw_shape;

    sf::VertexArray lines[GRID_SIZE];
    for (int i = 0; i < GRID_SIZE; i++){
        lines[i] = draw_shape.myLine(SNAKE_SIZE*i,0,SNAKE_SIZE*i,SCREEN_HEIGHT,sf::Color::Red);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(15,15,15));
        for (int i = 0; i < GRID_SIZE; i++){
            window.draw(lines[i]);
        }
        window.display();
    }

    return 0;
}