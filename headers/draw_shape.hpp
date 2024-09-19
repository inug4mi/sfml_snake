#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "constants.hpp"


class DrawShape{
public:
    sf::VertexArray myLine(double xi, double yi, double xf, double yf, sf::Color color);
    std::vector<sf::VertexArray> myGrid();
};