Window::Window() {
}

void Window::swapBuffer() {
	SDL_GL_SwapWindow(_window);
}

int Window::create(string windowName, int screenWidth, int screenHeight, unsigned int currentFlags) {
	Uint32 flags = SDL_WINDOW_OPENGL;

	_screenWidth = screenWidth;
	_screenHeight = screenHeight;

	if (currentFlags & INVISBLE)
		flags |= SDL_WINDOW_HIDDEN;
	if (currentFlags & FULLSCREEN)
		flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
	if (currentFlags & BORDERLESS)
		flags |= SDL_WINDOW_BORDERLESS;

	_window = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, flags);

	SDL_GLContext glContext = SDL_GL_CreateContext(_window);

	GLenum error = glewInit();
	
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	SDL_GL_SetSwapInterval(0);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	return 0;
}


Window::~Window() {
}

void Window::setTitle(std::string title) {
	SDL_SetWindowTitle(this->_window, title.c_str());
}