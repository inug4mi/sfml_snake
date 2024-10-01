#pragma once
#include "renderer.hpp"
#include "shape2D.hpp"
#include "text.hpp"
#include "collision.hpp"
#include "variables.hpp"
#include "database.hpp"
#include "sound_manager.hpp"
#include "game_state.hpp"

class GameOverWindow {
public:
    GameOverWindow(
        GEngine::Renderer &renderer,         // Pass by reference
        GameState &currentState
    );
    // engine window
    GEngine::Renderer &renderer;

    GameState &currentState;
    // variables
    GEngine::Variables variables;

    // engine shape
    GEngine::Shape2D shape;

    // engine text
    GEngine::Text text;

    // engine sound
    GEngine::SoundManager soundManager;

    // engine collision
    GEngine::Collision collision;
    //engine database
    GEngine::Database db;

    sf::Text retryText;
    sf::Text quitText;

    void run();
};
