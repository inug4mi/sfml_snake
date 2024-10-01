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
//#include "game.hpp"

namespace GEngine{
	class SceneManager{
	public:
		SceneManager();

		// engine window
		Renderer renderer;

		GameState currentState;
		// variables
		Variables variables;

		// engine shape
		Shape2D shape;

		// engine text
		Text text;

		// engine sound
		SoundManager soundManager;

		// engine collision
		Collision collision;
		//engine database
		Database db;

		MainMenuWindow mainMenuWindow;
        //Game game;

		void SceneSelector();
	};
}
