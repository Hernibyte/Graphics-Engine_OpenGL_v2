#include "Program.h"

Program::Program() {
	Window::Get().Width(800);
	Window::Get().Height(800);
	Window::Get().Tittle("Window");
}

Program::Program(int width, int height, const char* tittle) {
	Window::Get().Width(width);
	Window::Get().Height(height);
	Window::Get().Tittle(tittle);
}

void Program::Run() {
	Init();

	Core_Awake();
	Awake();

	Core_Start();
	Start();

	while (!Window::IsWindowShouldClose()) {
		Time::Start();
		
		Window::Clear();

		Core_LateUpdate();
		LateUpdate();

		Core_Update();
		Update();

		Core_FixedUpdate();
		FixedUpdate();

		Window::Refresh();

		Time::Tick();
	}

	Core_Sleep();
	Sleep();
}

void Program::Core_Awake() {

}

void Program::Core_Start() {

}

void Program::Core_LateUpdate() {

}

void Program::Core_Update() {

}

void Program::Core_FixedUpdate() {

}

void Program::Core_Sleep() {

}