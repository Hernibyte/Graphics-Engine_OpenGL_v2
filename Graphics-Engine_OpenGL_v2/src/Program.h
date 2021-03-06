#ifndef PROGRAM_H
#define PROGRAM_H

#include "Window.h"

class Program {
public:
	Program();
	Program(int width, int height, const char* tittle);

	void Run();
protected:
	virtual void Init() {}
	virtual void Awake() {}
	virtual void Start() {}
	virtual void LateUpdate() {}
	virtual void Update() {}
	virtual void FixedUpdate() {}
	virtual void Sleep() {}
private:
	void Core_Awake();
	void Core_Start();
	void Core_LateUpdate();
	void Core_Update();
	void Core_FixedUpdate();
	void Core_Sleep();
};

#endif // !PROGRAM_H
