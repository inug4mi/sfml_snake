#pragma once

#include <SFML/Graphics.hpp>

namespace Constants{
    constexpr int SNAKE_Xi = 2;
    constexpr int SNAKE_Yi = 2;
    constexpr int SNAKE_SIZE = 35;
    constexpr int APPLE_SIZE = SNAKE_SIZE;
    constexpr int APPLE_Xi = 9;
    constexpr int APPLE_Yi = 9;
    constexpr int SCREEN_WIDTH = 525;
    constexpr int SCREEN_HEIGHT = 525;
    constexpr int GRID_SIZE = SCREEN_WIDTH/SNAKE_SIZE;
    const float MOVE_STEP = SNAKE_SIZE;
    
    inline const sf::Color BG_COLOR = sf::Color(15,15,15); 
    inline const sf::Color GRID_COLOR = sf::Color(30,30,30);
    inline const sf::Color TEXT_COLOR = sf::Color(20,20,20);
}