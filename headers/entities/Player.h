#pragma once

#ifndef _PLAYER_
#define _PLAYER_

#include <vector>
#include <SDL\SDL.h>
#include "Human.h"
#include "../engine/input/InputManager.h"
#include "../engine/core/Camera2D.h"

class Player : public Human {
	InputManager* _inputManager;
	int _currentGun;
	Camera2D* _camera;

public:
	int score;

	Player();
	~Player();
	void init(float speed, glm::vec2 position, InputManager* inputManager, Camera2D* camera);
	void update(const std::vector<std::string>& levelData, std::vector<Human*>& humans, std::vector<Zombie*>& zombies);

	virtual void draw(SpriteBacth& spriteBatch) override;
};

#include "Player.inl"
#endif
