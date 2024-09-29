#include "scene_manager.hpp"

SceneManager::SceneManager() 
    : renderer(Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT, "SFML Snake"),
      variables(), 
      shape(), 
      text(), 
      collision(), 
      db("snakedb1.txt"), 
      soundManager(), 
      currentState(GameState::MainMenu),
      mainMenuWindow() {
    
    renderer.wsetFramerateLimit(12);
}

void SceneManager::SceneSelector() {
    while (renderer.wisOpen()) {
        switch (currentState) {
            case GameState::MainMenu:
                mainMenuWindow.run(renderer);
                break;
            case GameState::Playing:
                // Handle game-playing logic
                break;
        }
    }
}
