Game::Game() {
	_screenList = std::make_unique<ScreenList>(this);
}

bool Game::init() {
	Papu::init();
	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
	initSystems();
	onInit();
	addScreens();
	_currentScreen = _screenList->getCurrent();
	_currentScreen->onEntry();
	_currentScreen->setRunning();
	return true;
}

void Game::draw() {
	glViewport(0, 0, _window.getScreenWidth(), _window.getScreenHeight());
	if (_currentScreen && _currentScreen->getState() == ScreenState::RUNNING)
		_currentScreen->draw();
}
bool Game::initSystems() {
	_window.create("Final", 800, 600, 0);
	return true;
}

void Game::onSDLEvent(SDL_Event& event) {

}

void Game::run() {
	if (!init()) return;
	_isRunning = true;
	while (_isRunning) {
		_inputManager.update();
		update();
		draw();
		_window.swapBuffer();
	}
}

void Game::exit() {
	_currentScreen->onExit();
	if (_screenList) {
		_screenList->destroy();
		_screenList.reset();
	}
	_isRunning = false;
}

void Game::update() {
	if (_currentScreen) {
		switch (_currentScreen->getState()) {
			case ScreenState::RUNNING:
				_currentScreen->update();
				break;
			case ScreenState::CHANGE_NEXT:
				_currentScreen->onExit();
				_currentScreen = _screenList->moveNext();
				if (_currentScreen) {
					_currentScreen->setRunning();
					_currentScreen->onEntry();
				}
				break;
			case ScreenState::CHANGE_PREVIOUS:
				_currentScreen->onExit();
				_currentScreen = _screenList->movePrevious();
				if (_currentScreen) {
					_currentScreen->setRunning();
					_currentScreen->onEntry();
				}
				break;
			case ScreenState::EXIT_APPLICATION:
				exit();
				break;
			default:
				break;
		}
	}
}


Game::~Game() {

}
