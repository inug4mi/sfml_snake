#include "main_menu_window.hpp"

MainMenuWindow::MainMenuWindow(): 
        //renderer(Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT, "SFML Snake"),
      variables(), 
      shape(), 
      text(), 
      collision(), 
      db("snakedb1.txt"), 
      soundManager(), 
      currentState(GameState::MainMenu){
	if (text.good() == -1) {
		std::cerr << "Error loading font" << std::endl;
		// Aquí podrías manejar el error
	}
 	mainMenuText = text.write("SFMLSNAKE", 100, sf::Color::White);    // Initialization or setup logic, if needed
}

void MainMenuWindow::run(GEngine::Renderer& renderer) {
	renderer.wpollEventsMainMenu(variables, currentState);
	
	// UPDATE ///

	// RENDER ///
	renderer.wclear(Constants::BG_COLOR);
    renderer.wdraw(mainMenuText);
	renderer.wdisplay();    // Add logic for running the Main Menu
}