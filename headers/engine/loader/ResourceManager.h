#pragma once

#ifndef _RESOURCE_MANAGER_
#define _RESOURCE_MANAGER_

#include "../core/GLTexture.h"
#include "../core/TextureCache.h"

class ResourceManager {
	static TextureCache _textureCache;

public:
	static GLTexture getTexture(std::string texturePath);

};

#include "ResourceManager.inl"
#endif
