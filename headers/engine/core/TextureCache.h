#pragma once

#ifndef _TEXTURE_CACHE_
#define _TEXTURE_CACHE_

#include <map>
#include <string>
#include <iostream>
#include "GLTexture.h"
#include "../loader/ImageLoader.h"

using namespace std;

class TextureCache {
	std::map<std::string, GLTexture> _textureMap;

public:
	TextureCache();
	~TextureCache();
	GLTexture getTexture(std::string texturePath);

};

#include "TextureCache.inl"
#endif
