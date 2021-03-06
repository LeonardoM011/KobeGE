#include "WindowManager.h"
//#define STB_IMAGE_IMPLEMENTATION
#include "externcode/imageloader/stb_image.h"

WindowManager::WindowManager() :
	window(nullptr),
	_width(0),
	_height(0)
{
	
}

WindowManager::~WindowManager() {
	
}

int WindowManager::create(int width, int height, const char *title) {
	_width = width;
	_height = height;
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	glfwWindowHint(GLFW_REFRESH_RATE, 60);
	glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);
	#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
	#endif

	window = glfwCreateWindow(width, height, title, NULL, NULL);

	int bpp;
	GLFWimage icon;
	icon.pixels = stbi_load("res/images/icon_default.png", &icon.height, &icon.width, &bpp, 4);
	glfwSetWindowIcon(window, 1, &icon);
	stbi_image_free(icon.pixels);

	GLFWwindowPos::glfwSetWindowCenter(window);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	return 0;
}

bool WindowManager::closeRequested() {
	return !glfwWindowShouldClose(window);
}

void WindowManager::swap() {
	glfwSwapBuffers(window);
}

void WindowManager::pollEvents() {
	glfwPollEvents();
}
