#include "collision.hpp"
#include <SFML/Graphics.hpp>

namespace GEngine {
    bool Collision::between(const sf::RectangleShape& shape1, const sf::RectangleShape& shape2) {
        return shape1.getGlobalBounds().intersects(shape2.getGlobalBounds());
    }
}
