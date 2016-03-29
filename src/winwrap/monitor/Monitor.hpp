#ifndef IM_GUI_MONITOR_HPP
#define IM_GUI_MONITOR_HPP

#include "../util/Vector.hpp"
#include <GLFW/glfw3.hpp>
#include <vector>

namespace Imgui
{

class Monitor
{
	GLFWmonitor* mp_monitor;
public:
	Monitor(GLFWmonitor* monitor = NULL);
	Monitor(int monitorIndex);
	~Monitor();
	
	static Monitor GetPrimary();
	static std::vector<Monitor> GetMonitors();
	
	Vec2I GetPosition();
	
	Vec2I GetPhysicalSize();
	
	std::vector<GLFWvidmode> GetVideoModes();
	
	GLFWvidmode GetCurrentVideoMode();
	
	void SetGamma(float gamma);
	
	const char* GetName();
	
	GLFWmonitor* GetPointer();
	
	operator GLFWmonitor*() { return this->GetPointer(); }
};

}

#endif