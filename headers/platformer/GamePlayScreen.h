#pragma once

#ifndef _GAMEPLAY_SCREEN_
#define _GAMEPLAY_SCREEN_

#include <iostream>
#include <random>
#include <ctime>
#include <SDL\SDL.h>
#include "../SpriteFont.h"
#include "../engine/screen/IGameScreen.h"
#include "../engine/core/Camera2D.h"
#include "../engine/core/GLS_Program.h"
#include "../engine/screen/Window.h"
#include "../engine/core/GLTexture.h"
#include "../engine/core/SpriteBacth.h"
#include "Level.h"
#include "../entities/Zombie.h"
#include "../entities/Human.h"

#include "../entities/Alien.h"
#include "../entities/Player.h"

#include "../assets/Background.h"
#include "../engine/core/Game.h"
#include "../engine/loader/ImageLoader.h"
#include "../engine/loader/ResourceManager.h"
#include "../engine/PapuEngine.h"
#include "../ScreenIndices.h"

class GamePlayScreen : public IGameScreen {
	GLS_Program _program;
	Camera2D _camera;
	Window* _window = nullptr;
	SpriteBacth _spriteBatch;
	GLTexture _texture;
	InputManager _inputManager;
	vector<Level*> _levels;
	vector<Human*>  _humans;
	vector<Zombie*> _zombies;
	Background* background;
	SpriteFont* spriteFont;


	Player* _player;
	std::vector<Alien*> aliens;
	int gameTimer = 0;

	int _currenLevel;

	void updateAgents();

protected:
	int _screenIndex = 2;

public:
	GamePlayScreen(Window* window);
	~GamePlayScreen();

	virtual void build() override;
	virtual void destroy() override;
	virtual void onExit() override;
	virtual void onEntry() override;
	virtual void draw()override;
	virtual void update()override;
	virtual int getNextScreen() const override;
	virtual int getPreviousScreen() const override;

	void checkInput();

};

#include "GamePlayScreen.inl"
#endif
