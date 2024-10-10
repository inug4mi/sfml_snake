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
#include "game.hpp"
#include "game_over_window.hpp"

namespace GEngine{
	class SceneManager{
	public:
		SceneManager();

		// engine window
		Renderer renderer;

		// Estado global del juego
		GameState currentState;

		// global variables
		Variables variables;

		// Formas
		Shape2D shape;

		// Textos
		Text text;

		// engine sound
		SoundManager soundManager;

		// engine collision
		Collision collision;
		
		//engine database
		Database db;

		MainMenuWindow mainMenuWindow;
        Game game;
        GameOverWindow gameOverWindow;

		void SceneSelector();
	};
}
