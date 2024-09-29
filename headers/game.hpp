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
#include <vector>
#include <iostream>



class Game{
public:
	Game();

private:
	//snake
	std::vector<sf::RectangleShape> snakeBody;
	
	//apple
	sf::RectangleShape apple;
	
	// direction variable
	sf::Vector2f direction;

	int text_w_offset = 85;
	bool activeMusic = false;
	// grid
	std::vector<sf::VertexArray> grid;

	void update();

	void render();

	void handlePlaying();

	GameState currentState;

	//void handleInput(sf::Keyboard::Key key);

	void checkCollisionWithApple(std::vector<sf::Vector2f>& previousPositions);

	void checkCollisionWithSelf(std::vector<sf::Vector2f>& previousPositions);

	void crossBorder(std::vector<sf::Vector2f>& previousPositions);

	void resetGame();
};