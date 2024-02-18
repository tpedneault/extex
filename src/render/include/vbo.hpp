/***************************************************************************************************/
/*                                                                                                 */
/*                       $$$$$$$$\ $$\   $$\ $$$$$$$$\ $$$$$$$$\ $$\   $$\                         */
/*                       $$  _____|$$ |  $$ |\__$$  __|$$  _____|$$ |  $$ |                        */
/*                       $$ |      $$\ $$  |   $$ |   $$ |      $$\ $$  |                          */
/*                       $$$$$\     $$$$  /    $$ |   $$$$$\     $$$$  /                           */
/*                       $$  __|    $$  $$<     $$ |   $$  __|    $$  $$<                          */
/*                       $$ |      $$  /$$\    $$ |   $$ |      $$  /$$\                           */
/*                       $$$$$$$$\ $$ /  $$ |   $$ |   $$$$$$$$\ $$ /  $$ |                        */
/*                       \________|\__|  \__|   \__|   \________|\__|  \__|                        */
/*                                                                                                 */
/***************************************************************************************************/
/* FILE NAME  : vbo.hpp                                                                            */
/* DESCRIPTION: Implementation of OpenGL VBO (Vertex Buffer Object)                                */
/* AUTHOR     : Thomas Pedneault                                                                   */
/* DATE       : 2024-02-18                                                                         */
/***************************************************************************************************/

#ifndef VBO_H
#define VBO_H

#include "types.hpp"

#include <GL/glew.h>

/**
 * @enum VERTEX_BUFFER_TYPES
 * @brief Enumerates the types of buffers a VertexBufferObject can manage.
 */
enum VERTEX_BUFFER_TYPES {
  VERTEX_BUFFER = 0,            ///< Vertex buffer for storing vertex attributes.
  INDEX_BUFFER = 1,             ///< Index buffer for storing vertex indices.
  TEXTURE_COORDS_BUFFER = 2,    ///< Texture coordinates buffer.
  NORMAL_BUFFER = 3,            ///< Normal vector buffer for lighting calculations.

  FIRST = VERTEX_BUFFER,        ///< Utility value to store the first enum entry.
  LAST = NORMAL_BUFFER          ///< Utility value to store the last enum entry.
};

/**
 * @enum VERTEX_ATTRIB_LOCATION
 * @brief Defines standard locations for vertex attributes.
 *
 * This enumeration specifies standard locations for various types of vertex
 * attributes in a shader program. By standardizing the locations of common
 * attributes, it helps ensure consistency across different shaders and
 * simplifies the binding of vertex buffer data to shader inputs.
 */
enum VERTEX_ATTRIB_LOCATION {
    POSITIONS = 0,  ///< Location 0 is reserved for vertex positions.
    NORMALS = 1,    ///< Location 1 is reserved for vertex normals.
    TEX_COORDS = 2  ///< Location 2 is reserved for texture coordinates.
};

/**
 * @struct VertexAttributeData
 * @brief Holds data required to specify an attribute in a vertex buffer.
 *
 * This struct is designed to encapsulate the parameters needed by the
 * glVertexAttribPointer function, making it easier to manage vertex attribute
 * data within OpenGL applications. It provides a structured way to pass data
 * to shaders.
 */
struct VertexAttributeData {
  INT32 index;            ///< Index of the vertex attribute (use VERTEX_ATTRIB_LOCATION).
  INT32 size;             ///< Number of components per vertex attribute. Must be 1, 2, 3,
                          ///< or 4.
  GLenum type;            ///< Data type of each component in the attribute
                          ///< (e.g., GL_FLOAT).
  GLboolean normalized;   ///< Whether fixed-point data values should be
                          ///< normalized (GL_TRUE) or converted directly as
                          ///< fixed-point values (GL_FALSE).
  INT32 stride;           ///< Byte offset between consecutive vertex attributes. If 0,
                          ///< attributes are tightly packed.
  const void *pointer;    ///< Offset of the first component of the first attribute
                          ///< in the buffer. In OpenGL ES, this is a byte offset
                          ///< into the buffer object's data store.

  /**
   * Constructor to initialize the struct with default values.
   *
   * @param index The index of the vertex attribute.
   * @param size Number of components per attribute.
   * @param type The data type of each component in the attribute.
   * @param normalized Whether to normalize the data.
   * @param stride Byte offset between consecutive attributes.
   * @param pointer Offset to the first component of the first attribute.
   */
  VertexAttributeData(INT32 index = 0, INT32 size = 3, GLenum type = GL_FLOAT,
                      GLboolean normalized = GL_FALSE, INT32 stride = 0,
                      const void *pointer = nullptr)
      : index(index), size(size), type(type), normalized(normalized),
        stride(stride), pointer(pointer) {}
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
  UINT32 m_ID; ///< OpenGL ID of the buffer object managed by this VBO.
};

#endif /* VBO_H */
