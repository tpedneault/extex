#include "window.hpp"
#include "GLFW/glfw3.h"

Window::Window(UINT32 width, UINT32 height, CSTR title)
    : m_Width(width), m_Height(height), m_Title(title) {}

Window::~Window() {}

STATUS Window::Initialize() {
  if (!glfwInit()) {
    return FAILURE;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

  m_Window = glfwCreateWindow(1280, 720, "Hello", nullptr, nullptr);
  glfwMakeContextCurrent(m_Window);

  if (glewInit() != GLEW_OK) {
    return FAILURE;
  }

  return FAILURE;
}

STATUS Window::Update() {
   glfwPollEvents();
   glfwSwapBuffers(m_Window);
   return SUCCESS;
}

STATUS Window::Destroy() {
   glfwDestroyWindow(m_Window);
   glfwTerminate();
   return SUCCESS;
}

bool Window::IsWindowOpen() {
  return !glfwWindowShouldClose(m_Window);
}
