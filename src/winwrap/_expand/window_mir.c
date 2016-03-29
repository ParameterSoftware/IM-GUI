#include "window_platform.h"
#include <string.h>
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

const char* _eglfwPlatformGetWindowTitle(GLFWwindow* window)
{
	char* title;
	return strcpy(title, glfwGetMirWindow(window)->surface_name);
}