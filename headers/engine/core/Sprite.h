#pragma once

#ifndef _SPRITE_
#define _SPRITE_

#include <cstddef>
#include <GL\glew.h>
#include <string>
#include "GLTexture.h"
#include "Vertex.h"
#include "../loader/ResourceManager.h"

using namespace std;

class Sprite {
	float _x;
	float _y;
	int _width;
	int _height;
	float vertexData;
	GLuint _vobID;
	GLTexture _texture;

public:
	Sprite();
	~Sprite();
	void init(float x, float y, int width, int height, string texturePath);
	void draw();

};

#include "Sprite.inl"
#endif
