#pragma once
#ifndef HID_n3UBZ7BO5VRyt1Y
#define HID_n3UBZ7BO5VRyt1Y
namespace Imgui
{
namespace Win
{
namespace EIndex
{
	enum Index
	{
		/// Window Start Event
		/// \note Destroys window on cancel
		Start = 0,
		/// Window SwapBuffers Event
		/// \note Prevents SwapBuffer call on cancel
		SwapBuffers,
		/// Window End Event
		/// \note Not Cancelable
		End,
		/// Make Context Current Event
		/// \note Prevents making window context current on cancel
		MakeCurrent,
		/// Reposition Event
		/// \note Prevents reposition on cancel
		Reposition,
		/// Retitle Event
		/// \note Prevents retitle on cancel
		Retitle,
		/// Resize Event
		/// \note Prevents resize on cancel
		Resize,
		/// Maximize Event
		/// \note Prevents maximizing window on cancel
		Maximize,
		/// Iconify Event
		/// \note Prevents iconifying window on cancel
		Iconify,
		/// Restore Event
		/// \note Prevents restoring the window on cancel
		Restore,
		/// Show Event
		/// \note Prevents showing of window on cancel
		Show,
		/// Hide Event
		/// \note Prevents hiding of window on cancel
		Hide,
		/// Focus Event
		/// \note Prevents focusing window on cancel
		Focus,
		/// Input Mode Change Event
		/// \note Prevents mode change on cancel
		ModeChange,
		/// The required size of the event array
		SIZE
	}
}// namespace EIndex

namespace Event
{
	/// Standard Window Event
	struct WindowEvent
	{
		Window m_instance;
		WindowEvent(Window window): m_instance(window) {}
		virtual bool operator()() { return true; }
	};
	
	/// Retitle Window Event
	struct RetitleEvent: public WindowEvent
	{
		static EventIndex::Index index = EventIndex::Retitle;
		char* m_title;
		RetitleEvent(Window window): WindowEvent(window), m_title(NULL) {}
	};
	
	/// 2D Integer Vector Window Event
	struct Vec2IEvent: public WindowEvent
	{
		Vec2I m_vec;
		Vec2IEvent(Window window): WindowEvent(window), m_vec(Vec2I(0,0)) {}
	};
	
	/// Changing Mode Window Event
	struct ModeChangeEvent: public WindowEvent
	{
		static EventIndex::Index index = EventIndex::ModeChange;
		int m_values[2];
		ModeChange(Window window): WindowEvent(window), m_mode(NULL) {}
	}
}// namespace Event
}// namespace Win
}// namespace Imgui

#endif