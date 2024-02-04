#ifndef VAO_H
#define VAO_H

#include "vbo.hpp"

#include <GL/glew.h>

/**
 * @class VertexArrayObject
 * @brief Manages OpenGL Vertex Array Objects (VAOs).
 *
 * Encapsulates functionality for creating, binding, loading data into,
 * and destroying OpenGL Vertex Array Objects. Supports managing multiple types
 * of vertex buffer data (positions, indices, texture coordinates, normals)
 * through associated Vertex Buffer Objects (VBOs).
 */
class VertexArrayObject {
public:
  /**
   * @brief Initializes the VAO by generating a new array object.
   *
   * Creates a new OpenGL vertex array object and stores its ID. This method
   * must be called before the VAO can be used.
   *
   * @return STATUS indicating the success of the operation.
   */
  STATUS Initialize();

  /**
   * @brief Destroys the VAO and frees its associated resources.
   *
   * Deletes the OpenGL vertex array object and any associated VBOs, releasing
   * all resources.
   *
   * @return STATUS indicating the success of the operation.
   */
  STATUS Destroy();

  /**
   * @brief Binds the VAO and its associated VBOs to the current OpenGL context.
   *
   * Sets this VAO as the current array object for OpenGL operations. It also
   * binds any VBOs that have been loaded with data to the VAO.
   */
  void Bind();

  /**
   * @brief Unbinds the VAO and its associated VBOs from the current OpenGL
   * context.
   *
   * Unsets the current array object and unbinds any associated VBOs from the
   * VAO.
   */
  void Unbind();

  /**
   * @brief Loads vertex data into a buffer and attaches it to the VAO.
   *
   * @param size The size of the vertex data to load, in bytes.
   * @param vertices Pointer to the vertex data.
   * @return STATUS indicating the success of the vertex data loading
   * operation.
   */
  STATUS LoadVertexBufferData(INT32 size, const void *vertices);

  /**
   * @brief Loads index data into a buffer and attaches it to the VAO.
   *
   * @param size The size of the index data to load, in bytes.
   * @param indices Pointer to the index data.
   * @return STATUS indicating the success of the index data loading operation.
   */
  STATUS LoadIndexBufferData(INT32 size, const void *indices);

  /**
   * @brief Loads texture coordinate data into a buffer and attaches it to the
   * VAO.
   *
   * @param size The size of the texture coordinate data to load, in bytes.
   * @param textCoords Pointer to the texture coordinate data.
   * @return STATUS indicating the success of the texture coordinate data
   * loading operation.
   */
  STATUS LoadTextCoordBufferData(INT32 size, const void *textCoords);

  /**
   * @brief Loads normal data into a buffer and attaches it to the VAO.
   *
   * @param size The size of the normal data to load, in bytes.
   * @param normals Pointer to the normal data.
   * @return STATUS indicating the success of the normal data loading operation.
   */
  STATUS LoadNormalBufferData(INT32 size, const void *normals);

private:
  /**
   * @brief Loads data into a specified type of VBO and attaches it to the VAO.
   *
   * Creates or reuses a VBO for the specified type, binds it, loads the given
   * data, and checks if the data was loaded correctly. On failure, logs an
   * error and cleans up resources.
   *
   * @param vboType The type of VBO to load data into.
   * @param target The target buffer type to bind to (e.g., GL_ARRAY_BUFFER).
   * @param dataSizeBytes The size of the data to load, in bytes.
   * @param data Pointer to the data to be loaded.
   * @return STATUS indicating the success of the data loading operation.
   */
  STATUS LoadBufferData(VERTEX_BUFFER_TYPES vboType, GLenum target,
                        INT32 dataSizeBytes, const void *data);

  UINT32 m_ID; ///< OpenGL ID of the vertex array object managed by this VAO.

  /**
   * @brief Array of pointers to VBOs for different types of vertex data.
   *
   * Manages VertexBufferObject instances for vertices, indices, texture
   * coordinates, and normals. Initialized to nullptr and populated upon loading
   * data.
   */
  VertexBufferObject *m_VBOs[VERTEX_BUFFER_TYPES::LAST + 1];
};

#endif /* VAO_H */
