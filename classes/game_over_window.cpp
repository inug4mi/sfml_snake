//
// Created by user on 1/10/2024.
//
#include "game_over_window.hpp"

GameOverWindow::GameOverWindow(GEngine::Renderer &_renderer, GameState &_currentState):
      renderer(_renderer),
      variables(),
      shape(),
      text(),
      collision(),
      db("snakedb1.txt"),
      soundManager(),
      currentState(_currentState){
    if (text.good() == -1) {
        std::cerr << "Error loading font" << std::endl;
        // Aquí podrías manejar el error
    }

    retryText = text.write("TRY AGAIN", 35, sf::Color::White);    // Initialization or setup logic, if needed
    retryText.setPosition(Constants::SCREEN_WIDTH/2 - retryText.getGlobalBounds().width/2,90);

    quitText = text.write("QUIT GAME", 35, sf::Color::White);    // Initialization or setup logic, if needed
    quitText.setPosition(Constants::SCREEN_WIDTH/2 - quitText.getGlobalBounds().width/2,270);
}

void GameOverWindow::run() {
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
                if (text.isTextClicked(retryText, mousePos)) {
                    // Cambiar el color del texto como indicación de que fue clicado
                    retryText.setFillColor(sf::Color::Red);
                    currentState = GameState::Playing;
                }
                else if (text.isTextClicked(quitText, mousePos)) {
                    quitText.setFillColor(sf::Color::Red);
                    renderer.window.close();
                }
            }
        }
    }
    // UPDATE ///

    // RENDER ///

    renderer.wclear(Constants::BG_COLOR);
    renderer.wdraw(retryText);
    renderer.wdraw(quitText);
    renderer.wdisplay();    // Add logic for running the Main Menu
}