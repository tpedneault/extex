#ifndef RENDERER_H
#define RENDERER_H

#include "component.hpp"
#include "shader.hpp"
#include "vao.hpp"

/**
 * @class Renderer
 * @brief Manages the rendering pipeline.
 *
 * Inherits from ComponentBase to integrate with an application's component
 * system. This class encapsulates the setup and usage of shaders and vertex
 * array objects (VAOs) to render graphics. It provides methods for initializing
 * the rendering resources, updating the rendering logic, and destroying the
 * resources.
 */
class Renderer : public ComponentBase {
public:
  /**
   * @brief Initializes rendering resources.
   *
   * Sets up shaders and VAOs for rendering. This includes compiling shaders and
   * loading vertex data into VAOs. This method should be called before any
   * rendering operations are performed.
   *
   * @return STATUS indicating the success or failure of the initialization
   * process.
   */
  STATUS Initialize();

  /**
   * @brief Updates the rendering logic.
   *
   * Performs rendering operations using the initialized shaders and VAOs. This
   * method should be called in the application's main loop to render each
   * frame.
   *
   * @return STATUS indicating the success of the rendering update.
   */
  STATUS Update();

  /**
   * @brief Destroys rendering resources.
   *
   * Cleans up all resources associated with rendering, including shaders and
   * VAOs. This method should be called to properly release resources before the
   * application exits.
   *
   * @return STATUS indicating the success of the resource cleanup.
   */
  STATUS Destroy();

private:
  VertexArrayObject m_testVAO;
  Shader m_testShader;
};

#endif /* RENDERER_H */
