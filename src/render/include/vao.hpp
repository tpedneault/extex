#ifndef VAO_H
#define VAO_H

#include "vbo.hpp"

#include <GL/glew.h>

class VertexArrayObject {
public:
  STATUS Initialize();
  STATUS Destroy();

  void Bind();
  void Unbind();

  STATUS LoadVertexBufferData(INT32 size, const void *vertices);
  STATUS LoadIndexBufferData(INT32 size, const void *indices);
  STATUS LoadTextCoordBufferData(INT32 size, const void *textCoords);
  STATUS LoadNormalBufferData(INT32 size, const void *normals);

private:
  UINT32 m_ID;
  VertexBufferObject *m_VBOs[VERTEX_BUFFER_TYPES::LAST + 1];

  STATUS LoadBufferData(VERTEX_BUFFER_TYPES vboType, GLenum target, INT32 dataSizeBytes, const void* data);
};

#endif /* VAO_H */
