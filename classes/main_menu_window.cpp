#include "main_menu_window.hpp"

MainMenuWindow::MainMenuWindow(GEngine::Renderer &_renderer):
      renderer(_renderer),
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
	
 	startText = text.write("START GAME", 35, sf::Color::White);    // Initialization or setup logic, if needed
	startText.setPosition(102,90);

 	quitText = text.write("QUIT GAME", 35, sf::Color::White);    // Initialization or setup logic, if needed
	quitText.setPosition(115,270);
	renderer.wsetFramerateLimit(64);
}

void MainMenuWindow::run() {
	//renderer.wpollEventsMainMenu(variables, currentState, text, startText);
	while (renderer.window.pollEvent(renderer.event))
	{
		if (renderer.event.type == sf::Event::Closed)
			renderer.window.close();

		if (renderer.event.type == sf::Event::KeyPressed)
		{
		}
		if (renderer.event.type == sf::Event::MouseButtonPressed) {
			if (renderer.event.mouseButton.button == sf::Mouse::Left) {
				// Obtener las coordenadas del mouse
				sf::Vector2i mousePos = sf::Mouse::getPosition(renderer.window);
				// Verificar si el texto fue clicado
				if (text.isTextClicked(startText, mousePos)) {
					// Cambiar el color del texto como indicación de que fue clicado
					startText.setFillColor(sf::Color::Red);
					std::cout << "Texto clicado!" << std::endl;
                    //currentState = GameState::Playing;
				}
			}
		}
	}
	// UPDATE ///

	// RENDER ///

	renderer.wclear(Constants::BG_COLOR);
    renderer.wdraw(startText);
    renderer.wdraw(quitText);
	renderer.wdisplay();    // Add logic for running the Main Menu
}