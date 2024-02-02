#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "component.hpp"

class Window : public ComponentBase {
public:
  Window(UINT32 width, UINT32 height, CSTR title);
  virtual ~Window();

  STATUS Initialize() override;
  STATUS Update() override;
  STATUS Destroy() override;

  bool IsWindowOpen();

private:
  GLFWwindow *m_Window;
  UINT32 m_Width, m_Height;
  CSTR m_Title;
};

#endif /* WINDOW_H */
