#include "application.hpp"
#include "spdlog/spdlog.h"
#include "types.hpp"

STATUS ExtexApplication::Start() {
  m_Window = new Window(1280, 720, "Extex");

  spdlog::info("test");
  m_Window->Initialize();

  while(m_Window->IsWindowOpen()) {
    m_Window->Update();
  }

  m_Window->Destroy();

  return SUCCESS;
}
