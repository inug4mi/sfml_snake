#pragma once

#include <SFML/Graphics.hpp>
#include <string>

namespace GEngine {
    class Renderer {
    public:
        Renderer(int width, int height, const std::string &title);
        
        void clear(const sf::Color &color);                       // Clear the window
        void close();
        void display();                     // Display the frame
        void pollEvents();                  // Poll and handle events
        bool isOpen() const;                // Check if the window is open
        void setFramerateLimit(unsigned int limit); // Set the framerate limit
        template <typename T>
        void draw(const T &object) {
            window.draw(object);
        }

        // hacer privado variable window
        sf::RenderWindow window;            // SFML RenderWindow instance
    };
}
