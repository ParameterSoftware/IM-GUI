#ifndef IM_GUI_KEY_HPP
#define IM_GUI_KEY_HPP

namespace Imgui
{

class Key
{
	const char* m_nameCache;
	
	int m_keyValue;
	int m_scancode;
public:
	Key(int value, scancode = -1);
	
	const char* GetName();
	
	bool HasName() { this->m_nameCache != NULL; }
	
	operator char*() { return this->GetName(); }
};

}

#endif