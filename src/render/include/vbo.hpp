#ifndef VBO_H
#define VBO_H

#include "types.hpp"

#include <GL/glew.h>
#include <spdlog/spdlog.h>

/**
 * @enum VERTEX_BUFFER_TYPES
 * @brief Enumerates the types of buffers a VertexBufferObject can manage.
 */
enum VERTEX_BUFFER_TYPES {
  VERTEX_BUFFER = 0, /**< Vertex buffer for storing vertex attributes. */
  INDEX_BUFFER = 1,  /**< Index buffer for storing vertex indices. */
  TEXTURE_COORDS_BUFFER = 2, /**< Texture coordinates buffer. */
  NORMAL_BUFFER = 3, /**< Normal vector buffer for lighting calculations. */

  FIRST = VERTEX_BUFFER, /**< Utility value to store the first enum entry. */
  LAST = NORMAL_BUFFER   /**< Utility value to store the last enum entry. */
};

/**
 * @class VertexBufferObject
 * @brief Manages OpenGL vertex buffer objects (VBOs).
 *
 * This class encapsulates functionality to create, bind, load data into,
 * and destroy OpenGL vertex buffer objects. It supports operations for
 * managing vertex data, including positions, texture coordinates, and normals.
 */
class VertexBufferObject {
public:
  /**
   * @brief Initializes the VBO by generating a new buffer object.
   *
   * This method creates a new OpenGL buffer and stores its ID for future
   * operations. Must be called before the VBO can be used.
   *
   * @return STATUS indicating the success of the operation.
   */
  STATUS Initialize();

  /**
   * @brief Destroys the VBO and frees its associated resources.
   *
   * Deletes the OpenGL buffer associated with this VBO.
   *
   * @return STATUS indicating the success of the operation.
   */
  STATUS Destroy();

  /**
   * @brief Binds the VBO to the current OpenGL context.
   *
   * Sets this VBO as the current buffer for subsequent OpenGL operations.
   */
  void Bind();

  /**
   * @brief Unbinds any VBO from the current OpenGL context.
   *
   * Unsets the current buffer for GL_ARRAY_BUFFER, effectively unbinding any
   * VBO.
   */
  void Unbind();

  /**
   * @brief Loads data into the VBO.
   *
   * Binds the VBO and loads the provided data into it. It also checks if the
   * data was loaded correctly by comparing the intended size with the actual
   * buffer size.
   *
   * @param  target   The target buffer type to bind to (e.g., GL_ARRAY_BUFFER).
   * @param  size     The size of the data to load into the buffer, in bytes.
   * @param  data     Pointer to the data to be loaded.
   * @param  usage    The expected usage pattern of the data (e.g.,
   *                  GL_STATIC_DRAW).
   *
   * @return STATUS   indicating the success of the data loading operation.
   */
  STATUS LoadBufferData(GLenum target, GLsizeiptr size, const void *data,
                        GLenum usage);

private:
  UINT32 m_ID; /**< OpenGL ID of the buffer object managed by this VBO. */
};

#endif /* VBO_H */
