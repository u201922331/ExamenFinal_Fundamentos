void InputManager::pressKey(unsigned int keyCode) {
	_keyMap[keyCode] = true;
}

void InputManager::releaseKey(unsigned int keyCode) {
	_keyMap[keyCode] = false;
}

bool InputManager::isKeyDown(unsigned int keyCode) {
	auto it = _keyMap.find(keyCode);
	if (it != _keyMap.end())
		return it->second;
	return false;
}

void InputManager::update() {
	for (auto& it : _keyMap)
		_previusKeyMap[it.first] = it.second;
}


bool InputManager::isKeyPressed(unsigned int keyCode) {
	return isKeyDown(keyCode) && !wasKeyDown(keyCode);
}

bool InputManager::wasKeyDown(unsigned int keyCode) {
	auto it = _previusKeyMap.find(keyCode);
	if (it != _previusKeyMap.end())
		return it->second;
	return false;
}

void InputManager::setMouseCoords(float x, float y) {
	_mouseCoords.x = x;
	_mouseCoords.y = y;
}

InputManager::InputManager():_mouseCoords(0.0f,0.0f) {

}


InputManager::~InputManager() {

}
