TextureCache::TextureCache() {

}

GLTexture TextureCache::getTexture(std::string texturePath) {
	auto mit = _textureMap.find(texturePath);
	if (mit == _textureMap.end()) {
		GLTexture texture = ImageLoader::loadPNG(texturePath);
		_textureMap[texturePath] = texture;
		return texture;
	}
	return mit->second;
}


TextureCache::~TextureCache() {

}
