#pragma once

#ifndef _ALIEN_
#define _ALIEN_

#include "Agent.h"

enum class AlienType {
	ROJO,
	VERDE,
	AMARILLO
};

class Alien : public Agent {
	// glm::vec2 direction;
	int timer = 0;
	AlienType type;

	bool hasBeenHit = false;

public:
	Alien();
	~Alien();

	void init(float speed, glm::vec2 position, AlienType type);

	void update(const std::vector<std::string>& levelData, std::vector<Human*>& humans, std::vector<Zombie*>& zombies);
	virtual void draw(SpriteBacth& spriteBatch) override;

	void setHit(bool wasHit) {
		hasBeenHit = wasHit;
	}
	bool getHit() const {
		return hasBeenHit;
	}

	AlienType getType() const {
		return type;
	}
};

#include "Alien.inl"
#endif
