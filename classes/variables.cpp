#include "variables.hpp"

namespace GEngine{
    // Constructor
    Variables::Variables() : paused(false), game_lost(false), score(0) {}

    // Accessor methods
    bool Variables::isPaused() const {
        return paused;
    }

    bool Variables::isGameLost() const {
        return game_lost;
    }

    int Variables::getScore() const {
        return score;
    }

    // Mutator methods
    void Variables::setPaused(bool state) {
        paused = state;
    }

    void Variables::setGameLost(bool state) {
        game_lost = state;
    }

    void Variables::addScore(int points) {
        score += points;
    }

}