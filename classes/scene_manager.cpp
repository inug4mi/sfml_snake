#include "scene_manager.hpp"

SceneManager::SceneManager():renderer(Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT, "SFML Snake"),
variables(), shape(), text(), collision(), db("snakedb1.txt"), soundManager(), currentState(GameState::MainMenu), direction(0.0f, 0.0f){
    renderer.wsetFramerateLimit(32);
}

void SceneManager::SceneSelector(){
	while (renderer.wisOpen()){	
		switch (currentState) {
			case GameState::MainMenu:
				handleMainMenu();
				break;
			case GameState::Playing:
				handlePlaying();
				break;
		}

	}
}