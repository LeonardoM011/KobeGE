#include "Player.h"

Player::Player() {

}

Player::~Player() {

}

void Player::init(glm::vec2 pos, GLdouble width, GLdouble height, int windowWidth, int windowHeight, GLubyte r, GLubyte g, GLubyte b, GLubyte a) {
	_object.init(pos, width, height, windowWidth, windowHeight, r, g, b, a);
}

void Player::draw() {
	handleEvents();
	_object.draw();
}

void Player::handleEvents() {
	if (InputManager::keydown[GLFW_KEY_W]) {
		_object.move(glm::vec3(0.0f, 0.0003f, 0.0f));
		// Collision detection
		float upperCorner = _object.getPos().y + _object.getHeight() * 0.5;
		if (upperCorner >= 1.0f) {
			_object.move(glm::vec3(0.0f, -(upperCorner - 1.0f), 0.0f));
		}
	}
	if (InputManager::keydown[GLFW_KEY_S]) {
		_object.move(glm::vec3(0.0f, -0.0003f, 0.0f));
		// Collision detection
		float lowerCorner = _object.getPos().y + _object.getHeight() * -0.5;
		if (lowerCorner <= -1.0f) {
			_object.move(glm::vec3(0.0f, -(lowerCorner + 1.0f), 0.0f));
		}
	}
}
