#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include "Time.h"
#include "KeyListener.h"

class Window {
public:
	~Window();

	static Window Get() { return window; }

	static GLFWwindow* GetWindow() { return window.winMain; }

	static void Width(int width) { window.width = width; window.UpdateAttib(); }
	static int Width() { return width; }

	static void Height(int height) {  window.height = height; window.UpdateAttib(); }
	static int Height() { return height; }

	static void Tittle(const char* tittle) { window.tittle = tittle; window.UpdateAttib(); }
	static const char* Tittle() { return tittle; }

	static void SetWindowShouldClose(bool state) { glfwSetWindowShouldClose(window.winMain, state); }
	static bool IsWindowShouldClose() { return glfwWindowShouldClose(window.winMain); }

	static void Refresh();

	static void Clear(GLclampf r = 1, GLclampf g = 1, GLclampf b = 1, GLclampf a = 1);
private:
	Window();
	void Init(const char* tittle, int width, int height);
	void UpdateAttib();

	static Window window;
	GLFWwindow* winMain;
	static int width, height;
	static const char* tittle;
};

#endif // !WINDOW_H
