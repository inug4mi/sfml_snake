#include "renderer.hpp"
#include "constants.hpp"
#include <iostream>
namespace GEngine {
    Renderer::Renderer(int width, int height, const std::string &title) {
        window.create(sf::VideoMode(width, height), title, sf::Style::Close);
        //window.setFramerateLimit(60); // Default frame limit
    }

    void Renderer::wclear(const sf::Color &color) {
        window.clear(color); // Clear the window
    }

    void Renderer::wclose(){
        window.close();
    }

    void Renderer::wdisplay() {
        window.display(); // Display the rendered frame
    }

    bool Renderer::wisOpen() const {
        return window.isOpen(); // Return window status
    }

    void Renderer::wsetFramerateLimit(unsigned int limit) {
        window.setFramerateLimit(limit); // Set the framerate limit
    }

//    void Renderer::wpollEventsMainMenu(GEngine::Variables &variables, GameState &currentState, Text &text, sf::Text &startText){
//      while (window.pollEvent(event))
//          {
//            if (event.type == sf::Event::Closed)
//                window.close();
//
//            if (event.type == sf::Event::KeyPressed)
//            {
//            }
//            if (event.type == sf::Event::MouseButtonPressed) {
//                std::cout << "mouse pressed" << std::endl;
//
//                if (event.mouseButton.button == sf::Mouse::Left) {
//                    // Obtener las coordenadas del mouse
//                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
//                    std::cout << "left clicked" << std::endl;
//                    // Verificar si el texto fue clicado
//                    if (text.isTextClicked(startText, mousePos)) {
//                        // Cambiar el color del texto como indicación de que fue clicado
//                        startText.setFillColor(sf::Color::Red);
//                        std::cout << "Texto clicado!" << std::endl;
//                    }
//                }
//            }
//
//        }
//    }

    void Renderer::wpollEventsPlaying(GEngine::Variables &variables, sf::Vector2f &direction) {
    
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape){
                    if (!variables.gameLost){
                        variables.pause = !variables.pause;
                    }
                }
        
                switch (event.key.code)
                {
                    case sf::Keyboard::W:
                        direction.x = 0.0f;
                        if (direction.y == 0){
                            direction.y = -Constants::MOVE_STEP;
                        }
                        break;
                    
                    case sf::Keyboard::S:
                        direction.x = 0.0f;
                        if (direction.y == 0){
                            direction.y = Constants::MOVE_STEP;
                        }
                        break;
                    
                    case sf::Keyboard::A:
                        direction.y = 0.0f;
                        if (direction.x == 0){
                            direction.x = -Constants::MOVE_STEP;
        
                        }
                        break;
        
                    case sf::Keyboard::D:
                        direction.y = 0.0f;
                        if (direction.x == 0){
                            direction.x = Constants::MOVE_STEP;
                        }
                        break;
        
                    default:
                        break;
                }
            }
        }
    }
}
