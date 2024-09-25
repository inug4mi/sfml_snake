#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
namespace GEngine{
    class Text{
    public:
        sf::Font font;
        int good();
        sf::Text write(std::string text, int size, sf::Color color);
    };
}