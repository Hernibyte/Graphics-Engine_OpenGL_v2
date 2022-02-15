#include "Window.h"

Window Window::window = Window();
int Window::width  = 100;
int Window::height = 100;
const char* Window::tittle = "Window";

Window::Window() {
	Init("Window", 100, 100);
}

Window::~Window() {
	glfwTerminate();
	glfwDestroyWindow(winMain);
}

void Window::Refresh() {
	glfwSwapBuffers(window.winMain);
	glfwPollEvents();
}

void Window::Clear(GLclampf r, GLclampf g, GLclampf b, GLclampf a) {
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::Init(const char* tittle, int width, int height) {
	this->width = width;
	this->height = height;
	this->tittle = tittle;

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	winMain = glfwCreateWindow(this->width, this->height, this->tittle, NULL, NULL);
	if (winMain == NULL) {
		std::cout << "Failed to create Window" << std::endl;
		glfwTerminate();
		exit(-1);
	}

	glfwMakeContextCurrent(winMain);

	glViewport(0, 0, width, height);

	glewInit();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Window::UpdateAttib() {
	glfwSetWindowTitle(winMain, tittle);
	glfwSetWindowSize(winMain, width, height);
	glViewport(0, 0, width, height);
}