#include "renderer.hpp"

STATUS Renderer::Initialize() {
  const char *vertex_shader = "#version 400\n"
                              "in vec3 vp;"
                              "void main() {"
                              "  gl_Position = vec4(vp, 1.0);"
                              "}";

  const char *fragment_shader = "#version 400\n"
                                "out vec4 frag_colour;"
                                "void main() {"
                                "  frag_colour = vec4(0.5, 0.0, 0.5, 1.0);"
                                "}";

  m_testShader.Initialize();
  m_testShader.AddShader(GL_VERTEX_SHADER, vertex_shader);
  m_testShader.AddShader(GL_FRAGMENT_SHADER, fragment_shader);
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
