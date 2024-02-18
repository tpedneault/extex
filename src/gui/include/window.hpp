#ifndef WINDOW_H
#define WINDOW_H

#include "component.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

/**
 * @class Window
 * @brief Manages a GLFW window and its context.
 *
 * Inherits from ComponentBase to integrate with an application's component
 * system. This class encapsulates the creation, initialization, updating, and
 * destruction of a GLFW window. It also handles the initialization of GLEW for
 * OpenGL function loading.
 */
class Window : public ComponentPubSub {
public:
  /**
   * @brief Constructs a Window object with the specified dimensions and title.
   *
   * @param width Width of the window in pixels.
   * @param height Height of the window in pixels.
   * @param title Title of the window.
   */
  Window(UINT32 width, UINT32 height, CSTR title);

  /**
   * @brief Destroys the Window object.
   *
   * Ensures proper cleanup of GLFW resources associated with the window.
   */
  virtual ~Window();

  /**
   * @brief Initializes the GLFW window and the GLEW library.
   *
   * Creates the GLFW window with the specified dimensions and title, sets the
   * current context to this window, and initializes GLEW for OpenGL function
   * loading. Logs errors if GLFW or GLEW initialization fails.
   *
   * @return STATUS indicating the success or failure of the initialization
   * process.
   */
  STATUS Initialize() override;

  /**
   * @brief Polls for window events and swaps the front and back buffers.
   *
   * Should be called in the application's main loop to process input events
   * and update the window's contents.
   *
   * @return STATUS indicating the success of the update process.
   */
  STATUS Update() override;

  /**
   * @brief Destroys the GLFW window and terminates GLFW.
   *
   * Cleans up all resources associated with the GLFW window and properly
   * terminates the GLFW library.
   *
   * @return STATUS indicating the success of the destruction process.
   */
  STATUS Destroy() override;

  /**
   * @brief Checks if the GLFW window should close.
   *
   * @return true if the window is open and false if it should close.
   */
  bool IsWindowOpen();

private:
  GLFWwindow *m_Window; ///< Pointer to the GLFW window object.
  UINT32 m_Width;       ///< Width of the window in pixels.
  UINT32 m_Height;      ///< Height of the window in pixels.
  CSTR m_Title;         ///< Title of the window.
};

#endif /* WINDOW_H */
