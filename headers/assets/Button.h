#pragma once

#ifndef _BUTTON_
#define _BUTTON_

#include <iostream>
#include <string>
#include <glm/glm.hpp>
#include "../engine/core/SpriteBacth.h"
#include "../engine/core/GLTexture.h"
#include "../engine/loader/ResourceManager.h"

class Button {
	std::string path;
	int _textureID;
	glm::vec4 position;

public:
	Button(std::string _path);
	~Button();
	void draw(SpriteBacth& spriteBatch, glm::vec4 position);
	bool click(glm::vec2 position);

};

#include "Button.inl"
#endif
