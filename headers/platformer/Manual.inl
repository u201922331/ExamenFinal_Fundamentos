void ManualScreen::checkInput() {
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
			//presione click;
			glm::vec2 mouseCoords = _camera.convertScreenToWorl(inputManager.getMouseCoords());
			if (btnContinue->click(mouseCoords))
				_currentState = ScreenState::CHANGE_NEXT;
		}
	}
}

ManualScreen::ManualScreen(Window* window) : _window(window) {

}

ManualScreen::~ManualScreen() {

}

void ManualScreen::build() {
	background = new Background("assets/textures/fondos/Menu.png");
	background->setResolution(800, 800);
	btnContinue = new Button("assets/textures/btn_play.png");
}

void ManualScreen::destroy() {
	btnContinue = nullptr;
	background = nullptr;
}

void ManualScreen::onExit() {

}

void ManualScreen::onEntry() {
	_program.compileShaders("assets/shaders/main.vert", "assets/shaders/main.frag");
	_program.addAtribute("vertexPosition");
	_program.addAtribute("vertexColor");
	_program.addAtribute("vertexUV");
	_program.linkShader();
	_spriteBatch.init();
	_camera.init(_window->getScreenWidth(), _window->getScreenHeight());
	spriteFont = new SpriteFont("assets/fonts/alagard.ttf", 40);
}

void ManualScreen::draw() {
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

	background->draw(_spriteBatch);
	btnContinue->draw(_spriteBatch, glm::vec4(-50, -180, 360, 100));
	char buffer[256];

	Color color;

	color.r = 252; color.g = 255; color.b = 255; color.a = 255;
	sprintf_s(buffer, "REGLAS");
	spriteFont->draw(_spriteBatch, buffer, glm::vec2(-275, 175), glm::vec2(1), 0.0f, color);
	
	color.r = 252; color.g = 219; color.b = 0; color.a = 255;
	sprintf_s(buffer, "Al chocar con el amarillo:");
	spriteFont->draw(_spriteBatch, buffer, glm::vec2(-350, 120), glm::vec2(0.7), 0.0f, color);
	color.r = 252; color.g = 255; color.b = 255; color.a = 255;
	sprintf_s(buffer, "Q: +10 puntos");
	spriteFont->draw(_spriteBatch, buffer, glm::vec2(-350, 90), glm::vec2(0.7), 0.0f, color);
	sprintf_s(buffer, "W: -15");
	spriteFont->draw(_spriteBatch, buffer, glm::vec2(-350, 60), glm::vec2(0.7), 0.0f, color);
	sprintf_s(buffer, "E: /2");
	spriteFont->draw(_spriteBatch, buffer, glm::vec2(-350, 30), glm::vec2(0.7), 0.0f, color);

	color.r = 252; color.g = 0; color.b = 0; color.a = 255;
	sprintf_s(buffer, "Al chocar con el rojo:");
	spriteFont->draw(_spriteBatch, buffer, glm::vec2(-350, 0), glm::vec2(0.7), 0.0f, color);
	color.r = 252; color.g = 255; color.b = 255; color.a = 255;
	sprintf_s(buffer, "Q: -10");
	spriteFont->draw(_spriteBatch, buffer, glm::vec2(-350, -30), glm::vec2(0.7), 0.0f, color);
	sprintf_s(buffer, "W: +20");
	spriteFont->draw(_spriteBatch, buffer, glm::vec2(-350, -60), glm::vec2(0.7), 0.0f, color);
	sprintf_s(buffer, "E: -5");
	spriteFont->draw(_spriteBatch, buffer, glm::vec2(-350, -90), glm::vec2(0.7), 0.0f, color);

	color.r = 0; color.g = 255; color.b = 0; color.a = 255;
	sprintf_s(buffer, "Al chocar con el verde:");
	spriteFont->draw(_spriteBatch, buffer, glm::vec2(-350, -120), glm::vec2(0.7), 0.0f, color);
	color.r = 252; color.g = 255; color.b = 255; color.a = 255;
	sprintf_s(buffer, "Q: -20");
	spriteFont->draw(_spriteBatch, buffer, glm::vec2(-350, -150), glm::vec2(0.7), 0.0f, color);
	sprintf_s(buffer, "W: -15");
	spriteFont->draw(_spriteBatch, buffer, glm::vec2(-350, -180), glm::vec2(0.7), 0.0f, color);
	sprintf_s(buffer, "E: x2");
	spriteFont->draw(_spriteBatch, buffer, glm::vec2(-350, -210), glm::vec2(0.7), 0.0f, color);

	_spriteBatch.end();
	_spriteBatch.renderBatch();

	glBindTexture(GL_TEXTURE_2D, 0);
	_program.unuse();
	_window->swapBuffer();
}

void ManualScreen::update() {
	draw();
	_camera.update();
	inputManager.update();
	checkInput();
}

int ManualScreen::getNextScreen() const {
	return SCREEN_INDEX_GAMEPLAY;
}

int ManualScreen::getPreviousScreen() const {
	return SCREEN_INDEX_GAMEPLAY;
}