#include "draw_shape.hpp"


sf::VertexArray DrawShape::myLine(double xi, double yi, double xf, double yf, sf::Color color){
    sf::VertexArray line(sf::Lines, 2);
    line[0].position = sf::Vector2f(xi,yi);
    line[1].position = sf::Vector2f(xf,yf);
    line[0].color = color;
    line[1].color = color;
    return line;
}