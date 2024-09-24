#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "constants.hpp"

namespace MyShape{
    class Shape{
    public:
        sf::RectangleShape square(double xi, double yi, double size, sf::Color color, double thick = 1, sf::Color outlineColor = sf::Color::Red);
        sf::VertexArray line(double xi, double yi, double xf, double yf, sf::Color color);
        std::vector<sf::VertexArray> grid();
        

        bool collisionBetween(sf::RectangleShape rectangleShape1, sf::RectangleShape rectangleShape2);
    };
}