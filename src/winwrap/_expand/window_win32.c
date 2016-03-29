#include "window_platform.h"
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus
	
const char* _eglfwPlatformGetWindowTitle(GLFWwindow* window)
{
	char* title = NULL;
	HWND wnd = glfwGetWin32Window(window);
	GetWindowTextW(wnd, title, GetWindowTextLengthW(wnd);
	return title;
}

#ifdef __cplusplus
}
#endif //__cplusplus