#ifndef IM_GUI_MONITOR_HPP
#define IM_GUI_MONITOR_HPP

#include "Monitor.hpp"

namespace Imgui
{
class Monitor
{
public:
	Monitor(GLFWmonitor* monitor): mp_monitor(monitor != NULL ? monitor : glfwGetPrimaryMonitor()) {}
	Monitor(int monitorIndex): mp_monitor(GetMonitors()[monitorIndex]) {}
	~Monitor() {}
	
	static Monitor GetPrimary() { return Monitor(glfwGetPrimaryMonitor()); }
	static std::vector<Monitor> GetMonitors()
	{
		int* size;
		glfwMonitor** arr = glfwGetMonitors(size);
		std::vector<Monitor> result(size);
		for(int i = 0; i < *size; i++)
		{
			result.push_back(Monitor(arr[i]));
		}
		return result;
	}
	
	Vec2I GetPosition()
	{
		int pos[2];
		glfwGetMonitorPos(this, pos[0], pos[1]);
		return Vec2I(pos);
	}
	
	Vec2I GetPhysicalSize()
	{
		int size[2];
		glfwGetMonitorPhysicalSize(this, size[0], size[1]);
		return Vec2I(size);
	}
	
	std::vector<GLFWvidmode> GetVideoModes()
	{
		int* size;
		GLFWvidmode* arr = glfwGetVideoModes(this, size);
		return std::vector<GLFWvidmode>(size, arr);
	}
	
	GLFWvidmode GetCurrentVideoMode() { return glfwGetVideoMode(this); }
	
	void SetGamma(float gamma) { glfwSetGamma(this, gamma); }
	
	const char* GetName() { return glfwGetMonitorName(this); }
	
	GLFWmonitor* GetPointer() { return this->mp_monitor; }
};
}

#endif