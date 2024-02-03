#ifndef RENDERER_H
#define RENDERER_H

#include "component.hpp"
#include "vao.hpp"
#include "shader.hpp"

class Renderer : public ComponentBase {
public:
  STATUS Initialize();
  STATUS Update();
  STATUS Destroy();

private:
  VertexArrayObject m_testVAO;
  VertexBufferObject m_testVBO;
  Shader m_testShader;
};

#endif /* RENDERER_H */
