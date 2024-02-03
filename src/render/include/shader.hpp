#ifndef SHADER_H
#define SHADER_H

#include "types.hpp"

#include <GL/glew.h>
#include <spdlog/spdlog.h>

class Shader {
public:
  Shader();

  STATUS Initialize();
  STATUS Destroy();

  void Bind();
  void Unbind();

  STATUS AddShader(GLenum type, CSTR source);
  STATUS CompileProgram();
private:
  UINT32 m_ID;
  bool m_isCompiled;
};

#endif /* SHADER_H */
