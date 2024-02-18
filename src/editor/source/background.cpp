#include "background.hpp"

#include "spdlog/spdlog.h"

Background::Background() { m_initializedShader = false; }

Background::~Background() {}

STATUS Background::Initialize() {
  m_shader.Initialize();
  STATUS status = m_shader.CompileProgram();
  if (status != SUCCESS) {
    spdlog::error("Failed to initialize background shader.");
    return status;
  }

  status = m_vao.Initialize();
  if (status != SUCCESS) {
    spdlog::error("Failed to initialize background VAO.");
    return status;
  }

  return SUCCESS;
}

STATUS Background::Update() { return SUCCESS; }

STATUS Background::Destroy() {
  m_shader.Destroy();
  return SUCCESS;
}

RENDERER_TYPE Background::GetRendererID() const { return RENDERER_BACKGROUND; }

Shader &Background::GetShader() {
  if(!m_initializedShader) {
    m_shader.Initialize();
    m_initializedShader = true;
  }
  return m_shader;
}
