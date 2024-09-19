#include "draw_shape.hpp"

sf::VertexArray DrawShape::myLine(double xi, double yi, double xf, double yf, sf::Color color){
    sf::VertexArray line(sf::Lines, 2);
    line[0].position = sf::Vector2f(xi,yi);
    line[1].position = sf::Vector2f(xf,yf);
    line[0].color = color;
    line[1].color = color;
    return line;
}

std::vector<sf::VertexArray> DrawShape::myGrid(){
    std::vector<sf::VertexArray> lines(Constants::GRID_SIZE*2+2);
    int currentIndex = 0;
    
    // horizontal lines
    for (int i = 0; i <= Constants::GRID_SIZE; i++){
        lines[currentIndex] = myLine(0, Constants::SNAKE_SIZE*i, Constants::SCREEN_WIDTH, Constants::SNAKE_SIZE*i, Constants::GRID_COLOR);
        currentIndex++;
    }

    // verrical lines
    for (int i = 0; i <= Constants::GRID_SIZE; i++){
        lines[currentIndex] = myLine(Constants::SNAKE_SIZE*i,0,Constants::SNAKE_SIZE*i,Constants::SCREEN_HEIGHT, Constants::GRID_COLOR);
        currentIndex++;
    }

    return lines;
}