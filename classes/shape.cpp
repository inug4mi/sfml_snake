#include "shape.hpp"
#include <iostream>

namespace MyShape{

    sf::RectangleShape Shape::square(double xi, double yi, double size, sf::Color color, double thick, sf::Color outlineColor){
        sf::RectangleShape square(sf::Vector2f(size, size));
        square.setPosition(xi, yi);
        square.setFillColor(color);
        square.setOutlineThickness(thick);
        square.setOutlineColor(outlineColor);
        return square;
    }

    sf::VertexArray Shape::line(double xi, double yi, double xf, double yf, sf::Color color){
        sf::VertexArray line(sf::Lines, 2);
        line[0].position = sf::Vector2f(xi,yi);
        line[1].position = sf::Vector2f(xf,yf);
        line[0].color = color;
        line[1].color = color;
        return line;
    }

    std::vector<sf::VertexArray> Shape::grid(){
        std::vector<sf::VertexArray> lines(Constants::GRID_SIZE*2+2);
        int currentIndex = 0;
        
        // horizontal lines
        for (int i = 0; i <= Constants::GRID_SIZE; i++){
            lines[currentIndex] = line(0, Constants::SNAKE_SIZE*i, Constants::SCREEN_WIDTH, Constants::SNAKE_SIZE*i, Constants::GRID_COLOR);
            currentIndex++;
        }

        // verrical lines
        for (int i = 0; i <= Constants::GRID_SIZE; i++){
            lines[currentIndex] = line(Constants::SNAKE_SIZE*i,0,Constants::SNAKE_SIZE*i,Constants::SCREEN_HEIGHT, Constants::GRID_COLOR);
            currentIndex++;
        }

        return lines;
    }

    bool Shape::collisionBetween(sf::RectangleShape rectangleShape1, sf::RectangleShape rectangleShape2){
        if (rectangleShape1.getGlobalBounds().intersects(rectangleShape2.getGlobalBounds())){
            return true;
        }
        return false;
    }


}