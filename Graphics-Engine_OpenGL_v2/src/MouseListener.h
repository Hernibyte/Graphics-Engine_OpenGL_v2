#ifndef MOUSELISTENER_H
#define MOUSELISTENER_H

#include "GLEW/include/GL/glew.h"
#include "GLFW/include/glfw3.h"

class MouseListener {
public:
	MouseListener();
	static MouseListener Get() { return instance; }
	static void MousePositionCallBack(long window, double xPos, double yPos);
	static void MouseButtonCallback(long window, int button, int action, int mods);
	static void MouseScrollCallback(long window, double xOffset, double yOffset);
	static void EndFrame();
	static float GetX() { return (float)instance.xPos; }
	static float GetY() { return (float)instance.yPos; }
	static float GetDX() { return (float)instance.lastX - instance.xPos; }
	static float GetDY() { return (float)instance.lastY - instance.yPos; }
	static float GetScrollX() { return (float)instance.scrollX; }
	static float GetScrollY() { return (float)instance.scrollY; }
	static bool IsDragging() { return instance.isDragging; }
	static bool MouseButtonDown(int button) { 
		if (button < 3)
			return instance.mouseButtonPressed[button];
		return false;
	}
private:
	static MouseListener instance;
	double xPos, yPos, lastX, lastY;
	double scrollX, scrollY;
	bool mouseButtonPressed[3];
	bool isDragging;
};

#endif // !MOUSELISTENER_H
