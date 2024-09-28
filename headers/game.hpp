#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "constants.hpp"

class Game{
public:
	Game();
	void run();

private:
	GEngine::Renderer renderer;
	// variables
	GEngine::Variables variables;

	// engine shape
	GEngine::Shape2D shape;

	// engine text
	GEngine::Text text;

	// engine collision
	GEngine::Collision collision;

	//snake
	std::vector<sf::RectangleShape> snakeBody;

	//aple
	sf::RectangleShape apple;
	
	// direction variable
	sf::Vector2f direction;

	// grid
	std::vector<sf::VertexArray> grid;
	
	void processEvents();

	void update();

	void render();

	void handleInput(sf::Keyboard::Key key);

	void moveSnake();

	void checkCollisionWithApple();

	void checkCollisionWithSelf();

	void resetGame();

	void run();
};