#ifndef IM_GUI_UTIL_VECTOR_HPP
#define IM_GUI_UTIL_VECTOR_HPP

#include "Vector.hpp"

namespace Imgui
{
template<int size, typename T>
class Vector
{
public:
	Vector() {  }
	Vector(T defVal) { }
	Vector(T array[]): m_typeArray(array) {}
	
	T* operator[](int index) { return this->m_typeArray[index] }
	T* at(int index) { return *(this)[index]; }
	T* operator[](char index) { /*TODO: fix char indexes*/ }
	T* at(char index) { return *(this)[index]; }
};
}

#endif