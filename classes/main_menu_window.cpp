#include "main_menu_window.hpp"

MainMenuWindow::MainMenuWindow(
    Renderer& renderer,
    Variables& variables,
    Shape2D& shape,
    Text& text,
    Collision& collision,
    Database& db,
    SoundManager& soundManager,
    CurrentState& currentState
) : renderer(renderer),
    variables(variables),
    shape(shape),
    text(text),
    collision(collision),
    db(db),
    soundManager(soundManager),
    currentState(currentState) {
    // Initialization or setup logic, if needed
}

void MainMenuWindow::run() {
    // Add logic for running the Main Menu
}