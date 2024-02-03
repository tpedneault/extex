#include "application.hpp"
#include "spdlog/spdlog.h"
#include "types.hpp"

#define INITIALIZE_COMPONENT(component, errorMessage)                          \
  do {                                                                         \
    m_lastStatus = (component)->Initialize();                                  \
    if (m_lastStatus != SUCCESS) {                                             \
      spdlog::error(errorMessage);                                             \
      return m_lastStatus;                                                     \
    }                                                                          \
  } while (0)

STATUS ExtexApplication::Start() {
  m_Window = new Window(1280, 720, "Extex");
  m_Renderer = new Renderer();

  INITIALIZE_COMPONENT(m_Window, "Failed to initialize Window.");
  INITIALIZE_COMPONENT(m_Renderer, "Failed to initialize Renderer.");

  while(m_Window->IsWindowOpen()) {
    m_Window->Update();
    m_Renderer->Update();
  }

  m_Renderer->Destroy();
  m_Window->Destroy();

  return SUCCESS;
}
