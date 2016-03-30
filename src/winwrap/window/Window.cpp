#include "Window.hpp"
namespace Imgui
{
using namespace Imgui::Win::Event::WindowEvent;
using namespace Imgui::Win::Event::RetitleEvent;
using namespace Imgui::Win::Event::Vec2IEvent;
using namespace Imgui::Win::Event::ModeChangeEvent;

class Window {
	null = Window(NULL);
	
	Window(GLFWwindow* window): mp_window(window) {}
	Window(int width, int height, const char* title, Monitor monitor, Window share): 
		mp_window(glfwCreateWindow(width, height, title, monitor, share) 
	{
		WindowEvent event = m_bus<WindowEvent>[Win::EIndex::Start];
		if(!event()) ~Window();
	}
	
	~Window() 
	{
		WindowEvent event = m_bus<WindowEvent>[Win::EIndex::End];
		event();
		glfwDestroyWindow(this);
	}
	
	bool ShouldClose() { return glfwWindowShouldClose(this); }
	void SetShouldClose(int val) { glfwSetWindowShouldClose(this, val); }
	
	void SetTitle(const char* title) 
	{ 
		RetitleEvent event = m_bus<RetitleEvent>[Win::EIndex::Retitle];
		event.m_title = title;
		if(!event()) return;
		glfwSetTitle(this, title); 
	}
	
	Vec2I GetPosition()
	{
		int pos[2];
		glfwGetWindowPos(this, pos[0], pos[1]);
		return Vec2I(pos);
	}
	
	void SetPosition(Vec2I position) 
	{ 
		Vec2IEvent event = m_bus<Vec2IEvent>[Win::EIndex::Reposition];
		event.m_vec = position;
		if(!event()) return;
		glfwSetWindowPosition(this, *position.X(), *position.Y());
	}
	
	Vec2I GetSize()
	{
		int size[2];
		glfwGetWindowSize(this, size[0], size[1]);
		return Vec2I(size);
	}
	
	void SetSize(Vec2I size) 
	{
		Vec2IEvent event = m_bus<Vec2IEvent>[Win::EIndex::Reposition];
		event.m_vec = size;
		if(!event()) return;
		glfwSetWindowSize(this, *size.X(), *size.Y()); 
	}
	
	Vec2I GetBufferSize()
	{
		int size[2];
		glfwGetFramebufferSize(this, size[0], size[1]);
		return Vec2I(size);
	}
	
	void SetSizeLimits(Vec2I min, Vec2I max) { glfwSetWindowSizeLimits(this, *min.X(), *min.Y(), *max.X(), *max.Y()); }
	
	void Iconify() 
	{
		WindowEvent event = m_bus<WindowEvent>[Win::EIndex::Iconify];
		if(!event()) return;
		glfwIconifyWindow(this); 
	}
	
	void Restore() 
	{	
		WindowEvent event = m_bus<WindowEvent>[Win::EIndex::Restore];
		if(!event()) return;
		glfwRestoreWindow(this); 
	}
	
	void Maximize() 
	{
		WindowEvent event = m_bus<WindowEvent>[Win::EIndex::Maximize];
		if(!event()) return;
		glfwMaximizeWindow(this);
	}
	
	void Show() 
	{
		WindowEvent event = m_bus<WindowEvent>[Win::EIndex::Show];
		if(!event()) return;
		glfwShowWindow(this); 
	}
	void Hide() 
	{
		WindowEvent event = m_bus<WindowEvent>[Win::EIndex::Hide];
		if(!event()) return;
		glfwHideWindow(this); 
	}
	
	void Focus() 
	{
		WindowEvent event = m_bus<WindowEvent>[Win::EIndex::Focus];
		if(!event()) return;
		glfwFocusWindow(this); 
	}
	
	Monitor GetMonitor() { return Monitor(glfwGetWindowMonitor(this)); }
	
	int GetAttributes(int attribVal) { return glfwGetWindowAttrib(this, attribVal); }
	
	int GetInputMode(int modeType) { return glfwGetInputMode(this, modeType); }
	void SetInputMode(int modeType, int value) 
	{
		ModeChangeEvent event = m_bus<ModeChangeEvent>[Win::EIndex::ModeChange];
		event.m_values[0] = &mode;
		event.m_values[1] = &val;
		if(!event()) return;
		glfwSetInputMode(this, modeType, value);
	}
	
	int GetKey(Key key) { return glfwGetKey(this, key); }
	
	int GetMouseButton(int buttonIndex) { return glfwGetMouseButton(this, buttonIndex); }
	
	Vec2D GetCursorPosition()
	{
		double pos[2];
		glfwGetCursorPos(this, pos[0], pos[1]);
		return Vec2D(pos);
	}
	
	void SetCursorPosition(Vec2D position) { glfwSetCursorPos(this, *position.X(), *position.Y()); }
	
	void SetClipboardString(const char* string) { glfwSetClipboardString(this, string); }
	const char* GetClipboardString() { return glfwGetClipboardString(this); }
	
	void MakeCurrent() { glfwMakeContextCurrent(this); }
	static Window GetCurrentContext() { return Window(glfwGetCurrentContext()); }
	
	void SwapBuffers() 
	{
		WindowEvent event = m_bus<ModeChangeEvent>[Win::EIndex::SwapBuffers];
		if(!event()) return;
		glfwSwapBuffers(this);
	}
	
	GLFWwindow* GetPointer() { return mp_window; }
};
}// namespace Imgui
