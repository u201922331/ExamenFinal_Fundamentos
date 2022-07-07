Alien::Alien() {

}

Alien::~Alien() {

}

void Alien::init(float speed, glm::vec2 position, AlienType type) {
	_speed = speed;
	_position = position;
	this->type = type;
	color.set(255, 255, 255, 255);
}

void Alien::update(const std::vector<std::string>& levelData, std::vector<Human*>& humans, std::vector<Zombie*>& zombies) {

}

void Alien::draw(SpriteBacth& spriteBatch) {
	static int textureAlien;
	switch (type) {
	case AlienType::ROJO:
		textureAlien = ResourceManager::getTexture("assets/textures/rojo.png").id;
		break;
	case AlienType::AMARILLO:
		textureAlien = ResourceManager::getTexture("assets/textures/amarillo.png").id;
		break;
	case AlienType::VERDE:
		textureAlien = ResourceManager::getTexture("assets/textures/verde.png").id;
		break;
	}

	const glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);
	glm::vec4 destRect(_position, AGENT_WIDTH, AGENT_WIDTH);
	spriteBatch.draw(destRect, uvRect, textureAlien, 0.0f, color);
}
