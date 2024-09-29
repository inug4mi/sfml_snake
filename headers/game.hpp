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
#include <vector>
#include <iostream>
//helo world ?
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

	GEngine::SoundManager soundManager;

	// engine collision
	GEngine::Collision collision;

	GEngine::Database db;

	sf::RectangleShape snakeHead;

	sf::Text scoreText;

	sf::Vector2f snakeHeadPosition;

	//snake
	std::vector<sf::RectangleShape> snakeBody;
	
	//aple
	sf::RectangleShape apple;
	
	// direction variable
	sf::Vector2f direction;

	int text_w_offset = 85;
	bool activeMusic = false;
	// grid
	std::vector<sf::VertexArray> grid;

	void processEvents();

	void update();

	void render();

	//void handleInput(sf::Keyboard::Key key);

	void checkCollisionWithApple(std::vector<sf::Vector2f>& previousPositions);

	void checkCollisionWithSelf(std::vector<sf::Vector2f>& previousPositions);

	void crossBorder(std::vector<sf::Vector2f>& previousPositions);

	void resetGame();
};