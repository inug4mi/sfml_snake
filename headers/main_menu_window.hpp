#pragma once
#include "renderer.hpp"
#include "game_state.hpp"
#include "text.hpp"
#include "constants.hpp"
#include <iostream>

class MainMenuWindow {
public:
    MainMenuWindow(
        GEngine::Renderer &renderer,
		GameState &currentState,
		GEngine::Text &text
    );
	// engine window
	GEngine::Renderer &renderer;
	GameState &currentState;
	GEngine::Text &text;

    sf::Text startText;
    sf::Text quitText;

    void run();
};
