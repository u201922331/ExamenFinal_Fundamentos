void Player::init(float speed, glm::vec2 position, InputManager* inputManager, Camera2D* camera) {
	_speed = speed;
	_position = position;
	_camera = camera;
	_inputManager = inputManager;
	color.set(255, 255, 255, 255);

	score = 0;
}

void Player::update(const std::vector<std::string>& levelData, std::vector<Human*>& humans, std::vector<Zombie*>& zombies) {
	if (_inputManager->isKeyDown(SDLK_w) && _position.y < 200)
		_position.y += _speed;
	if (_inputManager->isKeyDown(SDLK_s) && _position.y > -200)
		_position.y -= _speed;
	if (_inputManager->isKeyDown(SDLK_a) && _position.x > -300)
		_position.x -= _speed;
	if (_inputManager->isKeyDown(SDLK_d) && _position.x < 300)
		_position.x += _speed;
	collideWithLevel(levelData);
}

Player::Player() :_currentGun(-1) {

}

Player::~Player() {

}

void Player::draw(SpriteBacth& spriteBatch) {
	// Textura base
	static int texturePlayer = ResourceManager::getTexture("assets/textures/player.png").id;

	const glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);
	glm::vec4 destRect(_position, AGENT_WIDTH, AGENT_WIDTH);
	spriteBatch.draw(destRect, uvRect, texturePlayer, 0.0f, color);
}