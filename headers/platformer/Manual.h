#pragma once

#ifndef _MANUAL_
#define _MANUAL_

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

class ManualScreen : public IGameScreen {
	GLS_Program _program;
	Window* _window = nullptr;
	SpriteBacth _spriteBatch;
	Background* background;
	Button* btnContinue;
	InputManager inputManager;
	Camera2D _camera;
	
	void checkInput();
	
	SpriteFont* spriteFont;

protected:
	int _screenIndex = 1;

public:
	ManualScreen(Window* window);
	~ManualScreen();

	virtual void build() override;
	virtual void destroy() override;

	virtual void onExit() override;
	virtual void onEntry() override;

	virtual void draw()override;
	virtual void update()override;

	virtual int getNextScreen() const override;
	virtual int getPreviousScreen() const override;
};

#include "Manual.inl"
#endif
