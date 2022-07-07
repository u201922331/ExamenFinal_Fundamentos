#pragma once

#ifndef _GAMEOVER_SCREEN_
#define _GAMEOVER_SCREEN_

#include "../engine/screen/IGameScreen.h"
#include "../engine/core/GLS_Program.h"
#include "../engine/screen/Window.h"
#include "../engine/core/SpriteBacth.h"
#include "../assets/Background.h"
#include "../SpriteFont.h"
#include "../engine/core/Camera2D.h"
#include "../assets/Button.h"
#include "../engine/input/InputManager.h"

class GameOverScreen : public IGameScreen {
	GLS_Program program;
	Window* window = nullptr;
	SpriteBacth spriteBatch;
	Background* background;
	Button* btnExit;
	InputManager inputManager;
	Camera2D camera;
	SpriteFont* spriteFont;

	void checkInput();

protected:
	int _screenIndex = 3;

public:
	GameOverScreen(Window* window);
	~GameOverScreen();

	virtual void build() override;
	virtual void destroy() override;

	virtual void onExit() override;
	virtual void onEntry() override;

	virtual void draw() override;
	virtual void update() override;
	
	virtual int getNextScreen() const override;
	virtual int getPreviousScreen() const override;

};

#include "GameOverScren.inl"
#endif
