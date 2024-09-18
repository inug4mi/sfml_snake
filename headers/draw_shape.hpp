#pragma once
#include <SFML/Graphics.hpp>

class DrawShape{
public:
    sf::VertexArray myLine(double xi, double yi, double xf, double yf, sf::Color color);
};