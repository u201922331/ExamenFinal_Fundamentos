#pragma once

#ifndef _WINDOW_
#define _WINDOW_

#include <string>
#include <SDL\SDL.h>
#include <GL\glew.h>
#include "../utils/Error.h"

using namespace std;
//1
//10
//100
enum WindowFlags {
	INVISBLE = 0x1, FULLSCREEN = 0x2, BORDERLESS = 0x4
};

class Window {
	SDL_Window* _window;
	int _screenWidth, _screenHeight;

public:
	Window();
	~Window();
	void swapBuffer();
	int getScreenWidth() { return _screenWidth; };
	int getScreenHeight() { return _screenHeight; };
	int create(string windowName, int screenWidth, int screenHeight, unsigned int currentFlags);

	void setTitle(std::string title);
};

#include "Window.inl"
#endif
