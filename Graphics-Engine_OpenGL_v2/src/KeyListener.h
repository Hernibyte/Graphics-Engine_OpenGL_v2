#ifndef KEYLISTENER_H
#define KEYLISTENER_H

#include "MouseListener.h"

class KeyListener {
public:
	static void KeyCallback(long window, int key, int scancode, int action, int mods);
	static KeyListener Get() { return instance; }
	static bool IsKeyPressed(int keyCode);

private:
	KeyListener();

	static KeyListener instance;
	bool keyPressed[350];
};

#endif // !KEYLISTENER_H
