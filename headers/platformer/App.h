#pragma once

#ifndef _APP_
#define _APP_

#include <algorithm>
#include "../engine/core/Game.h"
#include "GamePlayScreen.h"
#include "MenuScreen.h"
#include "Manual.h"
#include "GameOverScren.h"
#include "../engine/screen/ScreenList.h"

class App : public Game {
	std::unique_ptr<GamePlayScreen> _gamePlayScreen = nullptr;
	std::unique_ptr<MenuScreen> _menuScreen = nullptr;
	std::unique_ptr<ManualScreen> _manualScreen = nullptr;
	std::unique_ptr<GameOverScreen> _gameOverScreen = nullptr;

public:
	App();
	~App();

	virtual void onInit() override;
	virtual void addScreens() override;
	virtual void onExit() override;

};

#include "App.inl"
#endif
