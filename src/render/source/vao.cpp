#include "vao.hpp"
#include "vbo.hpp"

STATUS VertexArrayObject::Initialize() {
  glGenVertexArrays(1, &m_ID);
  return SUCCESS;
}

STATUS VertexArrayObject::Destroy() {
  glDeleteVertexArrays(1, &m_ID);
  return SUCCESS;
}

void VertexArrayObject::Bind() {
  glBindVertexArray(m_ID);
  for(INT32 i = VERTEX_BUFFER_TYPES::FIRST; i < VERTEX_BUFFER_TYPES::LAST; i++) {
    if(m_VBOs[i] != nullptr) {
      glEnableVertexAttribArray(i);
      m_VBOs[i]->Bind();
    }
  }
}

void VertexArrayObject::Unbind() {
  for(INT32 i = VERTEX_BUFFER_TYPES::FIRST; i < VERTEX_BUFFER_TYPES::LAST; i++) {
    if(m_VBOs[i] != nullptr) {
      m_VBOs[i]->Unbind();
    }
  }
  glBindVertexArray(0);
}

STATUS VertexArrayObject::LoadVertexBufferData(INT32 size, const void* vertices) {
  return LoadBufferData(VERTEX_BUFFER, GL_ARRAY_BUFFER, size, vertices);
}

STATUS VertexArrayObject::LoadIndexBufferData(INT32 size, const void* indices) {
  return LoadBufferData(INDEX_BUFFER, GL_ELEMENT_ARRAY_BUFFER, size, indices);
}

STATUS VertexArrayObject::LoadTextCoordBufferData(INT32 size, const void* textCoords) {
  return LoadBufferData(TEXTURE_COORDS_BUFFER, GL_ARRAY_BUFFER, size, textCoords);
}

STATUS VertexArrayObject::LoadNormalBufferData(INT32 size,
                                               const void *normals) {
  return LoadBufferData(NORMAL_BUFFER, GL_ARRAY_BUFFER, size, normals);
}

STATUS VertexArrayObject::LoadBufferData(VERTEX_BUFFER_TYPES vboType,
                                         GLenum target, INT32 dataSizeBytes,
                                         const void *data) {
  STATUS status = SUCCESS;

  if (m_VBOs[vboType] != nullptr) {
    m_VBOs[vboType]->Destroy();
  }

  m_VBOs[vboType] = new VertexBufferObject();
  m_VBOs[vboType]->Initialize();
  m_VBOs[vboType]->Bind();

  glBufferData(target, dataSizeBytes, 0, GL_STATIC_DRAW);
  glBufferSubData(target, 0, dataSizeBytes, data);

  INT32 bufferSize = 0;
  glGetBufferParameteriv(target, GL_BUFFER_SIZE, &bufferSize);

  m_VBOs[vboType]->Unbind();

  if(dataSizeBytes != bufferSize) {
    m_VBOs[vboType]->Destroy();
    spdlog::error("Failed to load buffer data.");
    status = FAILURE;
  }

  return status;
}
