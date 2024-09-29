#include "game.hpp"

Game::Game():renderer(Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT, "SFML Snake"),
variables(), shape(), text(), collision(), db("snakedb1.txt"), soundManager(), currentState(GameState::MainMenu), direction(0.0f, 0.0f){
	
	renderer.wsetFramerateLimit(12);

	grid = shape.grid();

	soundManager.loadMusic("assets/music/gtasa.mp3");
	soundManager.loadSound("coin","assets/sounds/pickupCoin.wav");
	soundManager.loadSound("powerUp","assets/sounds/powerUp.wav");
	soundManager.loadSound("hitSelf","assets/sounds/hitSelf.wav");

	// snake head
	snakeHead = shape.square(
		Constants::SNAKE_SIZE * Constants::SNAKE_Xi,
		Constants::SNAKE_SIZE * Constants::SNAKE_Yi,
		Constants::SNAKE_SIZE,
		sf::Color::Green
	);

	// snake head+body vector
	snakeBody.push_back(snakeHead);

	// apple 
	apple = shape.square(
		Constants::APPLE_SIZE * Constants::APPLE_Xi,
		Constants::APPLE_SIZE * Constants::APPLE_Yi,
		Constants::APPLE_SIZE,
		sf::Color::Red
	);

	// manejar direccion de movimiento
	direction = sf::Vector2f(0.0f, 0.0f);

	// texto y fuente
	if (text.good() == -1) {
		std::cerr << "Error loading font" << std::endl;
		// Aquí podrías manejar el error
	}
	scoreText = text.write(std::to_string(variables.score), 300, Constants::TEXT_COLOR);	

	// Reproducir la música de fondo
    soundManager.setMusicVolume(5.0f); // Ajustar el volumen de la música
}

void Game::run(){
	while (renderer.wisOpen()){
		
		switch (currentState) {
			case GameState::MainMenu:
				handleMainMenu();
				break;
			case GameState::Playing:
				handlePlaying();
				break;
		}

	}
}

void Game::handleMainMenu(){
	renderer.wpollEventsMainMenu(variables, currentState);
	renderer.wclear(Constants::BG_COLOR);
}

void Game::handlePlaying(){
	renderer.wpollEventsPlaying(variables, direction);
	update();
	render();
}


void Game::update(){
	if (variables.score > 0 && !activeMusic){ 
		soundManager.playMusic();
		activeMusic = true;
	}
		
	if (variables.score > 9) text_w_offset = 170;
	scoreText.setPosition(Constants::SCREEN_WIDTH/2 - text_w_offset, 10);
	
	snakeHeadPosition = snakeBody[0].getPosition(); 
	std::vector<sf::Vector2f> previousPositions;
	for (auto& part : snakeBody)
		previousPositions.push_back(part.getPosition());
	if (!variables.pause){
		crossBorder(previousPositions);
		// Hacer que cada parte siga a la anterior
		for (size_t i = 1; i < snakeBody.size(); i++) {
			snakeBody[i].setPosition(previousPositions[i - 1]);
		}
		// colision entre cabeza y cualquier otra parte del cuerpo de la serpiente
		checkCollisionWithSelf(previousPositions);
		// Colision entre serpiente y la manzana
		checkCollisionWithApple(previousPositions);
	}
}

void Game::render(){
	// background color
	renderer.wclear(Constants::BG_COLOR);

	// dibujar texto
	renderer.wdraw(scoreText);	

	for (const sf::VertexArray line : grid) renderer.wdraw(line);

	renderer.wdraw(apple);
	// draw snake body
	for (int i = 0; i < snakeBody.size(); i++) {
		renderer.wdraw(snakeBody[i]);
	}

	renderer.wdisplay();
}

void Game::checkCollisionWithApple(std::vector<sf::Vector2f>& previousPositions){
	if (collision.between(snakeBody[0], apple)) {
		sf::Vector2f lastPosition = previousPositions.back();
		snakeBody.push_back(shape.square(
			lastPosition.x,
			lastPosition.y,
			Constants::SNAKE_SIZE,
			sf::Color(-109*snakeBody.size(),233-snakeBody.size()*2,109-snakeBody.size())
		));
		soundManager.playSound("coin");
		// score added
		variables.score++;
		if (variables.score%10 == 0) soundManager.playSound("powerUp");
		// actualizar texto score
		scoreText.setString(std::to_string(variables.score));
		// la manzana cambia de posicion
		// la posicion NO PUEDE estar en una posicion del cuerpo de la serpiente
		bool newApple = false;
		while (!newApple){
			newApple = true;
			int newApplePosX = (int)variables.generateRandomInt(0,(int)((Constants::SCREEN_WIDTH/Constants::SNAKE_SIZE) - 1))*Constants::APPLE_SIZE;
			int newApplePosY = (int)variables.generateRandomInt(0,(int)((Constants::SCREEN_WIDTH/Constants::SNAKE_SIZE) - 1))*Constants::APPLE_SIZE;
			for (size_t i = 0; i < snakeBody.size(); i++) {
				sf::Vector2f posi = snakeBody[i].getPosition();
				//std::cout << "newApplePosX: " << newApplePosX << ", newApplePosY: " << newApplePosY << std::endl;
				//std::cout << "BodyPartX: " << posi.x << ", BodyPartY: " << posi.y << std::endl;
				if (newApplePosX == posi.x && newApplePosY == posi.y){
					newApple = false;
					break;
				}
			}
			if (newApple) {
				sf::Vector2f randomApplePosition(newApplePosX,newApplePosY);
				apple.setPosition(randomApplePosition);
			}
		}
	}
}

void Game::checkCollisionWithSelf(std::vector<sf::Vector2f>& previousPositions){
	for (int i = 1; i < snakeBody.size(); i++){
		if (collision.between(snakeBody[0], snakeBody[i])){
			soundManager.playSound("hitSelf");
			snakeBody[i].setFillColor(sf::Color::Yellow);
			snakeBody[i].setOutlineColor(sf::Color::White);
			soundManager.pauseMusic();
			variables.pause = true;
			variables.gameLost;
			db.addPlayerScore("Inug4mi",variables.score);
			//db.showDatabaseInfo();
			//std::cout << "Final score: " << variables.score << std::endl;
		}
	}	
}

void Game::crossBorder(std::vector<sf::Vector2f>& previousPositions){
	// mover cabeza en direccion
	snakeBody[0].move(direction);
	//std::cout << "xpos head: " <<snakeHeadPosition.x << std::endl;
	// si la cabeza sobrepasa un muro, aparece del otro lado
	if (snakeHeadPosition.x < 0) {
		snakeBody[0].setPosition(Constants::SCREEN_WIDTH - Constants::SNAKE_SIZE, snakeHeadPosition.y);
	} else if (snakeHeadPosition.x >= Constants::SCREEN_WIDTH) {
		snakeBody[0].setPosition(0, snakeHeadPosition.y);
	}

	// Si la cabeza sobrepasa un muro en el eje Y, aparece del otro lado
	if (snakeHeadPosition.y < 0) {
		snakeBody[0].setPosition(snakeHeadPosition.x, Constants::SCREEN_HEIGHT - Constants::SNAKE_SIZE);
	} else if (snakeHeadPosition.y >= Constants::SCREEN_HEIGHT) {
		snakeBody[0].setPosition(snakeHeadPosition.x, 0);
	}
}