#pragma once

#include <SFML/Graphics.hpp>
//#include <string>
#include "variables.hpp"
//#include "game_state.hpp"
//#include "text.hpp"
namespace GEngine {
    class Renderer {
    public:
        Renderer(int width, int height, const std::string &title);
        
        void wclear(const sf::Color &color);                       
        
        void wclose();
        
        void wdisplay();                                 
        
        bool wisOpen() const;                
        
        void wsetFramerateLimit(unsigned int limit); 
        
        template <typename T>
        void wdraw(const T &object) {
            window.draw(object);
        }

        void wpollEventsPlaying(GEngine::Variables &variables, sf::Vector2f &direction);   
        //void wpollEventsMainMenu(GEngine::Variables &variables, GameState &currentState, Text &text, sf::Text &startText);
        // hacer privado variable window
        sf::RenderWindow window;  
        sf::Event event;         
    };
}
