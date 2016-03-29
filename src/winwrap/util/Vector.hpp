#ifndef IM_GUI_UTIL_VECTOR_HPP
#define IM_GUI_UTIL_VECTOR_HPP

namespace Imgui
{

template<int size, typename T>
class Vector
{
	static int charIndex = {'x','y','z','w','v','u','t','s','r','q','p','o','n','m','l','k','j','i','h','g','f','e','d','c','b','a'};
	
	T m_typeArray[size];
public:
	typedef T type

	Vector();
	Vector(T defVal);
	Vector(T array[]);
	
	T* operator[](int index);
	T* at(int index);
	T* operator[](char index);
	T* at(char index);
	
	T* X() { return this->at('x'); }
	T* Y() { return this->at('y'); }
	T* Z() { return this->at('z'); }
	
	int size() { return size; }
};

typedef Vector<1, int> VecI;
typedef Vector<1, float> VecF;
typedef Vector<1, double> VecD;
typedef Vector<2, int> Vec2I;
typedef Vector<2, float> Vec2F;
typedef Vector<2, double> Vec2D;
typedef Vector<3, int> Vec3I;
typedef Vector<3, float> Vec3F;
typedef Vector<3, double> Vec3D;

}

#endif