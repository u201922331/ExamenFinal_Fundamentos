#pragma once

#ifndef _AGENT_
#define _AGENT_

#include <algorithm>
#include <string>
#include <glm\glm.hpp>
#include "../engine/core/SpriteBacth.h"
#include "../engine/core/GLTexture.h"
#include "../engine/loader/ResourceManager.h"
#include "../platformer/Level.h"

class Zombie;
class Human;

const float AGENT_WIDTH = 60.0f;
const float AGENT_RADIUS = AGENT_WIDTH / 2.0f;

class Agent {

protected:
	glm::vec2 _position;
	float _speed;
	Color color;
	
	void checkTilePosition(const std::vector<std::string>& levelData, std::vector<glm::vec2>& collideTilePosition, float x, float y);
	void collideWithTile(glm::vec2 tilePos);

public:
	Agent();
	virtual ~Agent();

	glm::vec2 getPosition() const { return _position; };
	
	virtual void update(const std::vector<std::string>& levelData, std::vector<Human*>& humans, std::vector<Zombie*>& zombies) = 0;
	virtual void draw(SpriteBacth& spritebatch) = 0;
	
	bool collideWithLevel(const std::vector<std::string>& levelData);
	bool collideWithAgent(Agent* agent);

};

#include "Agent.inl"
#endif
