#pragma once

#include <SFML/Graphics.hpp>

namespace Constants{
    constexpr int SNAKE_SIZE = 20;
    constexpr int SCREEN_WIDTH = 600;
    constexpr int SCREEN_HEIGHT = 600;
    constexpr int GRID_SIZE = SCREEN_WIDTH/SNAKE_SIZE;
    
    inline const sf::Color BG_COLOR = sf::Color(15,15,15); 
    inline const sf::Color GRID_COLOR = sf::Color(30,30,30);
}