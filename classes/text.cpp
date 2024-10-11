#include "text.hpp"

namespace GEngine{
    int Text::good(){
        if (!(font).loadFromFile("fonts/Arial.ttf")) {
            // Error al cargar la fuente
            std::cerr << "font error when loading not found" << std::endl;
            return -1;
        }
        return 0;
    }
    sf::Text Text::write(std::string text, int size, sf::Color color){
        sf::Text new_text;
        new_text.setFont(font);
        new_text.setCharacterSize(size);
        new_text.setFillColor(color);
        new_text.setString(text);
        return new_text;
    }
    bool Text::isTextClicked(const sf::Text& text, const sf::Vector2i& mousePos) {
        // Convertir las coordenadas del mouse al sistema de coordenadas de SFML
        sf::FloatRect textBounds = text.getGlobalBounds();
        return textBounds.contains(static_cast<sf::Vector2f>(mousePos));
    }
}