#pragma once

#ifndef _LEVEL_
#define _LEVEL_

#include <fstream>
#include <string>
#include <vector>
#include "../engine/core/SpriteBacth.h"
#include "../engine/loader/ResourceManager.h"
#include "../engine/utils/Error.h"

using namespace std;

const int TILE_WIDTH = 64;
class Level {
	vector<string> _levelData;
	int _numHumans;

	void parseLevel();

public:
	int getNumHumans() const {
		return _numHumans;
	}

	glm::vec2 _playerPosition;
	std::vector<glm::vec2> _zombiesPosition;
	glm::vec2 getPlayerPosition() const {
		return _playerPosition;
	};

	const std::vector<std::string>& getLevelData() {
		return _levelData;
	}
	int getWidth() const {
		return _levelData[0].size();
	}
	int getHeight() const {
		return _levelData[0].size();
	}
	std::vector<glm::vec2> getZombiesPosition()const {
		return _zombiesPosition;
	};

	Level(const std::string& fileName);
	~Level();
	
	void draw();
	SpriteBacth _spriteBatch;

};

#include "Level.inl"
#endif
