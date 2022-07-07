#pragma once

#ifndef _SPRITE_BATCH_
#define _SPRITE_BATCH_

#include <vector>
#include <algorithm>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Vertex.h"

enum class GlyphSortType {
	NONE,
	FRONT_TO_BACK,
	BACK_TO_FRONT,
	TEXTURE
};

class Glyph {

public:
	Glyph() {}
	Glyph(const glm::vec4& destRect, const glm::vec4& uvRect, GLuint _texture, float _depth, const Color& color) {
		texture = _texture;
		depth = _depth;

		topLeft.color = color;
		topLeft.setPosition(destRect.x, destRect.y + destRect.w);
		topLeft.setUV(uvRect.x, uvRect.y + uvRect.w);

		bottomLeft.color = color;
		bottomLeft.setPosition(destRect.x, destRect.y);
		bottomLeft.setUV(uvRect.x, uvRect.y);

		bottomRight.color = color;
		bottomRight.setPosition(destRect.x + destRect.z, destRect.y);
		bottomRight.setUV(uvRect.x + uvRect.z, uvRect.y);

		topRight.color = color;
		topRight.setPosition(destRect.x + destRect.z, destRect.y + destRect.w);
		topRight.setUV(uvRect.x + uvRect.z, uvRect.y + uvRect.w);
	}

	GLuint texture;
	float depth;
	Vertex topLeft;
	Vertex bottomLeft;
	Vertex topRight;
	Vertex bottomRight;
};

class RenderBatch {

public:
	RenderBatch(GLuint offset, GLuint numVertixex, GLuint texture);

	GLuint _offset;
	GLuint _numVertixes;
	GLuint _texture;
};

class SpriteBacth {
	GLuint _vbo;
	GLuint _vao;

	std::vector<Glyph> _glyphs;
	std::vector<Glyph*> _glyphsPointers;
	std::vector<RenderBatch> _renderBacthes;
	
	void createVertexArray();
	void sortGlyph();
	
	GlyphSortType _sortType;
	
	void createRenderBatches();

public:
	SpriteBacth();
	~SpriteBacth();

	void init();
	
	void begin(GlyphSortType sortType = GlyphSortType::TEXTURE);
	void end();
	
	void draw(const glm::vec4& destRect, const glm::vec4& uvRect, GLuint texture, float depth, const Color& color);
	void renderBatch();

	static bool compareFrontToBack(Glyph* a, Glyph* b);
	static bool compareBackToFront(Glyph* a, Glyph* b);
	static bool compareTexture(Glyph* a, Glyph* b);

};

#include "SpriteBacth.inl"
#endif

