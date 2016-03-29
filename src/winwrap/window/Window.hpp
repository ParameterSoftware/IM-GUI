#ifndef IM_GUI_WINDOW_HPP
#define IM_GUI_WINDOW_HPP

#include "../monitor/Monitor.hpp"
#include "../util/Key.hpp"
#include "../util/Vector.hpp"
#include "../util/Event.hpp"
#include <GLFW/glfw3.h>

namespace Imgui
{
class Window
{
	GLFWwindow* mp_window;
	EventBus<Window, EventFunc::WindowEvent, WindowEventIndex::SIZE> m_bus;
public:
	static Window null;

	Window(GLFWwindow* window);
	Window(int width, int height, const char* title, Monitor monitor = Monitor::GetPrimary(), Window share = Window::null);
	~Window();
	
	bool ShouldClose();
	void SetShouldClose(int value);
	
	void SetTitle(const char* title);
	
	Vec2I GetPosition();
	void SetPosition(Vec2I position);
	
	Vec2I GetSize();
	void SetSize(Vec2I size);
	
	Vec2I GetBufferSize();
	
	void SetSizeLimits(Vec2I min, Vec2I max);
	
	void Iconify();
	void Restore();
	void Maximize();
	
	void Show();
	void Hide();
	
	void Focus();
	
	Monitor GetMonitor();
	
	int GetAttributes(int attribVal);
	
	int GetInputMode(int modeType);
	void SetInputMode(int modeType, int value);
	
	int GetKey(Key key);
	
	int GetMouseButton(int buttonIndex);
	
	Vec2D GetCursorPosition();
	void SetCursorPosition(Vec2D position);
	
	void SetClipboardString(const char* string);
	const char* GetClipboardString();
	
	void MakeCurrent();
	static Window GetCurrentContext();
	
	void SwapBuffers();
	
	template<class Event>
	void SetEventFunction(EventIndex::Index index) { m_bus.RegsterEvent<Event>(this, index); }
	
	GLFWwindow* GetPointer();
	
	operator GLFWwindow*() { return this->GetPointer(); }
};
}// namespace Imgui

#endif