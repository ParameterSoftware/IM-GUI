#ifndef IM_GUI_EVENT_HPP
#define IM_GUI_EVENT_HPP

#include "Vector.hpp"

namespace Imgui
{
namespace WindowEventIndex
{
	enum Index
	{
		Start = 0,
		SwapBuffers,
		End,
		MakeCurrent,
		Reposition,
		Retitle,
		Resize,
		Maximize,
		Iconify,
		Restore,
		Show,
		Hide,
		Focus,
		ModeChange,
		SIZE
	}
}

namespace EventFunc
{
	struct WindowEvent
	{
		Window m_window;
		WindowEvent(Window window): m_window(window) {}
		virtual void operator()() = 0;
	};
	
	struct RetitleEvent: public WindowEvent
	{
		static EventIndex::Index index = EventIndex::Retitle;
		char* m_title;
		RetitleEvent(Window window): WindowEvent(window), m_title(NULL) {}
	};
	
	struct Vec2IEvent: public WindowEvent
	{
		Vec2I m_vec;
		Vec2IEvent(Window window): WindowEvent(window), m_vec(Vec2I(0,0)) {}
	};
	
	struct ModeChangeEvent: public WindowEvent
	{
		static EventIndex::Index index = EventIndex::ModeChange;
		int* m_mode;
		ModeChange(Window window): WindowEvent(window), m_mode(NULL) {}
	}
}// namespace EventFunc

template<class ForClass, class EventType, int EventCount>
class EventBus
{
	EventType m_events[EventCount];
public:
	EventBus() {}
	
	template<class RegType>
	void RegisterEvent(ForClass forClass, int index) { m_events[index] = RegType(forClass); }
	
	template<class ReturnType>
	ReturnType GetEvent(int index) { return dynamic_cast<ReturnType>(m_events[index]); }
	template<class ReturnType>
	ReturnType operator[](int index) { return GetEvent<ReturnType>(index); }
};

}// namespace Imgui

#endif