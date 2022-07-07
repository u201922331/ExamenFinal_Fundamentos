#pragma once

#ifndef _ZOMBIE_
#define _ZOMBIE_

#include "Agent.h"
#include "Human.h"

class Zombie :public Agent {

public:
	Human* getNearestHuman(std::vector<Human*>& humans);

	Zombie();
	~Zombie();

	void init(float speed, glm::vec2 position);

	void update(const std::vector<std::string>& levelData, std::vector<Human*>& humans, std::vector<Zombie*>& zombies);

	void draw(SpriteBacth& spriteBatch) override;
};

#include "Zombie.inl"
#endif
