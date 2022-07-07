#pragma once

#ifndef _SCREEN_LIST_
#define _SCREEN_LIST_

#include <vector>
#include "IGameScreen.h"

class Game;
class IGameScreen;

class ScreenList {

public:
	ScreenList(Game* game);
	~ScreenList();
	IGameScreen* moveNext();
	IGameScreen* movePrevious();
	void setScreen(int nextScreen);
	void addScreen(IGameScreen* newScreen);
	void destroy();
	IGameScreen* getCurrent();

protected:
	std::vector<IGameScreen*> _screens;
	Game* _game;
	int _currentIndex = -1;

};

#include "ScreenList.inl"
#endif
