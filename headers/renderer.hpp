#pragma once

#include <SFML/Graphics.hpp>
#include <string>

namespace GEngine {
    class Renderer {
    public:
        Renderer(int width, int height, const std::string &title);
        
        void wclear(const sf::Color &color);                       // Clear the window
        void wclose();
        void wdisplay();                     // Display the frame
        void wpollEvents();                  // Poll and handle events
        bool wisOpen() const;                // Check if the window is open
        void wsetFramerateLimit(unsigned int limit); // Set the framerate limit
        template <typename T>
        void wdraw(const T &object) {
            window.draw(object);
        }

        // hacer privado variable window
        sf::RenderWindow window;            // SFML RenderWindow instance
    };
}
