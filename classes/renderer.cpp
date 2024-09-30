#include "renderer.hpp"
#include "constants.hpp"
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

    void Renderer::wpollEventsMainMenu(GEngine::Variables &variables, GameState &currentState) {
    
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space){
                    currentState = GameState::Playing;
                }
            }
        }
    }

}
