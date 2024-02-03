#ifndef VBO_H
#define VBO_H

#include "types.hpp"

#include <GL/glew.h>
#include <spdlog/spdlog.h>

enum VERTEX_BUFFER_TYPES {
  VERTEX_BUFFER = 0,
  INDEX_BUFFER = 1,
  TEXTURE_COORDS_BUFFER = 2,
  NORMAL_BUFFER = 3,

  // Store the first and entries in the enum.
  FIRST = VERTEX_BUFFER,
  LAST  = NORMAL_BUFFER
};

class VertexBufferObject {
public:
  STATUS Initialize();
  STATUS Destroy();

  void Bind();
  void Unbind();

  STATUS LoadBufferData(GLenum target, GLsizeiptr size, const void *data, GLenum usage);

private:
  UINT32 m_ID;
};

#endif /* VBO_H */
