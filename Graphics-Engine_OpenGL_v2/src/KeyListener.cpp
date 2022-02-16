#include "KeyListener.h"

KeyListener KeyListener::instance = KeyListener();

KeyListener::KeyListener() {

}

void KeyListener::KeyCallback(long window, int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS) {
		instance.keyPressed[key] = true;
	}
	else if (action == GLFW_RELEASE) {
		instance.keyPressed[key] = false;
	}
}

bool KeyListener::IsKeyPressed(int keyCode) {
	if (keyCode < 350)
		return instance.keyPressed[keyCode];
	return false;
}