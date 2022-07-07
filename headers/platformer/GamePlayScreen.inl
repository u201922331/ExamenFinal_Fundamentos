GamePlayScreen::GamePlayScreen(Window* window) : _window(window) {

}

GamePlayScreen::~GamePlayScreen() {

}


void GamePlayScreen::build() {
	_levels.push_back(new Level("assets/levels/level1.txt"));
	spriteFont = new SpriteFont("assets/fonts/alagard.ttf", 30);

	_player = new Player();
	_currenLevel = 0;
	_player->init(1.0f, _levels[_currenLevel]->getPlayerPosition(), &_inputManager, &_camera);
	_humans.push_back(_player);
	_spriteBatch.init();

	srand(time(NULL));
	std::mt19937 randomEngine(time(nullptr));
	std::uniform_int_distribution<int>randPosX(
		1, _levels[_currenLevel]->getWidth() - 2);
	std::uniform_int_distribution<int>randPosY(
		1, _levels[_currenLevel]->getHeight() - 2);

	const std::vector<glm::vec2>& zombiePosition = _levels[_currenLevel]->getZombiesPosition();

	background = new Background("assets/textures/fondos/game.png");
	background->setResolution(700, 500);
}

void GamePlayScreen::destroy() {

}

void GamePlayScreen::onExit() {

}

void GamePlayScreen::onEntry() {
	_program.compileShaders("assets/shaders/main.vert", "assets/shaders/main.frag");
	_program.addAtribute("vertexPosition");
	_program.addAtribute("vertexColor");
	_program.addAtribute("vertexUV");
	_program.linkShader();

	_camera.init(_window->getScreenWidth(), _window->getScreenHeight());
}

void GamePlayScreen::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	_program.use();

	glActiveTexture(GL_TEXTURE0);

	GLuint pLocation = _program.getUniformLocation("P");

	glm::mat4 cameraMatrix = _camera.getCameraMatrix();
	glUniformMatrix4fv(pLocation, 1, GL_FALSE, &(cameraMatrix[0][0]));

	GLuint imageLocation = _program.getUniformLocation("myImage");
	glUniform1i(imageLocation, 0);

	_spriteBatch.begin();

	// Fondo
	background->draw(_spriteBatch);

	// Aliens
	for (size_t i = 0; i < aliens.size(); i++)
		aliens[i]->draw(_spriteBatch);
	// Jugdor
	_player->draw(_spriteBatch);

	// Texto
	char buffer[256];
	Color color;
	color.b = 0;
	color.a = 255;
	if (_player->score > 0)
		color.r = 0;
	else
		color.r = 255;
	if (_player->score > 0)
		color.g = 255;
	else if (_player->score < 0)
		color.g = 0;
	else
		color.g = 190;

	sprintf_s(buffer, ("Puntaje: " + std::to_string(_player->score)).c_str());
	spriteFont->draw(_spriteBatch, buffer, glm::vec2(-375, 250), glm::vec2(1), 0.0f, color);

	color.r = 255;
	color.g = 190;

	sprintf_s(buffer, ("Tiempo: " + std::to_string(gameTimer / 500)).c_str());
	spriteFont->draw(_spriteBatch, buffer, glm::vec2(200, 250), glm::vec2(1), 0.0f, color);

	_spriteBatch.end();
	_spriteBatch.renderBatch();

	glBindTexture(GL_TEXTURE_2D, 0);
	_program.unuse();
	_window->swapBuffer();

	if (_inputManager.isKeyPressed(SDL_BUTTON_LEFT))
		std::cout << "Para el otro anio sera :D\n";
}
void GamePlayScreen::update() {
	checkInput();
	draw();
	_camera.update();
	updateAgents();
	_inputManager.update();
	//_camera.setPosition(_player->getPosition());
}


