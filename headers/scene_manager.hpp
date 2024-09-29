#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
//#include <SFML/Audio.hpp>
#include "constants.hpp"
#include "renderer.hpp"
#include "shape2D.hpp"
#include "text.hpp"
#include "collision.hpp"
#include "variables.hpp"
#include "database.hpp"
#include "sound_manager.hpp"
#include "game_state.hpp"
#include "main_menu_window.hpp"
#include <vector>
#include <iostream>

class SceneManager{
public:
    SceneManager();
	~SceneManager();

    // engine window
	GEngine::Renderer renderer;

	GameState currentState;
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

	MainMenuWindow mainMenuWindow;

    void SceneSelector();
};

