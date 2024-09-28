#include "game.cpp"
#include "constants.hpp"

Game::Game(): direction(0.0f, 0.0f){
	GEngine::Renderer renderer(Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT, "SFML Snake");
	renderer.wsetFramerateLimit(12);

	std::vector<sf::VertexArray> grid = shape.grid();

	// variables
	int text_w_offset = 85; // offset en texto del puntaje

	// snake head
	sf::RectangleShape snakeHead = shape.square(
		Constants::SNAKE_SIZE * Constants::SNAKE_Xi,
		Constants::SNAKE_SIZE * Constants::SNAKE_Yi,
		Constants::SNAKE_SIZE,
		sf::Color::Green
	);

	// snake head+body vector
	snakeBody.push_back(snakeHead);

	// apple 
	sf::RectangleShape apple = shape.square(
		Constants::APPLE_SIZE * Constants::APPLE_Xi,
		Constants::APPLE_SIZE * Constants::APPLE_Yi,
		Constants::APPLE_SIZE,
		sf::Color::Red
	);

	// manejar direccion de movimiento
	sf::Vector2f direction(0.0f, 0.0f);

	// texto y fuente
	if (text.good() == -1) return -1;

	sf::Text scoreText = text.write(std::to_string(variables.score), 300, Constants::TEXT_COLOR);		
}

void Game::run(){
	while (renderer.wisOpen()){
		processEvents();
		update();
		render();
	}
}