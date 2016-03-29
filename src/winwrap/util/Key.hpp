#pragma once
#ifndef HID_kREpnDPLIaSh7R4
#define HID_kREpnDPLIaSh7R4
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
}// namespace Imgui
#endif