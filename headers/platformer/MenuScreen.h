#pragma once

#ifndef _MENU_SCREEN_
#define _MENU_SCREEN_

#include <iostream>
#include "../engine/screen/IGameScreen.h"
#include "../engine/core/GLS_Program.h"
#include "../engine/screen/Window.h"
#include "../engine/core/SpriteBacth.h"
#include "../assets/Background.h"
#include "../SpriteFont.h"
#include "../engine/core/Camera2D.h"
#include "../assets/Button.h"
#include "../engine/input/InputManager.h"
#include "../ScreenIndices.h"


class MenuScreen : public IGameScreen {
	GLS_Program _program;
	Window* _window = nullptr;
	SpriteBacth _spriteBatch;
	Background* background;
	Button* button;
	InputManager inputManager;
	Camera2D _camera;
	void checkInput();
	SpriteFont* spriteFont;

protected:
	int _screenIndex = 0;

public:
	MenuScreen(Window* window);
	~MenuScreen();

	virtual void build() override;
	virtual void destroy() override;
	
	virtual void onExit() override;
	virtual void onEntry() override;
	
	virtual void draw()override;
	virtual void update()override;
	
	virtual int getNextScreen() const override;
	virtual int getPreviousScreen() const override;

};

#include "MenuScreen.inl"
#endif
