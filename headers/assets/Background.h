#pragma once

#ifndef _BACKGROUND_
#define _BACKGROUND_

#include <string>
#include <glm/glm.hpp>
#include "../engine/core/SpriteBacth.h"
#include "../engine/core/GLTexture.h"
#include "../engine/loader/ResourceManager.h"

class Background {
	std::string path;
	int _textureID;
	int width, height;

public:
	Background(std::string _path);
	~Background();
	void draw(SpriteBacth& spriteBatch);

	void setResolution(int width, int height);
};


#include "Background.inl"
#endif
