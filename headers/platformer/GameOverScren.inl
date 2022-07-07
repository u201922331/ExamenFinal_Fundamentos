void GameOverScreen::checkInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_MOUSEBUTTONDOWN:
			inputManager.pressKey(event.button.button);
			break;
		case SDL_MOUSEBUTTONUP:
			inputManager.releaseKey(event.button.button);
			break;
		case SDL_MOUSEMOTION:
			inputManager.setMouseCoords(event.motion.x, event.motion.y);
			break;
		}

		if (inputManager.isKeyPressed(SDL_BUTTON_LEFT)) {
			glm::vec2 mouseCoords = camera.convertScreenToWorl(inputManager.getMouseCoords());
			if (btnExit->click(mouseCoords))
				_currentState = ScreenState::EXIT_APPLICATION;
		}
	}
}

GameOverScreen::GameOverScreen(Window* window) : window(window) {

}

GameOverScreen::~GameOverScreen() {

}

void GameOverScreen::build() {
	background = new Background("assets/textures/fondos/gam-over.png");
	background->setResolution(800, 800);
	btnExit = new Button("assets/textures/btn_salir.png");
}

void GameOverScreen::destroy() {
	btnExit = nullptr;
	background = nullptr;
}

void GameOverScreen::onExit() {

}

void GameOverScreen::onEntry() {
	program.compileShaders("assets/shaders/main.vert", "assets/shaders/main.frag");
	program.addAtribute("vertexPosition");
	program.addAtribute("vertexColor");
	program.addAtribute("vertexUV");
	program.linkShader();
	spriteBatch.init();
	camera.init(window->getScreenWidth(), window->getScreenHeight());
	spriteFont = new SpriteFont("assets/fonts/alagard.ttf", 80);
	window->setTitle("GAME OVER");
}

void GameOverScreen::draw() {
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	program.use();
	
	glActiveTexture(GL_TEXTURE0);

	GLuint pLocation = program.getUniformLocation("P");

	glm::mat4 cameraMatrix = camera.getCameraMatrix();
	glUniformMatrix4fv(pLocation, 1, GL_FALSE, &(cameraMatrix[0][0]));

	GLuint imageLocation = program.getUniformLocation("myImage");
	glUniform1i(imageLocation, 0);

	spriteBatch.begin();

	background->draw(spriteBatch);
	btnExit->draw(spriteBatch, glm::vec4(-160, -150, 330, 100));
	char buffer[256];
	sprintf_s(buffer, "FIN DEL JUEGO");
	Color color;
	color.r = 255;
	color.g = 0;
	color.b = 0;
	color.a = 255;
	spriteFont->draw(spriteBatch, buffer, glm::vec2(-240, 150), glm::vec2(1), 0.0f, color);
	spriteBatch.end();
	spriteBatch.renderBatch();

	glBindTexture(GL_TEXTURE_2D, 0);
	program.unuse();
	window->swapBuffer();
}

void GameOverScreen::update() {
	draw();
	camera.update();
	inputManager.update();
	checkInput();
}

int GameOverScreen::getNextScreen() const {
	return SCREEN_INDEX_NO_INDEX;
}

int GameOverScreen::getPreviousScreen() const {
	return SCREEN_INDEX_NO_INDEX;
}