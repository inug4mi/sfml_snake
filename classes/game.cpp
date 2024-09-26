#include "game.hpp"

namespace GEngine{
    // Constructor
    Game::Game() : paused(false), game_lost(false), score(0) {}

    // Accessor methods
    bool Game::isPaused() const {
        return paused;
    }

    bool Game::isGameLost() const {
        return game_lost;
    }

    int Game::getScore() const {
        return score;
    }

    // Mutator methods
    void Game::setPaused(bool state) {
        paused = state;
    }

    void Game::setGameLost(bool state) {
        game_lost = state;
    }

    void Game::addScore(int points) {
        score += points;
    }

}