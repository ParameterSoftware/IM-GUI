#ifndef IM_GUI_IMGUI_HPP
#define IM_GUI_IMGUI_HPP

#include <GLFW/glfw.h>

namespace Imgui
{

void PollEvents();
void WaitEvents();

void PostEmptyEvent();

double GetTime();
void SetTime(double time);

}

#endif