void GamePlayScreen::updateAgents() {
	_player->update(_levels[_currenLevel]->getLevelData(), _humans, _zombies);

	glm::vec2 randomPos = glm::vec2(rand() % 200, rand() % 150);
	int randomAlienType = rand() % 3;

	if (gameTimer % 1000 == 0) {
		// std::cout << "Game Timer: " << gameTimer << '\n';
		AlienType type;
		switch (randomAlienType) {
		case 0:
			type = AlienType::ROJO;
			break;
		case 1:
			type = AlienType::VERDE;
			break;
		case 2:
			type = AlienType::AMARILLO;
			break;
		}
		aliens.push_back(new Alien);
		aliens.back()->init(0.1f, randomPos, type);
	}

	// SI EL PLAYER CHOCA CON...
	// 1. AMARILLO y Q: +10
	// 2. ROJO y W: +20
	// 3. VERDE y E: x2

	// COMBINACIÓN ERRADA...?
	// 1. Q:
	//     a. ROJO:  -10
	//     b. VERDE: -20
	// 2. W y (VERDE o AMARILLO): -15
	// 3. E:
	//     a. ROJO:     -5
	//     b. AMARILLO: /2
	for (size_t i = 0; i < aliens.size(); i++) {
		aliens[i]->update(_levels[_currenLevel]->getLevelData(), _humans, _zombies);

		if (aliens[i]->collideWithAgent(_player)) {
			switch (aliens[i]->getType()) {
			case AlienType::AMARILLO:
				if (_inputManager.isKeyDown(SDLK_q)) {
					_player->score += 10;
					break;
				}
				if (_inputManager.isKeyDown(SDLK_w)) {
					_player->score -= 15;
					break;
				}
				if (_inputManager.isKeyDown(SDLK_e)) {
					_player->score /= 2;
					break;
				}
			case AlienType::ROJO:
				if (_inputManager.isKeyDown(SDLK_w)) {
					_player->score += 20;
					break;
				}
				if (_inputManager.isKeyDown(SDLK_q)) {
					_player->score -= 10;
					break;
				}
				if (_inputManager.isKeyDown(SDLK_e)) {
					_player->score /= 2;
					break;
				}
			case AlienType::VERDE:
				if (_inputManager.isKeyDown(SDLK_e)) {
					_player->score *= 2;
					break;
				}
				if (_inputManager.isKeyDown(SDLK_q)) {
					_player->score -= 20;
					break;
				}
				if (_inputManager.isKeyDown(SDLK_w)) {
					_player->score -= 15;
					break;
				}
			}

			// Eliminar alien correspondiente
			delete aliens[i];
			aliens[i] = aliens.back();
			aliens.pop_back();
		}
	}


	// Cambiar pantalla a game over
	if (_player->score < 0) {
		_currentState = ScreenState::CHANGE_NEXT;
	}

	gameTimer++;
}

void GamePlayScreen::checkInput() {
	SDL_Event event;
	const float CAMERA_SPEED = 20.0f;
	const float SCALE_SPEED = 0.1f;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			//_gameState = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			_inputManager.setMouseCoords(event.motion.x, event.motion.y);
			break;
		case  SDL_KEYUP:
			_inputManager.releaseKey(event.key.keysym.sym);
			break;
		case  SDL_KEYDOWN:
			_inputManager.pressKey(event.key.keysym.sym);
			break;
		case SDL_MOUSEBUTTONDOWN:
			_inputManager.pressKey(event.button.button);
			break;
		case SDL_MOUSEBUTTONUP:
			_inputManager.releaseKey(event.button.button);
			break;
		}
		/*
		if (_inputManager.isKeyDown(SDLK_q))
			_camera.setScale(_camera.getScale() + SCALE_SPEED);
		if (_inputManager.isKeyDown(SDLK_e))
			_camera.setScale(_camera.getScale() - SCALE_SPEED);
		*/
	}
}

int GamePlayScreen::getNextScreen() const {
	return SCREEN_INDEX_GAMEOVER;
};

int GamePlayScreen::getPreviousScreen() const {
	return SCREEN_INDEX_GAMEOVER;
}
