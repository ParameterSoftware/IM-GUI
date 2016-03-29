#include "Imgui.hpp"

namespace Imgui
{

void PollEvents() { glfwPollEvents(); }
void WaitEvents() { glfwWaitEvents(); }

void PostEmptyEvent() { glfwPostEmptyEvent(); }

double GetTime() { return glfwGetTime(); }
void SetTime(double time) { return glfwSetTime(); }

}