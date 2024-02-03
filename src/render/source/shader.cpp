#include "shader.hpp"

Shader::Shader() {
  m_isCompiled = false;
}

STATUS Shader::Initialize() {
  m_ID = glCreateProgram();
  return SUCCESS;
}

STATUS Shader::Destroy() {
  glDeleteProgram(m_ID);
  return SUCCESS;
}

void Shader::Bind() {
  glUseProgram(m_ID);
}

void Shader::Unbind() {
  glUseProgram(0);
}

STATUS Shader::AddShader(GLenum type, CSTR source) {
  STATUS status = SUCCESS;
  UINT32 shaderID;
  INT32 compileStatus;

  shaderID = glCreateShader(type);
  glShaderSource(shaderID, 1, &source, NULL);
  glCompileShader(shaderID);

  glGetShaderiv(shaderID, GL_COMPILE_STATUS, &compileStatus);
  if (compileStatus != GL_TRUE) {
    INT32 logLength = 0;
    char message[1024];

    glGetShaderInfoLog(shaderID, 1024, &logLength, message);
    spdlog::error("Failed to compile shader. Message: %s", message);
    status = FAILURE;
  }
  else {
    glAttachShader(m_ID, shaderID);
  }

  return status;
}

STATUS Shader::CompileProgram() {
  STATUS status = SUCCESS;
  INT32 linkStatus;

  glLinkProgram(m_ID);
  glGetProgramiv(m_ID, GL_LINK_STATUS, &linkStatus);
  if(linkStatus != GL_TRUE) {
    INT32 logLength = 0;
    char message[1024];

    glGetProgramInfoLog(m_ID, 1024, &logLength, message);
    spdlog::error("Failed to link shader program. Message: %s", message);
    status = FAILURE;
  }

  return status;
}
