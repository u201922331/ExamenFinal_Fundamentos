#pragma once

#ifndef _MAINGAME_
#define _MAINGAME_

#include <vector>
#include <iostream>
#include <random>
#include <ctime>
#include <SDL\SDL.h>
#include <GL\glew.h>
#include "engine/core/GLS_Program.h"
#include "engine/screen/Window.h"
#include "engine/core/Camera2D.h"
#include "engine/core/SpriteBacth.h"
#include "engine/input/InputManager.h"
#include "platformer/Level.h"
#include "entities/Player.h"
#include "entities/Human.h"
#include "entities/Zombie.h"
#include "engine/loader/ImageLoader.h"
#include "engine/loader/ResourceManager.h"
#include "engine/PapuEngine.h"

using namespace std;

enum class GameState {
	PLAY, EXIT
};


class MainGame {
	int _witdh;
	int _height;
	float _time;
	Window _window;
	
	GLS_Program _program;
	Camera2D _camera;
	SpriteBacth _spriteBacth;
	InputManager _inputManager;
	vector<Level*> _levels;
	vector<Human*>  _humans;
	vector<Zombie*> _zombies;
	Player* _player;
	int _currenLevel;

	void init();
	void procesInput();

	void initLevel();
	void updateAgents();

public:
	GameState _gameState;

	MainGame();
	~MainGame();
	
	void initShaders();
	void run();
	void draw();
	void update();

};

#include "MainGame.inl"
#endif
