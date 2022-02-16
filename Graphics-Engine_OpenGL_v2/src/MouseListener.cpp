#include "MouseListener.h"

MouseListener MouseListener::instance = MouseListener();

MouseListener::MouseListener() {

}

void MouseListener::MousePositionCallBack(long window, double xPos, double yPos) {
	instance.lastX = instance.xPos;
	instance.lastY = instance.yPos;
	instance.xPos = xPos;
	instance.yPos = yPos;
	instance.isDragging = 
		instance.mouseButtonPressed[0] ||
		instance.mouseButtonPressed[1] ||
		instance.mouseButtonPressed[2];
}

void MouseListener::MouseButtonCallback(long window, int button, int action, int mods) {
	if (action == GLFW_PRESS) {
		if (button < 3) {
			instance.mouseButtonPressed[button] = true;
		}
	}
	else if (action == GLFW_RELEASE) {
		instance.mouseButtonPressed[button] = false;
		instance.isDragging = false;
	}
}

void MouseListener::MouseScrollCallback(long window, double xOffset, double yOffset) {
	instance.scrollX = xOffset;
	instance.scrollY = yOffset;
}

void MouseListener::EndFrame() {
	instance.scrollX = 0;
	instance.scrollY = 0;
	instance.lastX = instance.xPos;
	instance.lastY = instance.yPos;
}