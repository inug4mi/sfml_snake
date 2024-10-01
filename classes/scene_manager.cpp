#include "scene_manager.hpp"
namespace GEngine{
    SceneManager::SceneManager() : 
        renderer(Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT, "SFML Snake"),
        variables(), 
        shape(), 
        text(), 
        collision(), 
        db("snakedb1.txt"), 
        soundManager(), 
        currentState(GameState::MainMenu),
        mainMenuWindow(renderer, currentState),
        game(renderer){
    }

    void SceneManager::SceneSelector() {
        while (renderer.wisOpen()) {
            switch (currentState) {
                case GameState::MainMenu:
                    mainMenuWindow.run();
                    break;
                case GameState::Playing:
                    game.handlePlaying();
                    break;
            }
        }
    }
}