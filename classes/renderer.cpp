#include "renderer.hpp"

namespace GEngine {
    Renderer::Renderer(int width, int height, const std::string &title) {
        window.create(sf::VideoMode(width, height), title, sf::Style::Close);
        window.setFramerateLimit(60); // Default frame limit
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

   //void Renderer::pollEvents() {
   //    sf::Event event;
   //    while (window.pollEvent(event))
   //    {
   //        if (event.type == sf::Event::Closed)
   //            window.close();
   //        
   //        if (event.type == sf::Event::KeyPressed)
   //        {
   //            if (event.key.code == sf::Keyboard::Escape){
   //                if (!game_lost){
   //                    paused = !paused;
   //                }
   //            }
   //    
   //            switch (event.key.code)
   //            {
   //                case sf::Keyboard::W:
   //                    direction.x = 0.0f;
   //                    if (direction.y == 0){
   //                        direction.y = -Constants::MOVE_STEP;
   //                    }
   //                    break;
   //                
   //                case sf::Keyboard::S:
   //                    direction.x = 0.0f;
   //                    if (direction.y == 0){
   //                        direction.y = Constants::MOVE_STEP;
   //                    }
   //                    break;
   //                
   //                case sf::Keyboard::A:
   //                    direction.y = 0.0f;
   //                    if (direction.x == 0){
   //                        direction.x = -Constants::MOVE_STEP;
   //    
   //                    }
   //                    break;
   //    
   //                case sf::Keyboard::D:
   //                    direction.y = 0.0f;
   //                    if (direction.x == 0){
   //                        direction.x = Constants::MOVE_STEP;
   //                    }
   //                    break;
   //    
   //                default:
   //                    break;
   //            }
   //        }
   //    }
   //}w3|

    bool Renderer::wisOpen() const {
        return window.isOpen(); // Return window status
    }

    void Renderer::wsetFramerateLimit(unsigned int limit) {
        window.setFramerateLimit(limit); // Set the framerate limit
    }
}
