#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "constants.hpp"

namespace GEngine{
    class Shape2D{
    public:
        sf::RectangleShape square(double xi, double yi, double size, sf::Color color);
        sf::RectangleShape rectangle(double xi, double yi, sf::Vector2f size, sf::Color color);
        sf::VertexArray line(double xi, double yi, double xf, double yf, sf::Color color);
        std::vector<sf::VertexArray> grid();
        //bool collisionBetween(sf::RectangleShape rectangleShape1, sf::RectangleShape rectangleShape2);
    };
}