#pragma once

#ifndef _IMAGE_LOADER_
#define _IMAGE_LOADER_

#include <string>
#include "../core/GLTexture.h"
#include "../utils/picoPNG.h"
#include "../utils/Error.h"
#include "IOManager.h"

class ImageLoader {

public:
	static GLTexture loadPNG(std::string filePath);

};

#include "ImageLoader.inl"
#endif
