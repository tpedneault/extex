#include "vbo.hpp"

#include <spdlog/spdlog.h>

STATUS VertexBufferObject::Initialize() {
  glGenBuffers(1, &m_ID);
  return SUCCESS;
}

STATUS VertexBufferObject::Destroy() {
  return SUCCESS;
}

void VertexBufferObject::Bind() {
  glBindBuffer(GL_ARRAY_BUFFER, m_ID);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
}

void VertexBufferObject::Unbind() {
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

STATUS VertexBufferObject::LoadBufferData(GLenum target, GLsizeiptr dataSize,
                                          const void *data, GLenum usage) {
  Bind();

  glBufferData(target, dataSize, 0, usage);
  glBufferSubData(target, 0, dataSize, data);

  INT32 bufferSize = 0;
  glGetBufferParameteriv(target, GL_BUFFER_SIZE, &bufferSize);

  Unbind();

  if (dataSize != bufferSize) {
    glDeleteBuffers(1, &m_ID);
    spdlog::error("Failed to load VBO buffer data.");
    return FAILURE;
  }

  return SUCCESS;
}
