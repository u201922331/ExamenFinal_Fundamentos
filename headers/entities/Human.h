#pragma once

#ifndef _HUMAN_
#define _HUMAN_

#include <random>
#include <ctime>
#include <glm\gtx\rotate_vector.hpp>
#include "Agent.h"

class Human : public Agent {

protected:
	glm::vec2 _direction;

public:
	Human();
	~Human();
	void init(float speed, glm::vec2 position);

	void update(const std::vector<std::string>& levelData, std::vector<Human*>& humans, std::vector<Zombie*>& zombies);

	virtual void draw(SpriteBacth& spriteBatch) override;
};

#include "Human.inl"
#endif
