Button::Button(std::string _path):path(_path) {
	_textureID = ResourceManager::getTexture(path).id;
}

Button::~Button() {

}

void Button::draw(SpriteBacth& spriteBatch, glm::vec4 position) {
	Color color;
	color.r = 255;
	color.b = 255;
	color.g = 255;
	color.a = 255;
	const glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);
	
	// glm::vec4 destRect(0,0,100,100);
	this->position = position;
	spriteBatch.draw(this->position, uvRect, _textureID, 0.0f, color);
}

bool Button::click(glm::vec2 position) {
	if (position.x >= this->position.x && position.x <= this->position.x + this->position.z) {
		std::cout << "Las x son iguales" << std::endl;
		if (position.y >= this->position.y && position.y <= this->position.y + this->position.w) {
			std::cout << "Las y son iguales" << std::endl;
			return true;
		}
	}
	return false;
}
