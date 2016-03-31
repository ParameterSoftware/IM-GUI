#pragma once
#ifndef HID_8fvKFlUfbHdkj0T
#define HID_8fvKFlUfbHdkj0T

#include "Vector.hpp"

namespace Imgui
{
template<class ForClass, class BaseEvent, int EventCount>
class EventBus
{
	BaseEvent m_events[EventCount];
public:
	EventBus() {}
	
	template<class RegType = BaseEvent>
	void RegisterEvent(ForClass forClass, int index) { m_events[index] = RegType(forClass); }
	template<class RegType = BaseEvent>
	void RegisterEvent(ForClass forClass, int index, RegType event) { event.m_instance = forClass; m_events[index] = event; }
	
	template<class ReturnType>
	ReturnType GetEvent(int index) { return dynamic_cast<ReturnType>(m_events[index]); }
	template<class ReturnType>
	ReturnType operator[](int index) { return GetEvent<ReturnType>(index); }
};
}// namespace Imgui

#endif