#include "renderer.hpp"

STATUS Renderer::Initialize() {
  m_testShader.Initialize();
  m_testShader.AddShaderFromFile(GL_VERTEX_SHADER, "/home/thomas/Repos/extex/assets/shaders/vs.glsl");
  m_testShader.AddShaderFromFile(GL_FRAGMENT_SHADER, "/home/thomas/Repos/extex/assets/shaders/fs.glsl");
  m_testShader.CompileProgram();

  float vertices[] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f};
  m_testVAO.Initialize();
  m_testVAO.LoadVertexBufferData(sizeof(vertices), vertices);

  return SUCCESS;
}

STATUS Renderer::Update() {
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  m_testShader.Bind();
  m_testVAO.Bind();

  glDrawArrays(GL_TRIANGLES, 0, 3);

  m_testVAO.Unbind();
  m_testShader.Unbind();

  return SUCCESS;
}

STATUS Renderer::Destroy() {
  return SUCCESS;
}
