#include "variables.hpp"

namespace GEngine{
    // Constructor
    Variables::Variables() : paused(false), game_lost(false), score(0) {
        std::mt19937 gen(rd());
    }

    int Variables::generateRandomInt(int from, int to) {
        std::uniform_int_distribution<> distr(from,to);
        return distr(gen);
    }

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