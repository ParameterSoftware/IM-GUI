#ifndef IM_GUI_KEY_HPP
#define IM_GUI_KEY_HPP

#include "Key.hpp"
#include <GLFW/glfw3.h>

namespace Imgui
{
class Key
{
	Key(int value, int scancode): m_keyValue(value), m_scancode(scancode < 0 ? value : scancode), m_nameCache(glfwGetKeyName(value, scancode)) {}
	
	const char* GetName() 
	{ 
		if(this->m_nameCache == NULL) this->m_nameCache = glfwGetKeyName(m_keyValue, m_scancode); 
		return m_nameCache; 
	}
};
}

#endif